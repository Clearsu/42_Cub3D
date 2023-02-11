/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:49:36 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/11 21:48:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "struct.h"

void	play_start(t_map_data *map_data, t_mlx_vars *mlx_vars);
void	raycast(t_player_data *pdata, t_map_data *map_data);
void	init_mlx_and_img(t_mlx_vars *mlx_vars);
int		key_hook_handler(int key_code, t_mlx_vars *mlx_vars);
void	close_win_and_exit(t_mlx_vars *mlx_vars);

#endif
