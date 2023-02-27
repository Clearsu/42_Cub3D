/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:43:14 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 18:30:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "define.h"
#include "mlx.h"

static void	dda(t_ray_data *rdata, t_map_data *map_data)
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

static void	get_perp_wall_dist(t_ray_data *rdata)
{
	if (rdata->side == 0)
		rdata->perp_wall_dist = (rdata->map_x + (1 - rdata->step_x)
				/ 2 - rdata->pos_x) / rdata->ray_dir_x;
	else
		rdata->perp_wall_dist = (rdata->map_y + (1 - rdata->step_y)
				/ 2 - rdata->pos_y) / rdata->ray_dir_y;
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
	x = -1;
	while (++x < WIDTH)
	{
		rdata->hit = 0;
		get_camerax_and_ray_dir(rdata, x);
		get_map_x_y(rdata);
		get_delta_dist(rdata);
		get_step_and_initial_sidedist(rdata);
		dda(rdata, map_data);
		get_perp_wall_dist(rdata);
		get_draw_start_end(rdata);
		get_wall_texture(rdata);
		draw_line(raycast_param, &mlx_vars->img_data, map_data->color, x);
	}
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, \
			mlx_vars->img_data.img, 0, 0);
	return (0);
}
