/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_maze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:54:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 23:32:16 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "execute.h"
#include "mlx.h"

void	execute_maze(t_map_data *map_data, t_mlx_vars *mlx_vars)
{
	init_mlx_and_img(mlx_vars);
	mlx_key_hook(mlx_vars->win, key_hook_handler, mlx_vars);
	mlx_loop(mlx_vars->mlx);
}
