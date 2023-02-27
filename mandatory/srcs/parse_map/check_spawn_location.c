/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spawn_location.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:14:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/26 15:21:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "error.h"

static int	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

void	check_spawn_location(t_map_data *map_data)
{
	int	x;
	int	y;
	int	cnt;

	cnt = 0;
	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (is_direction(map_data->map[y][x]))
			{
				map_data->spawn[SPAWN_X] = x;
				map_data->spawn[SPAWN_Y] = y;
				map_data->spawn[SPAWN_D] = map_data->map[y][x];
				map_data->map[y][x] = INSIDE;
				cnt++;
			}
			x++;
		}
		y++;
	}
	if (cnt != 1)
		print_err_and_exit(E_MAP);
}
