/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:36:24 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/08 20:37:54 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../libft/libft.h"
#include "../incs/defines.h"
#include "../incs/struct.h"
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
			print_err_and_exit(E_SYS);
		ft_lstadd_back(&buff_list, new_list);
	}
	return (buff_list);
}

void	check_map(t_list **buff_lst, char *fname)
{
	int		fd;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		print_err_and_exit(E_SYS);
	*buff_lst = put_lines_into_buff_list(fd);
	/*
	if (!check_map_elements(buff_list))
	{
		ft_lstclear(&buff_list, ft_free);
		print_err_and_exit(E_MAP);
	}
	*/
}
