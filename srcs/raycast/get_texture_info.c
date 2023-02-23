/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:47:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/23 15:27:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct.h"
#include "error.h"

static void	copy_image(t_tex_data *tex_data, t_img_data *img_data)
{
	int				x;
	int				y;
	unsigned int	*addr;

	addr = (unsigned int *)img_data->addr;
	y = 0;
	while (y < img_data->height)
	{
		x = 0;
		while (x < img_data->width)
		{
			tex_data->texture[y * img_data->width + x] = \
				addr[y * img_data->width + x];
			x++;
		}
		y++;
	}
	tex_data->width = img_data->width;
	tex_data->height = img_data->height;
}

void	get_texture_info(t_raycast_param *raycast_param)
{
	t_img_data	img_data;
	int			i;

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
		raycast_param->tex_data[i].texture = \
			ft_calloc(img_data.width * img_data.height, sizeof(unsigned int));
		if (!raycast_param->tex_data[i].texture)
		{
			while (--i >= 0)
				free(raycast_param->tex_data[i].texture);
			print_err_and_exit(E_SYS);
		}
		copy_image(&raycast_param->tex_data[i++], &img_data);
		mlx_destroy_image(raycast_param->mlx_vars->mlx, img_data.img);
	}
}
