/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:38:45 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/26 14:42:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raycast.h"

void	turn_right(t_ray_data *rdata)
{
	double	dir_x_cp;
	double	plane_x_cp;

	dir_x_cp = rdata->dir_x;
	rdata->dir_x = rdata->dir_x * cos(ROTSPEED) - rdata->dir_y * sin(ROTSPEED);
	rdata->dir_y = dir_x_cp * sin(ROTSPEED) + rdata->dir_y * cos(ROTSPEED);
	plane_x_cp = rdata->plane_x;
	rdata->plane_x = rdata->plane_x * cos(ROTSPEED)
		- rdata->plane_y * sin(ROTSPEED);
	rdata->plane_y = plane_x_cp * sin(ROTSPEED)
		+ rdata->plane_y * cos(ROTSPEED);
}

void	turn_left(t_ray_data *rdata)
{
	double	rotspeed;
	double	dir_x_cp;
	double	plane_x_cp;

	rotspeed = (-1) * ROTSPEED;
	dir_x_cp = rdata->dir_x;
	rdata->dir_x = rdata->dir_x * cos(rotspeed) - rdata->dir_y * sin(rotspeed);
	rdata->dir_y = dir_x_cp * sin(rotspeed) + rdata->dir_y * cos(rotspeed);
	plane_x_cp = rdata->plane_x;
	rdata->plane_x = rdata->plane_x * cos(rotspeed)
		- rdata->plane_y * sin(rotspeed);
	rdata->plane_y = plane_x_cp * sin(rotspeed)
		+ rdata->plane_y * cos(rotspeed);
}
