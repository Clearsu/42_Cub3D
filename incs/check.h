/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:11:49 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/08 20:37:03 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKING_H
# define CHECKING_H

#include "../libft/libft.h"

void	check_arg(int argc, char **argv);
void	check_map(t_list **buff_lst, char *fname);

#endif
