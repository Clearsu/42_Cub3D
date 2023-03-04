/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:03:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/04 17:52:13 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raycast_bonus.h"

static void	get_inverse_x_y(t_ray_data *rdata, t_sprite *sprite)
{
	double	rel_x;
	double	rel_y;
	double	inv_constant;

	rel_x = sprite->pos_x - rdata->pos_x;
	rel_y = sprite->pos_y - rdata->pos_y;
	if (sqrt(rel_x * rel_x + rel_y * rel_y) < 3)
		sprite->tex_idx = 1;
	else
		sprite->tex_idx = 0;
	inv_constant = 1.0 / (rdata->plane_x * rdata->dir_y - rdata->dir_x * rdata->plane_y);
	sprite->inverse_x = inv_constant * (rdata->dir_y * rel_x - rdata->dir_x * rel_y);
	sprite->inverse_y = inv_constant * ((-1) * rdata->plane_y * rel_x + rdata->plane_x * rel_y);
}

static void	get_draw_y(t_sprite *sprite)
{
	sprite->v_move_screen = (int)(vMove / sprite->inverse_y);
	sprite->sprite_height = (int)d_abs((HEIGHT / sprite->inverse_y) / vDiv); //prevent fisheye
	sprite->draw_start_y = (-1) * sprite->sprite_height / 2 + HEIGHT / 2 + sprite->v_move_screen;
	if (sprite->draw_start_y < 0)
		sprite->draw_start_y = 0;
	sprite->draw_end_y = sprite->sprite_height / 2 + HEIGHT / 2 + sprite->v_move_screen;
	if (sprite->draw_end_y >= HEIGHT)
		sprite->draw_end_y = HEIGHT - 1;
}

static void	get_draw_x(t_sprite *sprite)
{
	sprite->sprite_width = (int)d_abs((HEIGHT / sprite->inverse_y) / uDiv);
	sprite->sprite_screen_x = (int)((WIDTH / 2) * (1 + sprite->inverse_x / sprite->inverse_y));
	sprite->draw_start_x = (-1) * sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_start_x < 0)
		sprite->draw_start_x = 0;
	sprite->draw_end_x = sprite->sprite_width / 2 + sprite->sprite_screen_x;
	if (sprite->draw_end_x >= WIDTH)
		sprite->draw_end_x = WIDTH - 1;
}

static void	draw_sprite_ver_line(t_sprite *sprite, t_img_data *img_data, int x, int tex_x)
{
	int	y;
	int	d;
	int	color;
	int	tex_y;

	y = sprite->draw_start_y - 1;
	while (++y < sprite->draw_end_y)
	{
		d = (y - sprite->v_move_screen) * 256 - HEIGHT * 128 + sprite->sprite_height * 128; //256 and 128 factors to avoid floats
		tex_y = ((d * sprite->tex_data[sprite->tex_idx].height) / sprite->sprite_height) / 256;
		color = sprite->tex_data[sprite->tex_idx].texture[sprite->tex_data[sprite->tex_idx].width * tex_y + tex_x]; //get current color from the texture
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(img_data, x, y, color); //paint pixel if it isn't black, black is the invisible color
	}
}

void	draw_sprite(t_ray_data *rdata, t_sprite *sprite, t_img_data *img_data)
{
	int			x;
	int			tex_x;

	get_inverse_x_y(rdata, sprite);
	get_draw_y(sprite);
	get_draw_x(sprite);
	x = sprite->draw_start_x - 1;
	while (++x < sprite->draw_end_x)
	{
		tex_x = (int)((256 * (x - ((-1) * sprite->sprite_width \
							/ 2 + sprite->sprite_screen_x)) \
					* sprite->tex_data[sprite->tex_idx].width / sprite->sprite_width) / 256);
		if (sprite->inverse_y > 0 && x > 0 && x < WIDTH && sprite->inverse_y < sprite->perp_wall_dist[x])
			draw_sprite_ver_line(sprite, img_data, x, tex_x);
	}
}
