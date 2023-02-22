/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:05:12 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/22 20:17:43 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	get_width(int *width, t_list *token_list)
{
	t_token	*token;
	int		longest;
	int		curr_len;

	longest = 0;
	curr_len = 0;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == MAP)
		{
			curr_len = ft_strlen((char *)token->value);
			if (curr_len > longest)
				longest = curr_len;
		}
		token_list = token_list->next;
	}
	*width = longest;
}

static void	get_height(int *height, t_list *token_list)
{
	t_token	*token;
	int		len;

	len = 0;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == MAP)
			len++;
		token_list = token_list->next;
	}
	*height = len;
}

static char	select_char(char c)
{
	if (c == ' ')
		return (OUTSIDE);
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (INSIDE);
	else
		return (c);
}

static void	put_map_element(t_map_data *map_data, t_list *token_list)
{
	t_token	*token;
	size_t	x;
	size_t	y;
	char	*str;

	y = 0;
	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == MAP)
		{
			x = 0;
			str = (char *)token->value;
			while (*str)
			{
				map_data->map[y][x] = select_char(*str);
				str++;
				x++;
			}
			while (x < map_data->width)
				map_data->map[y][x++] = OUTSIDE;
			y++;
		}
		token_list = token_list->next;
	}
}

void	parse_map(t_map_data *map_data, t_list *token_list)
{
	get_width(&map_data->width, token_list);
	get_height(&map_data->height, token_list);
	map_data->map = calloc_2d_char_arr(map_data->width, map_data->height);
	put_map_element(map_data, token_list);
	basic_wall_check(map_data);
	is_map_fully_closed(map_data);
	check_spawn_location(map_data);
}
