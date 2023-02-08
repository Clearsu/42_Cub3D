/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:20:25 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/08 20:38:02 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

#define STDERR_FILENO 2

typedef enum e_err_type
{
	E_ARG_NUM,
	E_ARG_EXTENSION,
	E_MAP,
	E_SYS
}	t_err_type;
