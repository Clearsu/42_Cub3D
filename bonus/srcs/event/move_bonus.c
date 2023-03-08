/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:41:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/08 23:39:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "event_bonus.h"

void	move_left(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x + rdata->dir_y * MOVSPEED;
	new_pos_y = rdata->pos_y + (-1) * rdata->dir_x * MOVSPEED;
	if (map[(int)rdata->pos_y][(int)new_pos_x] != WALL && \
			map[(int)rdata->pos_y][(int)new_pos_x] != DOOR_CLOSED)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_y][(int)rdata->pos_x] != WALL && \
			map[(int)new_pos_y][(int)rdata->pos_x] != DOOR_CLOSED)
		rdata->pos_y = new_pos_y;
}

void	move_right(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x + (-1) * rdata->dir_y * MOVSPEED;
	new_pos_y = rdata->pos_y + rdata->dir_x * MOVSPEED;
	if (map[(int)rdata->pos_y][(int)new_pos_x] != WALL && \
			map[(int)rdata->pos_y][(int)new_pos_x] != DOOR_CLOSED)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_y][(int)rdata->pos_x] != WALL && \
			map[(int)new_pos_y][(int)rdata->pos_x] != DOOR_CLOSED)
		rdata->pos_y = new_pos_y;
}

void	move_forward(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x + rdata->dir_x * MOVSPEED;
	new_pos_y = rdata->pos_y + rdata->dir_y * MOVSPEED;
	if (map[(int)rdata->pos_y][(int)new_pos_x] != WALL && \
			map[(int)rdata->pos_y][(int)new_pos_x] != DOOR_CLOSED)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_y][(int)rdata->pos_x] != WALL && \
			map[(int)new_pos_y][(int)rdata->pos_x] != DOOR_CLOSED)
		rdata->pos_y = new_pos_y;
}

void	move_backward(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x - rdata->dir_x * MOVSPEED;
	new_pos_y = rdata->pos_y - rdata->dir_y * MOVSPEED;
	if (map[(int)rdata->pos_y][(int)new_pos_x] != WALL && \
			map[(int)rdata->pos_y][(int)new_pos_x] != DOOR_CLOSED)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_y][(int)rdata->pos_x] != WALL && \
			map[(int)new_pos_y][(int)rdata->pos_x] != DOOR_CLOSED)
		rdata->pos_y = new_pos_y;
}

void	move_player(t_key_state *key_state, t_ray_data *rdata, char **map)
{
	if (key_state->move_forward == TRUE)
		move_forward(rdata, map);
	if (key_state->move_backward == TRUE)
		move_backward(rdata, map);
	if (key_state->move_left == TRUE)
		move_left(rdata, map);
	if (key_state->move_right == TRUE)
		move_right(rdata, map);
	if (key_state->turn_left == TRUE)
		turn_left(rdata, ROTSPEED);
	if (key_state->turn_right == TRUE)
		turn_right(rdata, ROTSPEED);
}
