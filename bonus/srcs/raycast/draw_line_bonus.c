/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:50:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/28 22:32:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_bonus.h"

void	get_draw_start_end(t_ray_data *rdata)
{
	rdata->line_height = (int)(HEIGHT / rdata->perp_wall_dist);
	if (rdata->line_height < 0)
		rdata->line_height = 23999;
	rdata->draw_start = HEIGHT / 2 - rdata->line_height / 2;
	if (rdata->draw_start < 0)
		rdata->draw_start = 0;
	rdata->draw_end = HEIGHT / 2 + rdata->line_height / 2;
	if (rdata->draw_end >= HEIGHT)
		rdata->draw_end = HEIGHT - 1;
}

void	get_wall_texture(t_ray_data *rdata)
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

static int	get_tex_x(t_ray_data *rdata, int tex_width)
{
	double	wall_x;
	int		tex_x;

	if (rdata->side == 0)
		wall_x = rdata->pos_y + rdata->perp_wall_dist * rdata->ray_dir_y;
	else
		wall_x = rdata->pos_x + rdata->perp_wall_dist * rdata->ray_dir_x;
	wall_x = wall_x - (int)wall_x;
	tex_x = (int)(wall_x * (double)(tex_width));
	if ((rdata->side == 0 && rdata->ray_dir_x > 0) \
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
	rdata->tex_pos = (rdata->draw_start - HEIGHT / 2 + rdata->line_height / 2) \
					* rdata->tex_step;
	texture = raycast_param->tex_data[rdata->tex_idx].texture;
	while (++y < rdata->draw_end)
	{
		rdata->tex_y = (int)rdata->tex_pos;
		rdata->tex_pos += rdata->tex_step;
		color = texture[tex_width * rdata->tex_y + rdata->tex_x];
		my_mlx_pixel_put(img_data, x, y, color);
	}
}

void	draw_line(t_raycast_param *raycast_param, t_img_data *img_data,
		unsigned int *color, int x)
{
	int				y;
	int				start;

	y = -1;
	start = raycast_param->rdata->draw_start;
	while (++y < start)
		my_mlx_pixel_put(img_data, x, y, color[CEILING]);
	draw_texture_line(img_data, x, y - 1, raycast_param);
	y = raycast_param->rdata->draw_end - 1;
	while (++y < HEIGHT)
		my_mlx_pixel_put(img_data, x, y, color[FLOOR]);
}
