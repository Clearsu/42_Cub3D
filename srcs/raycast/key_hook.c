/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/18 23:20:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "mlx.h"

void	close_win_and_exit(t_mlx_vars *mlx_vars)
{
	mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
	exit(0);
}

int	press_key(int keycode, t_raycast_param *raycast_param)
{
	if (keycode == ESC)
		close_win_and_exit(raycast_param->mlx_vars);
	else if (keycode == LEFT)
		raycast_param->move_left = TRUE;
	else if (keycode == RIGHT)
		raycast_param->move_right = TRUE;
	else if (keycode == UP)
		raycast_param->move_forward = TRUE;
	else if (keycode == DOWN)
		raycast_param->move_backward = TRUE;
	else if (keycode == R_RIGHT)
		raycast_param->turn_right = TRUE;
	else if (keycode == R_LEFT)
		raycast_param->turn_left = TRUE;
	return (0);
}

int	release_key(int keycode, t_raycast_param *raycast_param)
{
	if (keycode == LEFT)
		raycast_param->move_left = FALSE;
	else if (keycode == RIGHT)
		raycast_param->move_right = FALSE;
	else if (keycode == UP)
		raycast_param->move_forward = FALSE;
	else if (keycode == DOWN)
		raycast_param->move_backward = FALSE;
	else if (keycode == R_RIGHT)
		raycast_param->turn_right = FALSE;
	else if (keycode == R_LEFT)
		raycast_param->turn_left = FALSE;
	return (0);
}
