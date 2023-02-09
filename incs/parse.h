/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:21:54 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 20:35:50 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

void	parse_map_data(t_map_data *map_data, \
		t_parse_data *parse_data, char *fname);
void	free_token_and_exit(t_token *token, t_err_type type);
void	check_invalid_char(t_list *buff_list);
void	check_map_order(t_list *token_list);
void	check_map_configuration(t_list *token_list);

#endif
