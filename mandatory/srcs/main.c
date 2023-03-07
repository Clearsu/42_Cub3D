/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:15:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/07 16:55:10 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "parse.h"
#include "raycast.h"
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
	ft_memset(&map_data->tex_fname, 0, sizeof(char *) * 4);
	ft_memset(&map_data->color, 0, sizeof(unsigned int) * 2);
	ft_memset(&map_data->spawn, 0, sizeof(int) * 3);
	ft_memset(&mlx_vars->img_data, 0, sizeof(t_img_data));
	map_data->map = NULL;
	map_data->width = 0;
	map_data->height = 0;
	mlx_vars->mlx = NULL;
	mlx_vars->win = NULL;
}

int	main(int argc, char **argv)
{
	t_parse_data	parse_data;
	t_map_data		map_data;
	t_mlx_vars		mlx_vars;

	check_arg(argc, argv);
	init_structs(&parse_data, &map_data, &mlx_vars);
	parse(&map_data, &parse_data, argv[1]);
	play_start(&map_data, &mlx_vars);
	return (0);
}
