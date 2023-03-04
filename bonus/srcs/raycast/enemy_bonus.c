/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:03:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/04 17:03:48 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_bonus.h"

void	get_inverse_x_y(t_ray_data *rdata, t_enemy *enemy)
{
	double	rel_x;
	double	rel_y;
	double	inv_constant;

	rel_x = enemy->pos_x - rdata->pos_x;
	rel_y = enemy->pos_y - rdata->pos_y;
	inv_constant = 1.0 / (rdata->plane_x * rdata->dir_y - rdata->dir_x * rdata->plane_y);
	enemy->inverse_x = inv_constant * (rdata->dir_y * rel_x - rdata->dir_x * rel_y);
	enemy->inverse_y = inv_constant * ((-1) * rdata->plane_y * rel_x + rdata->plane_x * rel_y);
}

void	get_draw_y(t_enemy *enemy)
{
	enemy->v_move_screen = (int)(vMove / enemy->inverse_y);
	enemy->sprite_height = (int)d_abs((HEIGHT / enemy->inverse_y) / vDiv); //prevent fisheye
	enemy->draw_start_y = (-1) * enemy->sprite_height / 2 + HEIGHT / 2 + enemy->v_move_screen;
	if (enemy->draw_start_y < 0)
		enemy->draw_start_y = 0;
	enemy->draw_end_y = enemy->sprite_height / 2 + HEIGHT / 2 + enemy->v_move_screen;
	if (enemy->draw_end_y >= HEIGHT)
		enemy->draw_end_y = HEIGHT - 1;	
}

void	get_draw_x(t_enemy *enemy)
{
	enemy->sprite_width = (int)d_abs((HEIGHT / enemy->inverse_y) / uDiv);
	enemy->sprite_screen_x = (int)((WIDTH / 2) * (1 + enemy->inverse_x / enemy->inverse_y));
	enemy->draw_start_x = (-1) * enemy->sprite_width / 2 + enemy->sprite_screen_x;
	if (enemy->draw_start_x < 0)
		enemy->draw_start_x = 0;
	enemy->draw_end_x = enemy->sprite_width / 2 + enemy->sprite_screen_x;
	if (enemy->draw_end_x >= WIDTH)
		enemy->draw_end_x = WIDTH - 1;
}

static void	draw_sprite_ver_line(t_enemy *enemy, t_img_data *img_data, int x, int tex_x)
{
	int	y;
	int	d;
	int	color;
	int	tex_y;

	y = enemy->draw_start_y - 1;
	while (++y < enemy->draw_end_y)
	{
		d = (y - enemy->v_move_screen) * 256 - HEIGHT * 128 + enemy->sprite_height * 128; //256 and 128 factors to avoid floats
		tex_y = ((d * enemy->tex_data[0].height) / enemy->sprite_height) / 256;
		color = enemy->tex_data[0].texture[enemy->tex_data[0].width * tex_y + tex_x]; //get current color from the texture
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(img_data, x, y, color); //paint pixel if it isn't black, black is the invisible color
	}
}

void	draw_sprite(t_raycast_param *raycast_param)
{
	t_enemy		*enemy;
	t_img_data	*img_data;
	int			x;
	int			tex_x;

	enemy = &raycast_param->enemy;
	img_data = &raycast_param->mlx_vars->img_data;
	x = enemy->draw_start_x - 1;
	while (++x < enemy->draw_end_x)
	{
		tex_x = (int)((256 * (x - ((-1) * enemy->sprite_width \
							/ 2 + enemy->sprite_screen_x)) \
					* enemy->tex_data[0].width / enemy->sprite_width) / 256);
		if (enemy->inverse_y > 0 && x > 0 && x < WIDTH && enemy->inverse_y < enemy->perp_wall_dist[x])
			draw_sprite_ver_line(enemy, img_data, x, tex_x);
	}
}
