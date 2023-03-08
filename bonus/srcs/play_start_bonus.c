/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_start_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:54:29 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/08 23:39:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "raycast_bonus.h"
#include "event_bonus.h"
#include "error_bonus.h"
#include "minimap_bonus.h"
#include "parse_bonus.h"

static void	set_dir_vector(t_ray_data *rdata, char c)
{
	if (c == 'E')
	{
		rdata->dir_x = 1;
		rdata->dir_y = 0;
	}
	else if (c == 'W')
	{
		rdata->dir_x = -1;
		rdata->dir_y = 0;
	}
	else if (c == 'S')
	{
		rdata->dir_x = 0;
		rdata->dir_y = 1;
	}
	else if (c == 'N')
	{
		rdata->dir_x = 0;
		rdata->dir_y = -1;
	}
}

static void	init_raycast_param(t_ray_data *rdata, t_map_data *map_data,
		t_raycast_param *raycast_param)
{
	ft_memset(rdata, 0, sizeof(t_ray_data));
	rdata->pos_x = (double)map_data->spawn[SPAWN_X] + 0.5;
	rdata->pos_y = (double)map_data->spawn[SPAWN_Y] + 0.5;
	raycast_param->sprite.pos_x = (double)map_data->sprite_pos[SPAWN_X] + 0.5;
	raycast_param->sprite.pos_y = (double)map_data->sprite_pos[SPAWN_Y] + 0.5;
	set_dir_vector(rdata, map_data->spawn[SPAWN_D]);
	rdata->plane_x = (-1) * rdata->dir_y * 0.66;
	rdata->plane_y = rdata->dir_x * 0.66;
	ft_memset(&raycast_param->key_state, 0, sizeof(t_key_state));
	ft_memset(raycast_param->tex_data, 0, 4 * sizeof(t_tex_data *));
}

static void	update_mouse(t_raycast_param *raycast_param)
{
	int	x;
	int	y;

	mlx_mouse_hide();
	mlx_mouse_get_pos(raycast_param->mlx_vars->win, &x, &y);
	if (x < WIDTH / 2)
		turn_left(raycast_param->rdata, ROTSPEED * 2);
	else if (x > WIDTH / 2)
		turn_right(raycast_param->rdata, ROTSPEED * 2);
	mlx_mouse_move(raycast_param->mlx_vars->win, WIDTH / 2, HEIGHT / 2);
}

static int	loop(t_raycast_param *raycast_param)
{
	update_mouse(raycast_param);
	move_player(&raycast_param->key_state, raycast_param->rdata, \
			raycast_param->map_data->map);
	raycast(raycast_param, raycast_param->rdata, \
			raycast_param->map_data, raycast_param->mlx_vars);
	put_minimap(raycast_param->mlx_vars, &raycast_param->minimap_img, \
			raycast_param->rdata, raycast_param->map_data);
	return (0);
}

void	play_start(t_map_data *map_data, t_mlx_vars *mlx_vars)
{
	t_raycast_param	raycast_param;
	t_ray_data		rdata;

	init_raycast_param(&rdata, map_data, &raycast_param);
	raycast_param.rdata = &rdata;
	raycast_param.map_data = map_data;
	raycast_param.mlx_vars = mlx_vars;
	init_mlx_and_img(mlx_vars);
	init_minimap_img(mlx_vars->mlx, &raycast_param.minimap_img);
	get_png_info(&raycast_param);
	mlx_hook(mlx_vars->win, KEY_PRESS, 0, press_key, &raycast_param);
	mlx_hook(mlx_vars->win, KEY_RELEASE, 0, release_key, &raycast_param);
	mlx_loop_hook(mlx_vars->mlx, loop, &raycast_param);
	mlx_loop(mlx_vars->mlx);
}
