/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:18 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 23:34:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx.h"

void	close_win_and_exit(t_mlx_vars *mlx_vars)
{
	mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
	exit(0);
}
