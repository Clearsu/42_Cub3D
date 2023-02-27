/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:58:59 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 19:41:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_BONUS_H
# define STATE_BONUS_H

void	start(t_state *state, t_parse_data *parse_data);
void	branch(t_state *state, t_parse_data *parse_data);
void	make_empty_token(t_state *state, t_parse_data *parse_data);
void	make_east_texture_token(t_state *state, t_parse_data *parse_data);
void	make_west_texture_token(t_state *state, t_parse_data *parse_data);
void	make_south_texture_token(t_state *state, t_parse_data *parse_data);
void	make_north_texture_token(t_state *state, t_parse_data *parse_data);
void	make_floor_color_token(t_state *state, t_parse_data *parse_data);
void	make_ceiling_color_token(t_state *state, t_parse_data *parse_data);
void	make_map_token(t_state *state, t_parse_data *parse_data);

#endif
