/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:29:35 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 02:36:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct_bonus.h"

int     mlx_mouse_move(void *win_ptr, int x, int y);
int     mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

int	mouse_hook(t_raycast_param *raycast_param)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(raycast_param->mlx_vars->win, &x, &y);
	mlx_mouse_move(raycast_param->mlx_vars->win, x, y);
	return (0);
}
