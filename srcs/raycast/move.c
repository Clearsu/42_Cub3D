/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:41:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/13 23:27:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	move_left(t_raycast_param *raycast_param)
{
	raycast_param->rdata->pos_x -= 0.05;
	raycast(raycast_param);
}

void	move_right(t_raycast_param *raycast_param)
{
}

void	move_backward(t_raycast_param *raycast_param)
{
}

void	move_forward(t_raycast_param *raycast_param)
{
}
