/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:03:26 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/02 22:20:19 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
	int	v_move_screen;
	int	sprite_height;

	v_move_screen = (int)(vMove / enemy->inverse_y);
	sprite_height = (int)dabs((HEIGHT / enemy->inverse_y) / vDiv); //prevent fisheye
	enemy->draw_start_y = (-1) * sprite_height / 2 + HEIGHT / 2 + v_move_screen;
	if (enemy->draw_start_y < 0)
		draw_start_y = 0;
	enemy->draw_end_y = sprite_height / 2 + HEIGHT / 2 + v_move_screen;
	if (enemy->draw_end_y >= HEIGHT)
		enemy->draw_end_y = HEIGHT - 1;	
}

void	get_draw_x(t_enemy *enemy)
{
	int	enemy_width;

	enemy_width = (int)dabs((HEIGHT / enemy->inverse_y) / uDiv);
	int drawStartX = -spriteWidth / 2 + spriteScreenX;
	if(drawStartX < 0) drawStartX = 0;
	int drawEndX = spriteWidth / 2 + spriteScreenX;
	if(drawEndX >= width) drawEndX = width - 1;
}*/
