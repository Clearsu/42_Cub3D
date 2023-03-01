/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:21:54 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 19:28:20 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "struct_bonus.h"

void	parse(t_map_data *map_data, \
		t_parse_data *parse_data, char *fname);
void	parse_map(t_map_data *map_data, t_list *token_list);
void	parse_tex_fname(char *tex_fname[5], t_list *token_list, int i);
void	parse_color(unsigned int color[2], t_list *token_list);
void	free_token_and_exit(t_token *token, t_err_type type);
void	check_invalid_char(t_list *buff_list);
void	check_map_order(t_list *token_list);
void	check_map_configuration(t_list *token_list);
void	basic_wall_check(t_map_data *map_data);
void	is_map_fully_closed(t_map_data *map_data);
void	check_spawn_location(t_map_data *map_data);
char	**calloc_2d_char_arr(size_t width, size_t height);

#endif
