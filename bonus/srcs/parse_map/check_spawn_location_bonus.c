/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spawn_location_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:14:55 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/02 17:27:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "error_bonus.h"

static int	is_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

static void	set_player_spawn_loc(t_map_data *map_data, int x, int y, int *cnt)
{
	map_data->spawn[SPAWN_X] = x;
	map_data->spawn[SPAWN_Y] = y;
	map_data->spawn[SPAWN_D] = map_data->map[y][x];
	map_data->map[y][x] = INSIDE;
	*cnt += 1;
}

static void	set_enemy_spawn_loc(t_map_data *map_data, int x, int y)
{
	map_data->enemy_spawn[SPAWN_X] = x;
	map_data->enemy_spawn[SPAWN_Y] = y;
	map_data->map[y][x] = INSIDE;
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
				set_player_spawn_loc(map_data, x, y, &cnt);
			else if (map_data->map[y][x] == ENEMY)
				set_enemy_spawn_loc(map_data, x, y);
			x++;
		}
		y++;
	}
	if (cnt != 1)
		print_err_and_exit(E_MAP);
}
