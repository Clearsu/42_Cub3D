/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:14:11 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 00:21:36 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "../libft/libft.h"
#include "defines.h"

typedef struct	s_token
{
	t_type	type;
	void	*value;
}

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
	char			*map;
	size_t			width;
	size_t			height;
}	t_map_data;

#endif
