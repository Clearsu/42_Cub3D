/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_fully_closed_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:59:07 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/27 17:29:25 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "error_bonus.h"

static int	is_element_near(t_map_data *map_data, int x, int y, int element)
{
	if (x > 0 && map_data->map[y][x - 1] == element)
		return (TRUE);
	if (y > 0 && map_data->map[y - 1][x] == element)
		return (TRUE);
	if (x < map_data->width - 1 && map_data->map[y][x + 1] == element)
		return (TRUE);
	if (y < map_data->height - 1 && map_data->map[y + 1][x] == element)
		return (TRUE);
	return (FALSE);
}

void	is_map_fully_closed(t_map_data *map_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (map_data->map[y][x] == OUTSIDE)
			{
				if (!is_element_near(map_data, x, y, WALL) && \
						!is_element_near(map_data, x, y, OUTSIDE))
					print_err_and_exit(E_MAP);
			}
			++x;
		}
		++y;
	}
}
