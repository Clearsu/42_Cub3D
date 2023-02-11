/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:43:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/11 23:10:51 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	d_abs(double n)
{
	if (n >= 0)
		return (n);
	return (n * (-1));
}

void	raycast(t_raycast_param *raycast_param)
{
	static t_player_data	*pdata = raycast_param->pdata;
	static t_map_data		*map_data = raycast_param->map_data;
	size_t					x;

	x = 0;
	while (x < map_data->width)
	{
		pdata->camera_x = 2 * x / (double)map_data->width - 1;
		pdata->ray_dir_x = pdata->dir_x + pdata->plane_x * camera_x;
		pdata->ray_dir_y = pdata->dir_y + pdata->plane_y * camera_x;

		pdata->map_x = (int)pdata->pos_x;
		pdata->map_y = (int)pdata->pos_y;

		if (pdata->ray_dir_x == 0)
			pdata->delta_dist_x = 1e30;
		else
			pdata->delta_dist_x = d_abs(1 / pdata->ray_dir_x);
		if (pdata->ray_dir_y == 0)
			pdata->delta_dist_y = 1e30;
		else
			pdata->delta_dist_y = d_abs(1 / pdata->ray_dir_y);

		if (pdata->ray_dir_x < 0)
		{
			pdata->step_x = -1;
			pdata->side_dist_x = (pdata->pos_x - pdata->map_x) * pdata->delta_dist_x;
		}
		else
		{
			pdata->step_x = 1;
			pdata->side_dist_x = (pdata->map_x + 1.0 - pdata->pos_x) * pdata->delta_dist_x;
		}
		if (pdata->ray_dir_y < 0)
		{
			pdata->step_y = -1;
			pdata->side_dist_y = (pdata->pos_y - pdata->map_y) * pdata->delta_dist_y;
		}
		else
		{
			pdata->step_y = 1;
			pdata->side_dist_y = (pdata->map_y + 1.0 - pdata->pos_y) * pdata->delta_dist_y;
		}

		while (pdata->hit == 0)
		{
			if (pdata->side_dist_x < pdata->side_dist_y)
			{
				pdata->side_dist_x += pdata->delta_dist_x;
				pdata->map_x += pdata->step_x;
				pdata->side = 0;
			}
			else
			{
				pdata->side_dist_y += pdata->delta_dist_y;
				pdata->map_y += pdata->step_y;
				pdata->side = 1;
			}
			if (map_data->map[pdata->map_y][pdata->map_x] == WALL)
				pdata->hit = 1;
		}

		if (pdata->side == 0)
			pdata->perp_wall_dist = pdata->side_dist_x - pdata->delta_dist_x;
		else
			pdata->perp_wall_dist = pdata->side_dist_y - pdata->delta_dist_y;

		int	line_height = (int)(map_data->height / pdata->perp_wall_dist);
		int draw_start = (-1) * line_height / 2 + map_data->height / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + map_data->height / 2;
		if (draw_end >= map_data->height)
			draw_end = map_data->height - 1;
	}
}
