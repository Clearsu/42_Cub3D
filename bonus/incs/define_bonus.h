/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:20:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/08 23:48:11 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_BONUS_H
# define DEFINE_BONUS_H

// rotate and move speed
# define ROTSPEED 0.02
# define MOVSPEED 0.03

// window width and height
# define WIDTH 1080
# define HEIGHT 720

// minimap
# define MINI_WIDTH 170
# define MINI_HEIGHT 170
# define MINI_WALL_COLOR 0x00777777
# define MINI_BACKGROUND_COLOR 0x88000000
# define MINI_PLAYER_COLOR 0x0000ff00
# define MINI_DOOR_COLOR 0x00ffffff
# define MINI_OFFSET 10
# define MINI_PLAYER_SIZE 10

// crosshair
# define CROSSHAIR_SIZE 15
# define CROSSHAIR_COLOR 0x00ffffff

// texture file paths
# define DOOR_TEXTURE_PATH "./textures/door.png"
# define SPRITE_TEXTURE_1 "./sprites/sealion1.png"
# define SPRITE_TEXTURE_2 "./sprites/sealion2.png"

# define TRUE 1
# define FALSE 0

# define STDERR_FILENO 2

// texture image index
# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3
# define DOOR 4

// floor and ceiling color index
# define FLOOR 0
# define CEILING 1

// values on the map for each factors
# define INSIDE 0
# define WALL 1
# define OUTSIDE 2
# define DOOR_CLOSED 5
# define DOOR_OPENED 6
# define ENEMY 7

// spawn information index
# define SPAWN_X 0
# define SPAWN_Y 1
# define SPAWN_D 2

// parsing
# define TOTAL_STATES 11

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

// error types
typedef enum e_err_type
{
	E_ARG_NUM,
	E_ARG_EXTENSION,
	E_MAP,
	E_SYS
}	t_err_type;

// keycodes
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define ESC 53
# define R_LEFT 123
# define R_RIGHT 124
# define UP 13
# define LEFT 0
# define RIGHT 2
# define DOWN 1
# define SPACEBAR 49

#endif
