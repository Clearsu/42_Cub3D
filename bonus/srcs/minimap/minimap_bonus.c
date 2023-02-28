/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:35:13 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/28 18:48:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"

void	init_minimap_img(t_raycast_param *raycast_param)
{
	raycast_param->minimap_img.img =
		mlx_new_image(raycast_param->mlx_vars->mlx, MINI_WIDTH, MINI_HEIGHT);
	raycast_param->minimap_img.addr =
		mlx_get_data_addr(raycast_param->minimap_img.img,
				&raycast_param->minimap_img.bits_per_pixel,
				&raycast_param->minimap_img.line_length,
				&raycast_param->minimap_img.endian);
}

void	put_minimap(t_raycast_param *raycast_param)
{
}
