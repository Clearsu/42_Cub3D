/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:15:46 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/08 20:36:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/check.h"
#include "../incs/struct.h"

int	main(int argc, char **argv)
{
	t_mapdata	map;

	check_arg(argc, argv);
	check_map(&map.buff_lst, argv[1]);
	return (0);
}
