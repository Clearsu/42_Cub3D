/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:49:36 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/13 22:43:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

void	play_start(t_map_data *map_data, t_mlx_vars *mlx_vars);
int		raycast(t_raycast_param *raycast_param);
void	init_mlx_and_img(t_mlx_vars *mlx_vars);
int		key_hook_handler(int key_code, t_raycast_param *raycast_param);
void	move_left(t_raycast_param *raycast_param);
void	move_right(t_raycast_param *raycast_param);
void	move_forward(t_raycast_param *raycast_param);
void	move_backward(t_raycast_param *raycast_param);
void	close_win_and_exit(t_mlx_vars *mlx_vars);
void	my_mlx_pixel_put(t_img_data *img_data,
		size_t x, size_t y, unsigned int color);

#endif
