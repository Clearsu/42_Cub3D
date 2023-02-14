/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:41:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/14 21:33:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

// ㅋㅓㄴ센서스 베이비로션향

void	rotate_left(t_ray_data *rdata)
{
	
}

void	rotate_right(t_ray_data *rdata)
{
}

void	move_left(t_ray_data *rdata, char **map)
{
}

void	move_right(t_ray_data *rdata, char **map)
{
}

void	move_forward(t_ray_data *rdata, char **map)
{
	if (map[(int)(rdata->pos_x + rdata->dir_x * MOVSPEED)][(int)rdata->pos_y] \
		== FALSE)
		rdata->pos_x += rdata->dir_x * MOVSPEED;
	if (map[(int)rdata->pos_x][(int)(rdata->pos_y + rdata->dir_y * MOVSPEED)] \
		== FALSE)
		rdata->pos_y += rdata->dir_y * MOVSPEED;
}

void	move_backward(t_ray_data *rdata, char **map)
{
	if (map[(int)(rdata->pos_x - rdata->dir_x * MOVSPEED)][(int)rdata->pos_y] \
		== FALSE)
		rdata->pos_x -= rdata->dir_x * MOVSPEED;
	if (map[(int)rdata->pos_x][(int)(rdata->pos_y - rdata->dir_y * MOVSPEED)] \
		== FALSE)
		rdata->pos_y -= rdata->dir_y * MOVSPEED;
}
