/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:15:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 01:53:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

void	init_minimap_img(void *mlx, t_img_data *minimap_img);
void	put_minimap(t_mlx_vars *mlx_vars, t_img_data *minimap_img, \
		t_ray_data *rdata, t_map_data *map_data);

#endif
