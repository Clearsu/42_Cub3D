/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_fully_closed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:59:07 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 20:12:07 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct.h"
#include "../incs/error.h"

static void	is_facing_outside(char **map, size_t x, size_t y)
{
	if (map[y][x - 1] == OUTSIDE || map[y][x + 1] == OUTSIDE \
		|| map[y - 1][x] == OUTSIDE || map[y + 1][x] == OUTSIDE)
		print_err_and_exit(E_MAP);
}

void	is_map_fully_closed(t_map_data *map_data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (map_data->map[y][x] == INSIDE)
				is_facing_outside(map_data->map, x, y);
			x++;
		}
		y++;
	}
}
