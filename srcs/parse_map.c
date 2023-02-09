/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:05:12 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 23:53:14 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/parse.h"

static void	get_width(size_t *width, t_list *token_list)
{
	t_token	*token;
	size_t	longest;
	size_t	curr_len;

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

static void	get_height(size_t *height, t_list *token_list)
{
	t_token	*token;
	size_t	len;

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

static void	put_map_element(t_map_data *map_data, t_list *token_list)
{
	t_token	*token;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_data->height)
	{
		token = (t_token *)token_list->content;
		if
		x = 0;
		while (x < map_data->width)
		{
			x++;
		}
		y++;
	}
}

void	parse_map(t_map_data *map_data, t_list *token_list)
{
	get_width(&map_data->width, token_list);
	get_height(&map_data->height, token_list);
	map_data->map = alloc_2d_char_arr(map_data->width, map_data->height);
	put_map_element(map_data, token_list);
}