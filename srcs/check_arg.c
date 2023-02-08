/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:17:49 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/08 18:54:24 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../incs/defines.h"
#include "../incs/check.h"
#include "../incs/error.h"

static int	is_valid_extension(char *fname)
{
	size_t	ext_idx;

	ext_idx = ft_strlen(fname) - ft_strlen(".cub");
	if (ext_idx == 0)
		return (FALSE);
	if (ft_strcmp(".cub", &fname[ext_idx]) == 0)
		return (TRUE);
	return (FALSE);
}

void	check_arg(int argc, char **argv)
{
	int	fd;

	if (argc == 1 || argc > 2)
		print_err_and_exit(E_ARG_NUM);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_err_and_exit(E_PERR);
	close(fd);
	if (!is_valid_extension(argv[1]))
		print_err_and_exit(E_ARG_EXTENSION);
}
