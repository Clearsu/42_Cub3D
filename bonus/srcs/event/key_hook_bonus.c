/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 19:34:55 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "raycast_bonus.h"

int	close_win_and_exit(t_raycast_param *raycast_param)
{
	int	i;

	mlx_destroy_image(raycast_param->mlx_vars->mlx, \
			raycast_param->mlx_vars->img_data.img);
	mlx_destroy_window(raycast_param->mlx_vars->mlx, \
			raycast_param->mlx_vars->win);
	i = 0;
	while (i < 4)
		free(raycast_param->tex_data[i++].texture);
	exit(0);
	return (0);
}

int	press_key(int keycode, t_raycast_param *raycast_param)
{
	t_key_state	*key_state;

	key_state = &raycast_param->key_state;
	if (keycode == ESC)
		close_win_and_exit(raycast_param);
	else if (keycode == LEFT)
		key_state->move_left = TRUE;
	else if (keycode == RIGHT)
		key_state->move_right = TRUE;
	else if (keycode == UP)
		key_state->move_forward = TRUE;
	else if (keycode == DOWN)
		key_state->move_backward = TRUE;
	else if (keycode == R_RIGHT)
		key_state->turn_right = TRUE;
	else if (keycode == R_LEFT)
		key_state->turn_left = TRUE;
	return (0);
}

int	release_key(int keycode, t_raycast_param *raycast_param)
{
	t_key_state	*key_state;

	key_state = &raycast_param->key_state;
	if (keycode == LEFT)
		key_state->move_left = FALSE;
	else if (keycode == RIGHT)
		key_state->move_right = FALSE;
	else if (keycode == UP)
		key_state->move_forward = FALSE;
	else if (keycode == DOWN)
		key_state->move_backward = FALSE;
	else if (keycode == R_RIGHT)
		key_state->turn_right = FALSE;
	else if (keycode == R_LEFT)
		key_state->turn_left = FALSE;
	return (0);
}
