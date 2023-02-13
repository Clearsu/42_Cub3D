/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:56:57 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/13 22:02:41 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"
#include "raycast.h"

void	init_mlx_and_img(t_mlx_vars *mlx_vars)
{
	mlx_vars->mlx = mlx_init();
	mlx_vars->win = mlx_new_window(mlx_vars->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_vars->img_data.img = mlx_new_image(mlx_vars->mlx, WIDTH, HEIGHT);
	mlx_vars->img_data.addr = mlx_get_data_addr(mlx_vars->img_data.img,
			&mlx_vars->img_data.bits_per_pixel,
			&mlx_vars->img_data.line_length, &mlx_vars->img_data.endian);
}

void	my_mlx_pixel_put(t_img_data *img_data,
		size_t x, size_t y, unsigned int color)
{
	char	*dest;

	dest = img_data->addr 
		+ (y * img_data->line_length + x * (img_data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}
