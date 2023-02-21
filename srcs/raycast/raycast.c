/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:43:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/21 18:03:44 by jincpark         ###   ########.fr       */
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
	int	line_height;

	line_height = (int)(HEIGHT / rdata->perp_wall_dist);
	rdata->draw_start = HEIGHT / 2 - line_height / 2;
	if (rdata->draw_start < 0)
		rdata->draw_start = 0;
	rdata->draw_end = HEIGHT / 2 + line_height / 2;
	if (rdata->draw_end >= HEIGHT)
		rdata->draw_end = HEIGHT - 1;
}

static void	get_wall_color(t_ray_data *rdata, t_map_data *map_data)
{
	char	**map;
	int		map_x;
	int		map_y;

	map = map_data->map;
	map_x = rdata->map_x;
	map_y = rdata->map_y;
	if (rdata->side == 1)
	{
		if ((int)rdata->pos_y < map_y)
			rdata->color = SOUTH_COLOR;
		else
			rdata->color = NORTH_COLOR;
	}
	else
	{
		if ((int)rdata->pos_x < map_x)
			rdata->color = EAST_COLOR;
		else
			rdata->color = WEST_COLOR;
	}
}

static void	draw_vertical_line(size_t x, t_ray_data *rdata, t_map_data *map_data, t_mlx_vars *mlx_vars)
{
	int	y;
	int	start;
	int	end;

	y = 0;
	start = rdata->draw_start;
	end = rdata->draw_end;
	while (y < start)
		my_mlx_pixel_put(&mlx_vars->img_data, x, y++, map_data->color[CEILING]);
	while (y < end)
		my_mlx_pixel_put(&mlx_vars->img_data, x, y++, rdata->color);
	while (y < HEIGHT)
		my_mlx_pixel_put(&mlx_vars->img_data, x, y++, map_data->color[FLOOR]);
}

int	raycast(t_raycast_param *raycast_param)
{
	t_ray_data	*rdata;
	t_map_data	*map_data;
	t_mlx_vars	*mlx_vars;
	size_t		x;

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
		get_wall_color(rdata, map_data);
		draw_vertical_line(x++, rdata, map_data, mlx_vars);
	}
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, mlx_vars->img_data.img, 0, 0);
	return (0);
}
