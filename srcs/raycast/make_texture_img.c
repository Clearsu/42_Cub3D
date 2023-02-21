/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:47:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/21 21:20:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct.h"
#include "define.h"
#include "error.h"

static void	init_texture_img(t_img_data *img_data, void *mlx, char *filename)
{
	int	width;
	int	height;

	img_data->img = mlx_png_file_to_image(mlx, filename,
			&img_data->width, &img_data->height);
	if (img_data->img == NULL)
		print_err_and_exit(E_SYS);
	img_data->addr = mlx_get_data_addr(img_data->img,
			&img_data->bits_per_pixel,
			&img_data->line_length,
			&img_data->endian);
}

void	make_texture_img(t_map_data *map_data, t_mlx_vars *mlx_vars)
{
	int	i;

	i = EAST;
	while (i <= NORTH)
	{
		init_texture_img(&map_data->tex_img_data[i], mlx_vars->mlx,
				map_data->texture[i]);
		i++;
	}
}
