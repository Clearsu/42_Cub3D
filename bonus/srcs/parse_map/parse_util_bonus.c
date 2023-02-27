/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:18:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 19:37:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "error_bonus.h"

void	free_token_and_exit(t_token *token, t_err_type err_type)
{
	free(token);
	print_err_and_exit(err_type);
}

static void	free_2d_arr(char **ptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(ptr[i++]);
	free(ptr);
}

char	**calloc_2d_char_arr(size_t width, size_t height)
{
	char	**ptr;
	size_t	i;

	ptr = ft_calloc(height, sizeof(char *));
	if (!ptr)
		print_err_and_exit(E_SYS);
	i = 0;
	while (i < height)
	{
		ptr[i] = ft_calloc(width, sizeof(char));
		if (!ptr[i])
		{
			free_2d_arr(ptr, i);
			print_err_and_exit(E_SYS);
		}
		i++;
	}
	return (ptr);
}
