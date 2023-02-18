/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:49:36 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/19 00:14:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

void	play_start(t_map_data *map_data, t_mlx_vars *mlx_vars);
int		raycast(t_raycast_param *raycast_param);
void	init_mlx_and_img(t_mlx_vars *mlx_vars);
int		press_key(int keycode, t_raycast_param *raycast_param);
int		release_key(int keycode, t_raycast_param *raycast_param);
void	move_player(t_raycast_param *raycast_param);
void	move_left(t_ray_data *rdata, char **map);
void	move_right(t_ray_data *rdata, char **map);
void	move_forward(t_ray_data *rdata, char **map);
void	move_backward(t_ray_data *rdata, char **map);
void	turn_right(t_ray_data *rdata);
void	turn_left(t_ray_data *rdata);
void	close_win_and_exit(t_mlx_vars *mlx_vars);
void	my_mlx_pixel_put(t_img_data *img_data,
		size_t x, size_t y, unsigned int color);

#endif
