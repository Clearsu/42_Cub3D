/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:55:17 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 21:34:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/define.h"
#include "../incs/struct.h"
#include "../incs/parse.h"
#include "../incs/error.h"

static t_token	*init_token_and_get_path(char *str)
{
	t_token	*token;
	size_t	idx;
	size_t	start;
	size_t	finish;
	
	idx = 3;
	while (str[idx++] == ' ');
	start = idx - 1;
	while (str[idx] != ' ' && str[idx] != '\0' && str[idx] != '\n')
		idx++;
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

void	make_east_texture_token(t_state *state, t_parse_data *parse_data)
{
	char	*str;
	t_token	*token;

	str = (char *)parse_data->buff_now->content;
	token = init_token_and_get_path(str);
	token->type = T_EAST;
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	*state = BRANCH;
	parse_data->buff_now = parse_data->buff_now->next;
}

void	make_west_texture_token(t_state *state, t_parse_data *parse_data)
{
	char	*str;
	t_token	*token;

	str = (char *)parse_data->buff_now->content;
	token = init_token_and_get_path(str);
	token->type = T_WEST;
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	*state = BRANCH;
	parse_data->buff_now = parse_data->buff_now->next;
}

void	make_south_texture_token(t_state *state, t_parse_data *parse_data)
{
	char	*str;
	t_token	*token;

	str = (char *)parse_data->buff_now->content;
	token = init_token_and_get_path(str);
	token->type = T_SOUTH;
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	*state = BRANCH;
	parse_data->buff_now = parse_data->buff_now->next;
}

void	make_north_texture_token(t_state *state, t_parse_data *parse_data)
{
	char	*str;
	t_token	*token;

	str = (char *)parse_data->buff_now->content;
	token = init_token_and_get_path(str);
	token->type = T_NORTH;
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	*state = BRANCH;
	parse_data->buff_now = parse_data->buff_now->next;
}
