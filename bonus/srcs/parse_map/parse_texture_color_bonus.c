/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_color_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:29:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/01 19:28:50 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_bonus.h"
#include "error_bonus.h"

static void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

void	parse_tex_fname(char *tex_fname[5], t_list *token_list, int i)
{
	t_token	*token;

	while (token_list)
	{
		token = (t_token *)token_list->content;
		if (token->type == T_EAST)
			tex_fname[EAST] = ft_strdup((char *)token->value);
		else if (token->type == T_WEST)
			tex_fname[WEST] = ft_strdup((char *)token->value);
		else if (token->type == T_SOUTH)
			tex_fname[SOUTH] = ft_strdup((char *)token->value);
		else if (token->type == T_NORTH)
			tex_fname[NORTH] = ft_strdup((char *)token->value);
		token_list = token_list->next;
	}
	if (!tex_fname[EAST] || !tex_fname[WEST] || !tex_fname[SOUTH] || !tex_fname[NORTH])
	{
		while (i < 4)
		{
			if (tex_fname[i])
				free(tex_fname[i++]);
		}
		print_err_and_exit(E_SYS);
	}
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
