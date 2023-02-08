/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:45:28 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 03:21:26 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/define.h"

static t_token	*init_token_and_get_color_value(char *str)
{
	t_token	*token;
	size_t	idx;
	size_t	start;
	size_t	finish;
	
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		print_err_and_exit(E_SYS);
	idx = 2;
	while (str[idx++] == ' ');
	start = idx;
	while (str[idx++] != ' ');
	finish = idx;
	token->value = (void *)ft_substr(str, start, finish - start);
	if (!token_value)
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
