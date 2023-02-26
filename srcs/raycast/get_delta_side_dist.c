/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_delta_side_dist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:01:49 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/26 17:07:27 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "define.h"

static double	d_abs(double n)
{
	if (n >= 0)
		return (n);
	return (n * (-1));
}

void	get_camerax_and_ray_dir(t_ray_data *rdata, size_t x)
{
	rdata->camera_x = 2 * x / (double)WIDTH - 1;
	rdata->ray_dir_x = rdata->dir_x + rdata->plane_x * rdata->camera_x;
	rdata->ray_dir_y = rdata->dir_y + rdata->plane_y * rdata->camera_x;
}

void	get_map_x_y(t_ray_data *rdata)
{
	rdata->map_x = (int)rdata->pos_x;
	rdata->map_y = (int)rdata->pos_y;
}

void	get_delta_dist(t_ray_data *rdata)
{
	if (rdata->ray_dir_x == 0)
		rdata->delta_dist_x = 1.7e308;
	else
		rdata->delta_dist_x = d_abs(1 / rdata->ray_dir_x);
	if (rdata->ray_dir_y == 0)
		rdata->delta_dist_y = 1.7e308;
	else
		rdata->delta_dist_y = d_abs(1 / rdata->ray_dir_y);
}

void	get_step_and_initial_sidedist(t_ray_data *rdata)
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
