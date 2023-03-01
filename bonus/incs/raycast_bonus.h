/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:49:36 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 21:51:06 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

# include "struct_bonus.h"

void	play_start(t_map_data *map_data, t_mlx_vars *mlx_vars);
int		raycast(t_raycast_param *raycast_param, t_ray_data *rdata, \
		t_map_data *map_data, t_mlx_vars *mlx_vars);
void	get_map_x_y(t_ray_data *rdata);
void	get_delta_dist(t_ray_data *rdata);
void	get_step_and_initial_sidedist(t_ray_data *rdata);
void	init_mlx_and_img(t_mlx_vars *mlx_vars);
void	get_texture_info(t_raycast_param *raycast_param);
void	get_wall_texture(t_ray_data *rdata, t_map_data *map_data);
void	get_draw_start_end(t_ray_data *rdata);
void	draw_line(t_raycast_param *raycast_param, t_img_data *img_data, \
		unsigned int *color, int x);
void	get_camerax_and_ray_dir(t_ray_data *rdata, size_t x);
void	my_mlx_pixel_put(t_img_data *img_data, \
		size_t x, size_t y, unsigned int color);

#endif
