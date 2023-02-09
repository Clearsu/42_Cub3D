/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:18:05 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 21:21:08 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "../incs/struct.h"
#include "../incs/define.h"
#include "../incs/error.h"

void	check_invalid_char(t_list *buff_list)
{
	char	*str;

	while (buff_list)
	{
		str = (char *)buff_list->content;
		while (*str)
		{
			if (!ft_isascii(*str) || *str == '\t')
				print_err_and_exit(E_MAP);
			str++;
		}
		buff_list = buff_list->next;
	}
}

void	check_map_configuration(t_list *token_list)
{
	unsigned int	hashmap[TOTAL_STATES - 4];
	t_token			*token;
	size_t			i;

	ft_memset(hashmap, 0, sizeof(unsigned int) * (TOTAL_STATES - 4));
	while (token_list)
	{
		token = (t_token *)token_list->content;
		token_list = token_list->next;
		if (hashmap[MAP - 3] == TRUE || token->type == EMPTY)
			continue ;
		hashmap[token->type - 3]++;
	}
	i = 0;
	while (i < TOTAL_STATES - 4)
	{
		if (hashmap[i] == 0 || hashmap[i] > 1)
			print_err_and_exit(E_MAP);
		i++;
	}
}

void	check_map_order(t_list *token_list)
{
	t_token	*token;

	token = (t_token *)token_list->content;
	while (token_list && token->type != MAP)
	{
		token_list = token_list->next;
		if (token_list)
			token = (t_token *)token_list->content;
	}
	while (token_list && token->type == MAP)
	{
		token_list = token_list->next;
		if (token_list)
			token = (t_token *)token_list->content;
	}
	while (token_list && token->type == EMPTY)
	{
		token_list = token_list->next;
		if (token_list)
			token = (t_token *)token_list->content;
	}
	if (token_list != NULL)
		print_err_and_exit(E_MAP);
}
