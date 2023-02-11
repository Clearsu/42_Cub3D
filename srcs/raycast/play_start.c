/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:54:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/11 22:05:35 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "raycast.h"
#include "define.h"

static void	set_dir_vector(t_player_data *pdata, char c)
{
	if (c == 'E')
	{
		pdata->dir_x = 1;
		pdata->dir_y = 0;
	}
	else if (c == 'W')
	{
		pdata->dir_x = -1;
		pdata->dir_y = 0;
	}
	else if (c == 'S')
	{
		pdata->dir_x = 0;
		pdata->dir_y = 1;
	}
	else if (c == 'N')
	{
		pdata->dir_x = 0;
		pdata->dir_y = -1;
	}
}

static void	init_player_data(t_player_data *pdata, t_map_data *map_data)
{
	ft_memset(pdata, 0, sizeof(t_player_data));
	pdata->pos_x = map_data->spawn[SPAWN_X];
	pdata->pos_y = map_data->spawn[SPAWN_Y];
	set_dir_vector(pdata, map_data->spawn[SPAWN_D]);
	pdata->plane_x = (-1) * pdata->dir_y * 0.66;
	pdata->plane_y = pdata->dir_x * 0.66;
}

void	play_start(t_map_data *map_data, t_mlx_vars *mlx_vars)
{
	t_loop_hook_param	loop_hook_param;
	t_player_data		pdata;

	init_player_data(&pdata, map_data);
	loop_hook_param.pdata = &pdata;
	loop_hook_param.map_data = map_data;
	init_mlx_and_img(mlx_vars);
	mlx_key_hook(mlx_vars->win, key_hook_handler, mlx_vars);
	mlx_loop_hook(mlx_vars->mlx, raycast, &loop_hook_param);
	mlx_loop(mlx_vars->mlx);
}
