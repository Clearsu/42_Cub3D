/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:21:21 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 18:18:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# include "struct_bonus.h"

void	move_player(t_raycast_param *raycast_param);
void	move_left(t_ray_data *rdata, char **map);
void	move_right(t_ray_data *rdata, char **map);
void	move_forward(t_ray_data *rdata, char **map);
void	move_backward(t_ray_data *rdata, char **map);
void	turn_right(t_ray_data *rdata);
void	turn_left(t_ray_data *rdata);
int		press_key(int keycode, t_raycast_param *raycast_param);
int		release_key(int keycode, t_raycast_param *raycast_param);
int		close_win_and_exit(t_raycast_param *raycast_param);

#endif
