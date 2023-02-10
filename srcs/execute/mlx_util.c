/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:56:57 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 23:36:00 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "execute.h"

void	init_mlx_and_img(t_mlx_vars *mlx_vars)
{
	mlx_vars->mlx = mlx_init();
	mlx_vars->win = mlx_new_window(mlx_vars->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_vars->img_data.img = mlx_new_image(mlx_vars->mlx, WIDTH, HEIGHT);
	mlx_vars->img_data.addr = mlx_get_data_addr(mlx_vars->img_data.img,
			&mlx_vars->img_data.bits_per_pixel,
			&mlx_vars->img_data.line_length, &mlx_vars->img_data.endian);
}

int	key_hook_handler(int keycode, t_mlx_vars *mlx_vars)
{
	if (keycode == ESC)
		close_win_and_exit(mlx_vars);
	return (0);
}
