/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_wall_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:14:27 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 20:03:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct.h"
#include "../incs/error.h"

static void	check_left_wall(t_map_data *map_data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (map_data->map[y][x] == OUTSIDE)
			x++;
		if (map_data->map[y][x] == WALL)
		{
			y++;
			continue ;
		}
		else
			print_err_and_exit(E_MAP);
	}
}

static void	check_right_wall(t_map_data *map_data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_data->height)
	{
		x = map_data->width - 1;
		while (map_data->map[y][x] == OUTSIDE)
			x--;
		if (map_data->map[y][x] == WALL)
		{
			y++;
			continue ;
		}
		else
			print_err_and_exit(E_MAP);
	}
}

static void	check_top_wall(t_map_data *map_data)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map_data->width)
	{
		y = 0;
		while (map_data->map[y][x] == OUTSIDE)
			y++;
		if (map_data->map[y][x] == WALL)
		{
			x++;
			continue ;
		}
		else
			print_err_and_exit(E_MAP);
	}
}

static void	check_bottom_wall(t_map_data *map_data)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < map_data->width)
	{
		y = map_data->height - 1;
		while (map_data->map[y][x] == OUTSIDE)
			y--;
		if (map_data->map[y][x] == WALL)
		{
			x++;
			continue ;
		}
		else
			print_err_and_exit(E_MAP);
	}
}

void	basic_wall_check(t_map_data *map_data)
{
	check_left_wall(map_data);
	check_right_wall(map_data);
	check_top_wall(map_data);
	check_bottom_wall(map_data);
	//check_if_fully_closed(map_data);
	//is_single_spawn_location(map_data);
}
