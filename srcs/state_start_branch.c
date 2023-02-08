/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_start_branch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:26:05 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 03:08:44 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incs/parse.h"
#include "../incs/define.h"

void	start(t_state *state, t_parse_data *parse_data)
{
	parse_data->token_list = NULL;
	parse_data->buff_now = parse_data->buff_list;
	*state = BRANCH;
	(void)parse_data;
}

int	is_only_map_char(char *str)
{
	while (*str != '\0' && (*str == '1' || *str == '0' || \
			  *str == 'E' || *str == 'W' || *str == 'S' || *str == 'N' || \
			  *str == ' '))
		str++;
	if (*str == '\n')
		str++;
	if (*str != '\0')
		return (FALSE);
	return (TRUE);
}

int	is_only_space_or_newline(char *str)
{
	while (*str && *str++ == ' ');
	while (*str && *str++ == '\n');
	if (*str != '\0')
		return (FALSE);
	return (TRUE);
}

void	branch(t_state *state, t_parse_data *parse_data)
{
	char	*str;

	str = (char *)parse_data->buff_now->content;
	if (is_only_space_or_newline(str))
		*state = EMPTY;
	else if (ft_strncmp("EA ", str, 3) == 0)
		*state = T_EAST;
	else if (ft_strncmp("WE ", str, 3) == 0)
		*state = T_WEST;
	else if (ft_strncmp("SO ", str, 3) == 0)
		*state = T_SOUTH;
	else if (ft_strncmp("NO ", str, 3) == 0)
		*state = T_NORTH;
	else if (ft_strncmp("F ", str, 2) == 0)
		*state = C_FLOOR;
	else if (ft_strncmp("C ", str, 2) == 0)
		*state = C_CEILING;
	else if (is_only_map_char(str))
		*state = MAP;
	else
		*state = FINISH;
}
