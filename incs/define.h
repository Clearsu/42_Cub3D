/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:20:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/23 15:29:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define ROTSPEED 0.02
# define MOVSPEED 0.03

# define WIDTH 1080
# define HEIGHT 720

# define TRUE 1
# define FALSE 0

# define STDERR_FILENO 2

# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3

# define FLOOR 0
# define CEILING 1

# define INSIDE 0
# define WALL 1
# define OUTSIDE 2

# define SPAWN_X 0
# define SPAWN_Y 1
# define SPAWN_D 2

# define TOTAL_STATES 11

# define EAST_COLOR 0x00ff0000
# define WEST_COLOR 0x0000ff00
# define SOUTH_COLOR 0x000000ff
# define NORTH_COLOR 0x00800080

typedef enum e_state
{
	START,
	BRANCH,
	EMPTY,
	T_EAST,
	T_WEST,
	T_SOUTH,
	T_NORTH,
	C_FLOOR,
	C_CEILING,
	MAP,
	FINISH
}	t_state;

typedef enum e_err_type
{
	E_ARG_NUM,
	E_ARG_EXTENSION,
	E_MAP,
	E_SYS
}	t_err_type;

# define ESC 53
# define R_LEFT 123
# define R_RIGHT 124
# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1

# define KEY_PRESS 2
# define KEY_RELEASE 3

#endif
