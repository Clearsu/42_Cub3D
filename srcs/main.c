/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:15:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 23:17:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "define.h"
#include "parse.h"
#include "struct.h"
#include "execute.h"
#include "error.h"

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

static void	init_structs(t_parse_data *parse_data,
		t_map_data *map_data, t_mlx_vars *mlx_vars)
{
	ft_memset(parse_data, 0, sizeof(t_parse_data));
	ft_memset(&map_data->texture, 0, sizeof(char *) * 4);
	ft_memset(&map_data->color, 0, sizeof(unsigned int) * 2);
	ft_memset(&map_data->spawn, 0, sizeof(size_t) * 2);
	ft_memset(&mlx_vars->img_data, 0, sizeof(t_img_data));
	map_data->map = NULL;
	map_data->width = 0;
	map_data->height = 0;
	mlx_vars->mlx = NULL;
	mlx_vars->win = NULL;
}

void	print_map_data(t_map_data *map_data)
{
	printf("TEXTURE\n");
	printf("EAST: %s\n", map_data->texture[0]);
	printf("WEST: %s\n", map_data->texture[1]);
	printf("SOUTH: %s\n", map_data->texture[2]);
	printf("NORTH: %s\n", map_data->texture[3]);
	printf("\n");
	printf("COLOR\n");
	printf("FLOOR: %u\n", map_data->color[0]);
	printf("CEILING: %u\n", map_data->color[1]);
	printf("\n");
	printf("MAP\n");
	for (int i = 0; i < map_data->height; i++)
	{
		for (int j = 0; j < map_data->width; j++)
			printf("%d", map_data->map[i][j]);
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_parse_data	parse_data;
	t_map_data		map_data;
	t_mlx_vars		mlx_vars;

	check_arg(argc, argv);
	init_structs(&parse_data, &map_data, &mlx_vars);
	parse(&map_data, &parse_data, argv[1]);
	print_map_data(&map_data);
	execute_maze(&map_data, &mlx_vars);
	return (0);
}
