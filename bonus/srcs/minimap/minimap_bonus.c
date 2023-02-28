/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:35:13 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/28 22:13:30 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "raycast_bonus.h"
#include "struct_bonus.h"

void	init_minimap_img(void *mlx, t_img_data *minimap_img)
{
	minimap_img->img =
		mlx_new_image(mlx, MINI_WIDTH, MINI_HEIGHT);
	minimap_img->addr = mlx_get_data_addr(minimap_img->img,
				&minimap_img->bits_per_pixel,
				&minimap_img->line_length,
				&minimap_img->endian);
}

static void	draw_minimap(t_img_data *minimap_img, t_ray_data *rdata,
		t_map_data *map_data)
{
	int	x;
	int	y;
	double	draw_start_x;
	double	draw_start_y;
	int		draw_y;
	int		draw_x;

	draw_start_x = rdata->pos_x - MINI_OFFSET / 2;
	draw_start_y = rdata->pos_y - MINI_OFFSET / 2;
	y = -1;
	while (++y < MINI_HEIGHT)
	{
		x = -1;
		draw_y = draw_start_y + MINI_OFFSET * y / MINI_HEIGHT;
		while (++x < MINI_WIDTH)
		{
			draw_x = draw_start_x + MINI_OFFSET * x / MINI_WIDTH;
			if (draw_y < 0 || draw_y >= map_data->height
					|| draw_x < 0 || draw_x >= map_data->width
					|| map_data->map[draw_y][draw_x] == OUTSIDE
					|| map_data->map[draw_y][draw_x] == WALL)
				my_mlx_pixel_put(minimap_img, x, y, MINI_WALL_COLOR);
			else
				my_mlx_pixel_put(minimap_img, x, y, MINI_BACKGROUND_COLOR);
		}
	}
}

static void	draw_player(t_img_data *minimap_img)
{
	int	x;
	int	y;
	int	p_draw_end_x;
	int	p_draw_end_y;

	x = MINI_WIDTH / 2 - MINI_PLAYER_SIZE / 2 + 10;
	y = MINI_HEIGHT / 2 - MINI_PLAYER_SIZE / 2;
	p_draw_end_x = x + MINI_PLAYER_SIZE;
	p_draw_end_y = x + MINI_PLAYER_SIZE;
	while (++y <= p_draw_end_y)
	{
		x = MINI_WIDTH / 2 - 3;
		while (++x < p_draw_end_x)
			my_mlx_pixel_put(minimap_img, x, y, MINI_PLAYER_COLOR);
	}
}

void	put_minimap(t_mlx_vars *mlx_vars, t_img_data *minimap_img,
		t_ray_data *rdata, t_map_data *map_data)
{
	draw_minimap(minimap_img, rdata, map_data);
	draw_player(minimap_img);
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, minimap_img->img, 20, 20);
}
