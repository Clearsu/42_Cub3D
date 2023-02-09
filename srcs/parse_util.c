/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:18:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 23:50:36 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/struct.h"
#include "../incs/error.h"

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

char	**alloc_2d_char_arr(size_t width, size_t height)
{
	char	**ptr;
	size_t	i;

	ptr = malloc(sizeof(char *) * (height));
	if (!ptr)
		print_err_and_exit(E_SYS);
	ft_memset(ptr, 0, height);
	while (i < height)
	{
		ptr[i] = malloc(sizeof(char) * (width));
		if (!ptr[i])
		{
			free_2d_arr(ptr, i);
			print_err_and_exit(E_SYS);
		}
		ft_memset(ptr[i], 0, width);
		i++;
	}
	return (ptr);
}
