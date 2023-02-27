/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_empty_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:05:48 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 19:45:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "error_bonus.h"

void	make_empty_token(t_state *state, t_parse_data *parse_data)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		print_err_and_exit(E_SYS);
	token->type = EMPTY;
	token->value = NULL;
	ft_lstadd_back(&parse_data->token_list, ft_lstnew((void *)token));
	parse_data->buff_now = parse_data->buff_now->next;
	*state = BRANCH;
}
