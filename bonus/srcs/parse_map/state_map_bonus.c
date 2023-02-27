/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:54:32 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 19:45:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "error_bonus.h"

void	make_map_token(t_state *state, t_parse_data *parse_data)
{
	t_token	*token;
	char	*str;
	size_t	len;

	str = (char *)parse_data->buff_now->content;
	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		print_err_and_exit(E_SYS);
	token->type = MAP;
	len = ft_strlen(str) - 1;
	while (str[len] == ' ' || str[len] == '\n')
		len--;
	token->value = (void *)ft_substr(str, 0, len + 1);
	if (!token->value)
		free_token_and_exit(token, E_SYS);
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	*state = BRANCH;
	parse_data->buff_now = parse_data->buff_now->next;
}
