/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:41:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/20 22:55:46 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raycast.h"

// ㅋㅓㄴ센서스 베이비로션향

void	turn_right(t_ray_data *rdata)
{
	double	dir_x_cp;
	double	plane_x_cp;

	dir_x_cp = rdata->dir_x;
	rdata->dir_x = rdata->dir_x * cos(ROTSPEED) - rdata->dir_y * sin(ROTSPEED);
	rdata->dir_y = dir_x_cp * sin(ROTSPEED) + rdata->dir_y * cos(ROTSPEED);
	plane_x_cp = rdata->plane_x;
	rdata->plane_x = rdata->plane_x * cos(ROTSPEED) - rdata->plane_y * sin(ROTSPEED);
	rdata->plane_y = plane_x_cp * sin(ROTSPEED) + rdata->plane_y * cos(ROTSPEED);
}

void	turn_left(t_ray_data *rdata)
{
	double	rotspeed;
	double	plane_x_cp;

	rotspeed = (-1) * ROTSPEED;
	rdata->dir_x = rdata->dir_x * cos(rotspeed) - rdata->dir_y * sin(rotspeed);
	rdata->dir_y = rdata->dir_x * sin(rotspeed) + rdata->dir_y * cos(rotspeed);
	plane_x_cp = rdata->plane_x;
	rdata->plane_x = rdata->plane_x * cos(rotspeed) - rdata->plane_y * sin(rotspeed);
	rdata->plane_y = plane_x_cp * sin(rotspeed) + rdata->plane_y * cos(rotspeed);
}

void	move_left(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x + rdata->dir_y * MOVSPEED;
	new_pos_y = rdata->pos_y + (-1) * rdata->dir_x * MOVSPEED;
	if (map[(int)new_pos_x][(int)rdata->pos_y] == INSIDE)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_x][(int)new_pos_y] == INSIDE)
		rdata->pos_y = new_pos_y;
}

void	move_right(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x + (-1) * rdata->dir_y * MOVSPEED;
	new_pos_y = rdata->pos_y + rdata->dir_x * MOVSPEED;
	if (map[(int)new_pos_x][(int)rdata->pos_y] == INSIDE)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_x][(int)new_pos_y] == INSIDE)
		rdata->pos_y = new_pos_y;
}

void	move_forward(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x + rdata->dir_x * MOVSPEED;
	new_pos_y = rdata->pos_y + rdata->dir_y * MOVSPEED;
	if (map[(int)new_pos_x][(int)rdata->pos_y] == INSIDE)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_x][(int)new_pos_y] == INSIDE)
		rdata->pos_y = new_pos_y;
}

void	move_backward(t_ray_data *rdata, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = rdata->pos_x - rdata->dir_x * MOVSPEED;
	new_pos_y = rdata->pos_y - rdata->dir_y * MOVSPEED;
	if (map[(int)new_pos_x][(int)rdata->pos_y] == INSIDE)
		rdata->pos_x = new_pos_x;
	if (map[(int)new_pos_x][(int)new_pos_y] == INSIDE)
		rdata->pos_y = new_pos_y;
}

void	move_player(t_raycast_param *raycast_param)
{
	t_key_state	*key_state;

	key_state = &raycast_param->key_state;
	if (key_state->move_forward == TRUE)
		move_forward(raycast_param->rdata, raycast_param->map_data->map);
	if (key_state->move_backward == TRUE)
		move_backward(raycast_param->rdata, raycast_param->map_data->map);
	if (key_state->move_left == TRUE)
		move_left(raycast_param->rdata, raycast_param->map_data->map);
	if (key_state->move_right == TRUE)
		move_right(raycast_param->rdata, raycast_param->map_data->map);
	if (key_state->turn_left == TRUE)
		turn_left(raycast_param->rdata);
	if (key_state->turn_right == TRUE)
		turn_right(raycast_param->rdata);
}
