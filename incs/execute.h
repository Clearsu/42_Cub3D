/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:49:36 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 23:35:34 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "struct.h"

void	execute_maze(t_map_data *map_data, t_mlx_vars *mlx_vars);
void	init_mlx_and_img(t_mlx_vars *mlx_vars);
int		key_hook_handler(int key_code, t_mlx_vars *mlx_vars);
void	close_win_and_exit(t_mlx_vars *mlx_vars);

#endif
