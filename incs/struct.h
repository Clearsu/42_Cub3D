/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/10 02:57:17 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "../libft/libft.h"
#include "define.h"

typedef struct	s_token
{
	t_state	type;
	void	*value;
}	t_token;

typedef struct	s_parse_data
{
	t_list	*buff_list;
	t_list	*token_list;
	t_list	*buff_now;
}	t_parse_data;

typedef struct	s_map_data
{
	char			*texture[4];
	unsigned int	color[2];
	char			**map;
	size_t			width;
	size_t			height;
}	t_map_data;

typedef void	(*t_state_fp)(t_state *state, t_parse_data *parse_data);

#endif
