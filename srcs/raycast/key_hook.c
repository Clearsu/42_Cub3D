/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/14 21:28:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "mlx.h"

void	close_win_and_exit(t_mlx_vars *mlx_vars)
{
	mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
	exit(0);
}

#include <stdio.h>
int	key_hook_handler(int keycode, t_raycast_param *raycast_param)
{
	if (keycode == ESC)
		close_win_and_exit(raycast_param->mlx_vars);
	else if (keycode == LEFT)
		move_left(raycast_param->rdata, raycast_param->map_data->map);
	else if (keycode == RIGHT)
		move_right(raycast_param->rdata, raycast_param->map_data->map);
	else if (keycode == UP)
		move_forward(raycast_param->rdata, raycast_param->map_data->map);
	else if (keycode == DOWN)
		move_backward(raycast_param->rdata, raycast_param->map_data->map);
	else if (keycode == R_RIGHT)
		rotate_right(raycast_param->rdata);
	else if (keycode == R_LEFT)
		rotate_right(raycast_param->rdata);
	return (0);
}
