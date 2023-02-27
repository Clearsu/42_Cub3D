/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:45:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 19:45:29 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse_bonus.h"
#include "error_bonus.h"

static t_token	*init_token_and_get_color_value(char *str)
{
	t_token	*token;
	size_t	idx;
	size_t	start;
	size_t	finish;

	idx = 2;
	while (str[idx] == ' ')
		++idx;
	start = idx;
	while (str[idx] != '\n')
		++idx;
	finish = idx;
	if (start == finish - 1)
		print_err_and_exit(E_MAP);
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		print_err_and_exit(E_SYS);
	token->value = (void *)ft_substr(str, start, finish - start);
	if (!token->value)
		free_token_and_exit(token, E_SYS);
	return (token);
}

void	make_floor_color_token(t_state *state, t_parse_data *parse_data)
{
	char	*str;
	t_token	*token;

	str = (char *)parse_data->buff_now->content;
	token = init_token_and_get_color_value(str);
	token->type = C_FLOOR;
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	*state = BRANCH;
	parse_data->buff_now = parse_data->buff_now->next;
}

void	make_ceiling_color_token(t_state *state, t_parse_data *parse_data)
{
	char	*str;
	t_token	*token;

	str = (char *)parse_data->buff_now->content;
	token = init_token_and_get_color_value(str);
	token->type = C_CEILING;
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	*state = BRANCH;
	parse_data->buff_now = parse_data->buff_now->next;
}
