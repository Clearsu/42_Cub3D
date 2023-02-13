/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/13 22:48:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "mlx.h"

void	close_win_and_exit(t_mlx_vars *mlx_vars)
{
	mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
	exit(0);
}

int	key_hook_handler(int keycode, t_raycast_param *raycast_param)
{
	if (keycode == ESC)
		close_win_and_exit(raycast_param->mlx_vars);
	else if (keycode == LEFT)
		move_left(raycast_param);
	else if (keycode == RIGHT)
		move_right(raycast_param);
	else if (keycode == UP)
		move_forward(raycast_param);
	else if (keycode == DOWN)
		move_backward(raycast_param);
	return (0);
}
