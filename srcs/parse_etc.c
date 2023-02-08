/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_etc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 03:18:05 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/09 03:19:33 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_token_and_exit(t_token *token, t_err_type err_type)
{
	free(token);
	print_err_and_exit(type);
}
