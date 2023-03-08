/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:21:21 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/08 23:48:39 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_BONUS_H
# define EVENT_BONUS_H

# include "struct_bonus.h"

// move player
void	move_player(t_key_state *key_state, t_ray_data *rdata, char **map);
void	move_left(t_ray_data *rdata, char **map);
void	move_right(t_ray_data *rdata, char **map);
void	move_forward(t_ray_data *rdata, char **map);
void	move_backward(t_ray_data *rdata, char **map);

// rotation
void	turn_right(t_ray_data *rdata, double rotspeed);
void	turn_left(t_ray_data *rdata, double rotspeed);

// key hook
int		press_key(int keycode, t_raycast_param *raycast_param);
int		release_key(int keycode, t_raycast_param *raycast_param);
void	door(t_raycast_param *raycast_param);

#endif
