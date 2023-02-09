/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:21:54 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 23:53:15 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "struct.h"

void	parse(t_map_data *map_data, \
		t_parse_data *parse_data, char *fname);
void	parse_map(t_map_data *map_data, t_list *token_list);
void	parse_texture(char *texture[4], t_list *token_list);
void	parse_color(unsigned int color[2], t_list *token_list);
void	free_token_and_exit(t_token *token, t_err_type type);
void	check_invalid_char(t_list *buff_list);
void	check_map_order(t_list *token_list);
void	check_map_configuration(t_list *token_list);
char	**alloc_2d_char_arr(size_t width, size_t height);

#endif
