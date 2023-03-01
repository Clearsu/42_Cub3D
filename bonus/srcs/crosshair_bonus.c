/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:06:40 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 22:24:21 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_bonus.h"

void	draw_crosshair(t_img_data *img_data)
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;

	x = WIDTH / 2 - CROSSHAIR_SIZE - 1;
	y = HEIGHT / 2 - CROSSHAIR_SIZE - 1;
	x_end = x + CROSSHAIR_SIZE * 2;
	y_end = y + CROSSHAIR_SIZE * 2;
	while (++x < x_end)
		my_mlx_pixel_put(img_data, x, HEIGHT / 2, CROSSHAIR_COLOR);
	while (++y < y_end)
		my_mlx_pixel_put(img_data, WIDTH / 2, y, CROSSHAIR_COLOR);
}
