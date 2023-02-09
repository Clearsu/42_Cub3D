/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:15:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 18:20:45 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "../libft/libft.h"
#include "../incs/define.h"
#include "../incs/parse.h"
#include "../incs/struct.h"
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

static void	check_arg(int argc, char **argv)
{
	int	fd;

	if (argc == 1 || argc > 2)
		print_err_and_exit(E_ARG_NUM);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_err_and_exit(E_SYS);
	close(fd);
	if (!is_valid_extension(argv[1]))
		print_err_and_exit(E_ARG_EXTENSION);
}

void	init_structs(t_parse_data *parse_data, t_map_data *map_data)
{
	ft_memset(parse_data, 0, sizeof(t_parse_data));
	ft_memset(&map_data->texture, 0, sizeof(char *) * 4);
	ft_memset(&map_data->color, 0, sizeof(unsigned int) * 2);
	map_data->map = NULL;
	map_data->width = 0;
	map_data->height = 0;
}

#include <stdio.h>
void	print_token_list(t_list *token_list)
{
	t_token *token;

	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == EMPTY)
			printf("type: EMPTY, value: null\n");
		else if (token->type == T_EAST || token->type == T_WEST
			|| token->type == T_SOUTH || token->type == T_NORTH)
			printf("type: TEXTURE, value: %s\n", (char *)token->value);
		else if (token->type == C_FLOOR || token->type == C_CEILING)
			printf("type: COLOR, value: %s\n", (char *)token->value);
		else if (token->type == MAP)
			printf("type: MAP, value: %s\n", (char *)token->value);
		token_list = token_list->next;
	}
}
/*
void	print_buff_list(t_list *buff_list)
{
	while (buff_list)
	{
		printf("%s", (char *)buff_list->content);
		buff_list = buff_list->next;
	}
}
*/
int	main(int argc, char **argv)
{
	t_parse_data	parse_data;
	t_map_data		map_data;

	check_arg(argc, argv);
	init_structs(&parse_data, &map_data);
	parse_map_data(&map_data, &parse_data, argv[1]);
	print_token_list(parse_data.token_list);
	return (0);
}
