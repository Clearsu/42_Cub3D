/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:20:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 20:58:56 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

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

#endif
