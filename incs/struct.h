/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/11 22:49:47 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../libft/libft.h"
# include "define.h"

typedef struct s_token
{
	t_state	type;
	void	*value;
}	t_token;

typedef struct s_parse_data
{
	t_list	*buff_list;
	t_list	*token_list;
	t_list	*buff_now;
}	t_parse_data;

typedef struct s_map_data
{
	char			*texture[4];
	unsigned int	color[2];
	char			**map;
	size_t			width;
	size_t			height;
	size_t			spawn[3];
}	t_map_data;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_mlx_vars
{
	void		*mlx;
	void		*win;
	t_img_data	img_data;
}	t_mlx_vars;

typedef struct s_player_data
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time_curr;
	double	time_old;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_player_data;

typedef struct s_raycast_param
{
	t_player_data	*pdata;
	t_map_data		*map_data;
}	t_raycast_param;

typedef void	(*t_state_fp)(t_state *state, t_parse_data *parse_data);

#endif
