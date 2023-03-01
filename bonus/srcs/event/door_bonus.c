/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:15:05 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 21:10:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"

static int	is_near_door(t_ray_data *rdata, char **map, \
		int *door_x, int *door_y)
{
	int	front_x;
	int	front_y;

	front_x = rdata->pos_x + rdata->dir_x;
	front_y = rdata->pos_y + rdata->dir_y;
	if (map[front_y][front_x] == DOOR_CLOSED || \
			map[front_y][front_x] == DOOR_OPENED)
	{
		*door_x = front_x;
		*door_y = front_y;
		return (TRUE);
	}
	return (FALSE);

}

void	door(t_raycast_param *raycast_param)
{
	int	door_x;
	int door_y;

	if (is_near_door(raycast_param->rdata, raycast_param->map_data->map, \
				&door_x, &door_y))
	{
		if (raycast_param->map_data->map[door_y][door_x] == DOOR_CLOSED)
			raycast_param->map_data->map[door_y][door_x] = DOOR_OPENED;
		else
			raycast_param->map_data->map[door_y][door_x] = DOOR_CLOSED;
	}
}
