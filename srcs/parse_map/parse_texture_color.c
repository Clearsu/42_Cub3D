/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:29:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/02/27 18:34:01 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "error.h"

static void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

void	parse_texture(char *texture[4], t_list *token_list)
{
	t_token	*token;

	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == T_EAST)
			texture[EAST] = ft_strdup((char *)token->value);
		else if (token->type == T_WEST)
			texture[WEST] = ft_strdup((char *)token->value);
		else if (token->type == T_SOUTH)
			texture[SOUTH] = ft_strdup((char *)token->value);
		else if (token->type == T_NORTH)
			texture[NORTH] = ft_strdup((char *)token->value);
		token_list = token_list->next;
	}
	if (!texture[EAST] || !texture[WEST] || !texture[SOUTH] || !texture[NORTH])
		print_err_and_exit(E_SYS);
}

static int	is_right_color_form(char *str)
{
	while (ft_isdigit(*str))
		str++;
	skip_spaces(&str);
	if (*str == ',')
		str++;
	skip_spaces(&str);
	while (ft_isdigit(*str))
		str++;
	skip_spaces(&str);
	if (*str == ',')
		str++;
	skip_spaces(&str);
	while (ft_isdigit(*str))
		str++;
	skip_spaces(&str);
	if (*str != '\0')
		return (FALSE);
	return (TRUE);
}

static unsigned int	get_color_value(char *str, int i)
{
	char			**str_split;
	unsigned int	cval;
	int				temp;

	if (!is_right_color_form(str))
		print_err_and_exit(E_MAP);
	str_split = ft_split(str, ',');
	if (!str_split)
		print_err_and_exit(E_SYS);
	cval = 0;
	while (str_split[++i])
	{
		temp = ft_atoi(str_split[i]);
		if (temp > 255)
		{
			ft_free2((void **)str_split);
			print_err_and_exit(E_MAP);
		}
		cval = (cval << 8) + temp;
	}
	ft_free2((void **)str_split);
	if (i != 3)
		print_err_and_exit(E_MAP);
	return (cval);
}

void	parse_color(unsigned int color[2], t_list *token_list)
{
	t_token	*token;

	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == C_FLOOR)
			color[FLOOR] = get_color_value((char *)token->value, -1);
		else if (token->type == C_CEILING)
			color[CEILING] = get_color_value((char *)token->value, -1);
		token_list = token_list->next;
	}
}
