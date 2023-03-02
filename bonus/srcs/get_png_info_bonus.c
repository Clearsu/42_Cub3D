/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_png_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:47:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/02 17:13:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct_bonus.h"
#include "error_bonus.h"

static void	destroy_image_and_free_array_and_exit(void *mlx, void *img, \
		t_tex_data *tex_data, int i)
{
	if (mlx && img)
		mlx_destroy_image(mlx, img);
	while (--i >= 0)
		free(tex_data[i].texture);
	print_err_and_exit(E_SYS);
}

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

static void	get_texture_image_info(t_raycast_param *raycast_param)
{
	t_img_data	img_data;
	int			i;

	i = 0;
	while (i < 5)
	{
		img_data.img = mlx_png_file_to_image(raycast_param->mlx_vars->mlx,
				raycast_param->map_data->tex_fname[i],
				&img_data.width, &img_data.height);
		if (img_data.img == NULL)
			destroy_image_and_free_array_and_exit(NULL, NULL, \
					raycast_param->tex_data, i);
		img_data.addr = mlx_get_data_addr(img_data.img,
				&img_data.bits_per_pixel, &img_data.line_length,
				&img_data.endian);
		raycast_param->tex_data[i].texture = \
			ft_calloc(img_data.width * img_data.height, sizeof(unsigned int));
		if (!raycast_param->tex_data[i].texture)
			destroy_image_and_free_array_and_exit(raycast_param->mlx_vars->mlx, \
					img_data.img, raycast_param->tex_data, i);
		copy_image(&raycast_param->tex_data[i++], &img_data);
		mlx_destroy_image(raycast_param->mlx_vars->mlx, img_data.img);
	}
}

static void	get_enemy_image_info(t_raycast_param *raycast_param)
{
	t_img_data	img_data;
	int			i;
	char		*tex_path;

	i = 0;
	tex_path = ENEMY_TEXTURE_1;
	while (i < 2)
	{
		img_data.img = mlx_png_file_to_image(raycast_param->mlx_vars->mlx,
				tex_path, &img_data.width, &img_data.height);
		if (img_data.img == NULL)
			destroy_image_and_free_array_and_exit(NULL, NULL, \
					raycast_param->enemy.tex_data, i);
		img_data.addr = mlx_get_data_addr(img_data.img,
				&img_data.bits_per_pixel, &img_data.line_length,
				&img_data.endian);
		raycast_param->enemy.tex_data[i].texture = \
			ft_calloc(img_data.width * img_data.height, sizeof(unsigned int));
		if (!raycast_param->enemy.tex_data[i].texture)
			destroy_image_and_free_array_and_exit(raycast_param->mlx_vars->mlx, \
					img_data.img, raycast_param->enemy.tex_data, i);
		copy_image(&raycast_param->enemy.tex_data[i++], &img_data);
		mlx_destroy_image(raycast_param->mlx_vars->mlx, img_data.img);
		tex_path = ENEMY_TEXTURE_2;
	}
}

void	get_png_info(t_raycast_param *raycast_param)
{
	get_enemy_image_info(raycast_param);
	get_texture_image_info(raycast_param);
}
