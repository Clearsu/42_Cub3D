/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:47:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/22 16:54:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	get_texture_info(t_raycast_param *raycast_param)
{
	t_img_data	img_data;
	int			i;
	int			x;
	int			y;

	i = 0;
	while (i < 4)
	{
		img_data.img = mlx_png_file_to_image(raycast_param->mlx_vars->mlx,
				raycast_param->map_data->tex_fname[i],
				&img_data.width, &img_data.height);
		if (img_data.img == NULL)
			print_err_and_exit(E_SYS);
		img_data.addr = mlx_get_data_addr(img_data.img,
				&img_data.bits_per_pixel, &img_data.line_length,
				&img_data.endian);
		y = 0;
		while (y < TEX_HEIGHT)
		{
			x = 0;
			while (x < TEX_WIDTH)
			{
				raycast_param->texture[i][y * TEX_WIDTH + x] = \
					(unsigned int)img_data->addr \
					+ (y * img_data->line_length \
					+ x * (img_data->bits_per_pixel / 8));
				x++;
			}
			y++;
		}
		mlx_destroy_image(raycast_param->mlx_vars->mlx, img_data.img);
		i++;
	}
}
