/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:43:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/24 15:51:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "raycast.h"
#include "define.h"
#include "mlx.h"

double	d_abs(double n)
{
	if (n >= 0)
		return (n);
	return (n * (-1));
}

static void	get_camerax_and_ray_dir(t_ray_data *rdata,
		t_map_data *map_data, size_t x)
{
	rdata->camera_x = 2 * x / (double)WIDTH - 1;
	rdata->ray_dir_x = rdata->dir_x + rdata->plane_x * rdata->camera_x;
	rdata->ray_dir_y = rdata->dir_y + rdata->plane_y * rdata->camera_x;
}

static void	get_map_x_y(t_ray_data *rdata)
{
	rdata->map_x = (int)rdata->pos_x;
	rdata->map_y = (int)rdata->pos_y;
}

static void	get_delta_dist(t_ray_data *rdata)
{
	if (rdata->ray_dir_x == 0)
		rdata->delta_dist_x = 1e30;
	else
		rdata->delta_dist_x = d_abs(1 / rdata->ray_dir_x);
	if (rdata->ray_dir_y == 0)
		rdata->delta_dist_y = 1e30;
	else
		rdata->delta_dist_y = d_abs(1 / rdata->ray_dir_y);
}

static void	get_step_and_initial_sidedist(t_ray_data *rdata)
{
	if (rdata->ray_dir_x < 0)
	{
		rdata->step_x = -1;
		rdata->side_dist_x = (rdata->pos_x - rdata->map_x) \
							* rdata->delta_dist_x;
	}
	else
	{
		rdata->step_x = 1;
		rdata->side_dist_x = (rdata->map_x + 1.0 - rdata->pos_x) \
							* rdata->delta_dist_x;
	}
	if (rdata->ray_dir_y < 0)
	{
		rdata->step_y = -1;
		rdata->side_dist_y = (rdata->pos_y - rdata->map_y) \
							* rdata->delta_dist_y;
	}
	else
	{
		rdata->step_y = 1;
		rdata->side_dist_y = (rdata->map_y + 1.0 - rdata->pos_y) \
							* rdata->delta_dist_y;
	}
}

static void	perform_dda(t_ray_data *rdata, t_map_data *map_data)
{
	while (rdata->hit == 0)
	{
		if (rdata->side_dist_x < rdata->side_dist_y)
		{
			rdata->side_dist_x += rdata->delta_dist_x;
			rdata->map_x += rdata->step_x;
			rdata->side = 0;
		}
		else
		{
			rdata->side_dist_y += rdata->delta_dist_y;
			rdata->map_y += rdata->step_y;
			rdata->side = 1;
		}
		if (map_data->map[rdata->map_y][rdata->map_x] == WALL)
			rdata->hit = 1;
	}
}

static void	get_dist_of_perp_ray(t_ray_data *rdata)
{
	if (rdata->side == 0)
		rdata->perp_wall_dist = rdata->side_dist_x - rdata->delta_dist_x;
	else
		rdata->perp_wall_dist = rdata->side_dist_y - rdata->delta_dist_y;
}

static void	get_draw_start_end(t_ray_data *rdata, t_map_data *map_data)
{
	rdata->line_height = (int)(HEIGHT / rdata->perp_wall_dist);
	rdata->draw_start = HEIGHT / 2 - rdata->line_height / 2;
	if (rdata->draw_start < 0)
		rdata->draw_start = 0;
	rdata->draw_end = HEIGHT / 2 + rdata->line_height / 2;
	if (rdata->draw_end >= HEIGHT)
		rdata->draw_end = HEIGHT - 1;
}

static void	get_wall_texture(t_ray_data *rdata, t_map_data *map_data)
{
	if (rdata->side == 1)
	{
		if ((int)rdata->pos_y < rdata->map_y)
			rdata->tex_idx = SOUTH;
		else
			rdata->tex_idx = NORTH;
	}
	else
	{
		if ((int)rdata->pos_x < rdata->map_x)
			rdata->tex_idx = EAST;
		else
			rdata->tex_idx = WEST;
	}
}

static int get_tex_x(t_ray_data *rdata, int tex_width)
{
	double	wall_x;
	int		tex_x;

	if (rdata->side == 0)
		wall_x = rdata->pos_y + rdata->perp_wall_dist * rdata->ray_dir_y;
	else
		wall_x = rdata->pos_x + rdata->perp_wall_dist * rdata->ray_dir_x;
	wall_x = wall_x - (int)wall_x;
	tex_x = (int)(wall_x * (double)(tex_width));
	if ((rdata->side == 0 && rdata->ray_dir_x > 0)
			|| (rdata->side == 1 && rdata->ray_dir_y < 0))
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

static void	draw_texture_line(t_img_data *img_data,
		int x, int y, t_raycast_param *raycast_param)
{
	t_ray_data		*rdata;
	unsigned int	*texture;
	int				tex_width;
	int				tex_height;
	unsigned int	color;

	rdata = raycast_param->rdata;
	tex_width = raycast_param->tex_data[raycast_param->rdata->tex_idx].width;
	tex_height = raycast_param->tex_data[raycast_param->rdata->tex_idx].height;
	rdata->tex_x = get_tex_x(rdata, tex_width);
	rdata->tex_step = 1.0 * tex_height / rdata->line_height;
    rdata->tex_pos = (rdata->draw_start - HEIGHT / 2 + rdata->line_height / 2)
		* rdata->tex_step;
	texture = raycast_param->tex_data[rdata->tex_idx].texture;
	while (y < rdata->draw_end)
	{
		rdata->tex_y = (int)rdata->tex_pos;
		rdata->tex_pos += rdata->tex_step;
		color = texture[tex_width * rdata->tex_y + rdata->tex_x];
		my_mlx_pixel_put(img_data, x, y++, color);
	}
}

static void	draw_line(t_raycast_param *raycast_param, t_img_data *img_data,
		unsigned int *color, int x)
{
	int				y;
	int				start;
	unsigned int	tex_color;
	

	y = 0;
	start = raycast_param->rdata->draw_start;
	while (y < start)
		my_mlx_pixel_put(img_data, x, y++, color[CEILING]);
	draw_texture_line(img_data, x, y, raycast_param);
	y = raycast_param->rdata->draw_end;
	while (y < HEIGHT)
		my_mlx_pixel_put(img_data, x, y++, color[FLOOR]);
}

int	raycast(t_raycast_param *raycast_param)
{
	t_ray_data	*rdata;
	t_map_data	*map_data;
	t_mlx_vars	*mlx_vars;
	int			x;

	rdata = raycast_param->rdata;
	map_data = raycast_param->map_data;
	mlx_vars = raycast_param->mlx_vars;
	x = 0;
	while (x < WIDTH)
	{
		rdata->hit = 0;
		get_camerax_and_ray_dir(rdata, map_data, x);
		get_map_x_y(rdata);
		get_delta_dist(rdata);
		get_step_and_initial_sidedist(rdata);
		perform_dda(rdata, map_data);
		get_dist_of_perp_ray(rdata);
		get_draw_start_end(rdata, map_data);
		get_wall_texture(rdata, map_data);
		draw_line(raycast_param, &mlx_vars->img_data, map_data->color, x++);
	}
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, mlx_vars->img_data.img, 0, 0);
	return (0);
}
