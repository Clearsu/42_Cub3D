/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spawn_location.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:14:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 20:36:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct.h"
#include "../incs/error.h"

void	check_spawn_location(t_map_data *map_data)
{
	size_t	x;
	size_t	y;
	size_t	cnt;

	cnt = 0;
	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (map_data->map[y][x] == 'E' || map_data->map[y][x] == 'W' \
				|| map_data->map[y][x] == 'S' || map_data->map[y][x] == 'N')
			{
				map_data->spawn[SPAWN_X] = x;
				map_data->spawn[SPAWN_Y] = y;
				map_data->spawn[SPAWN_D] = map_data->map[y][x];
				cnt++;
			}
			x++;
		}
		y++;
	}
	if (cnt != 1)
		print_err_and_exit(E_MAP);
}
