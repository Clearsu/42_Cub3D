/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:36:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 21:39:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../incs/define.h"
#include "../incs/struct.h"
#include "../incs/state.h"
#include "../incs/parse.h"
#include "../incs/error.h"

static t_list	*put_lines_into_buff_list(int fd)
{
	char	*line;
	t_list	*buff_list;
	t_list	*new_list;

	buff_list = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_list = ft_lstnew((void *)line);
		if (!new_list)
		{
			if (buff_list)
				ft_lstclear(&buff_list, free);
			print_err_and_exit(E_SYS);
		}
		ft_lstadd_back(&buff_list, new_list);
	}
	return (buff_list);
}

static void	make_token_list(t_parse_data *parse_data)
{
	t_state					state;
	static const t_state_fp	state_fp[TOTAL_STATES - 1] = {
		start, branch,
		make_empty_token,
		make_east_texture_token,
		make_west_texture_token,
		make_south_texture_token,
		make_north_texture_token,
		make_floor_color_token,
		make_ceiling_color_token,
		make_map_token
	};

	state = START;
	while (state != FINISH)
		state_fp[state](&state, parse_data);
}
/*
#include <stdio.h>
void	print_token_list(t_list *token_list)
{
	t_token *token;

	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == EMPTY)
			printf("type: EMPTY, value: null\n");
		else if (token->type == T_EAST || token->type == T_WEST
			|| token->type == T_SOUTH || token->type == T_NORTH)
			printf("type: TEXTURE, value: %s\n", (char *)token->value);
		else if (token->type == C_FLOOR || token->type == C_CEILING)
			printf("type: COLOR, value: %s\n", (char *)token->value);
		else if (token->type == MAP)
			printf("type: MAP, value: %s\n", (char *)token->value);
		token_list = token_list->next;
	}
}*/

void	parse(t_map_data *map_data, t_parse_data *parse_data, char *fname)
{
	int	fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(E_SYS);
	parse_data->buff_list = put_lines_into_buff_list(fd);
	check_invalid_char(parse_data->buff_list);
	make_token_list(parse_data);
//	print_token_list(parse_data->token_list);
	check_map_configuration(parse_data->token_list);
	check_map_order(parse_data->token_list);
	parse_texture(map_data->texture, parse_data->token_list);
	parse_color(map_data->color, parse_data->token_list);
	parse_map(map_data, parse_data->token_list);
}
