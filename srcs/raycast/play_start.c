/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:54:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/14 17:10:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "raycast.h"
#include "define.h"

static void	set_dir_vector(t_ray_data *rdata, char c)
{
	if (c == 'E')
	{
		rdata->dir_x = 1;
		rdata->dir_y = 0;
	}
	else if (c == 'W')
	{
		rdata->dir_x = -1;
		rdata->dir_y = 0;
	}
	else if (c == 'S')
	{
		rdata->dir_x = 0;
		rdata->dir_y = 1;
	}
	else if (c == 'N')
	{
		rdata->dir_x = 0;
		rdata->dir_y = -1;
	}
}

static void	init_ray_data(t_ray_data *rdata, t_map_data *map_data)
{
	ft_memset(rdata, 0, sizeof(t_ray_data));
	rdata->pos_x = map_data->spawn[SPAWN_X];
	rdata->pos_y = map_data->spawn[SPAWN_Y];
	set_dir_vector(rdata, map_data->spawn[SPAWN_D]);
	rdata->plane_x = (-1) * rdata->dir_y * 0.66;
	rdata->plane_y = rdata->dir_x * 0.66;
}

void	play_start(t_map_data *map_data, t_mlx_vars *mlx_vars)
{
	t_raycast_param	raycast_param;
	t_ray_data	rdata;

	init_ray_data(&rdata, map_data);
	raycast_param.rdata = &rdata;
	raycast_param.map_data = map_data;
	raycast_param.mlx_vars = mlx_vars;
	init_mlx_and_img(mlx_vars);
	mlx_key_hook(mlx_vars->win, key_hook_handler, &raycast_param);
	mlx_loop_hook(mlx_vars->mlx, raycast, &raycast_param);
	mlx_loop(mlx_vars->mlx);
}
