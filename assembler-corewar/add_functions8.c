/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:07:23 by alikhtor          #+#    #+#             */
/*   Updated: 2018/09/25 22:07:26 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				del_args(char *name, char **str)
{
	char			*tmp;
	unsigned int	i;

	i = ft_strlen(name);
	tmp = ft_strsub(*str, i, ft_strlen(*str) - i);
	ft_strcpy(*str, tmp);
	ft_strdel(&tmp);
}

int					find_type(char *arg)
{
	int				i;

	i = -1;
	while (++i < 17)
		if (ft_strequ(op_tab[i].op_name, arg))
			return (op_tab[i].label_size_two);
	return (0);
}

void				ft_temp(char **str, t_cmd **im_asm, char *arg)
{
	if (**str == 'r' || (**str == ',' && *(*str + 1) == 'r'))
	{
		(*im_asm)->type_arg = 1;
		(*im_asm)->arg_size = 1;
	}
	else if (**str == ':' || **str == '-')
	{
		(*im_asm)->type_arg = 2;
		(*im_asm)->arg_size = 2;
	}
	else if (**str == '%' || (**str == ',' && *(*str + 1) == '%'))
	{
		(*im_asm)->type_arg = (*(*str + 1) == ':') ? 4 : 3;
		(*im_asm)->arg_size = (find_type(arg) == 1) ? 2 : 4;
	}
	else if (**str == ',' && (ft_isdigit(*(*str + 1))
							|| *(*str + 1) == ':' || *(*str + 1) == '-'))
	{
		(*im_asm)->type_arg = 2;
		(*im_asm)->arg_size = 2;
		(*str)++;
	}
}

void				parse_command_part(char *str, t_cmd **im_asm, char *arg)
{
	int				i;
	char			*tmp;

	while (*str)
	{
		ft_temp(&str, im_asm, arg);
		ft_skip(&str);
		i = option_length(str);
		tmp = ft_strdup(str);
		i = assigning_option_values(tmp, i, im_asm);
		if (*str == ':')
			str++;
		ft_strdel(&tmp);
		str += i;
		if (*str && *str != ',')
			error_print(error_manager_text(0), g_line_numb);
		else
			break ;
	}
}

t_cmd				*get_commands(char *temp, t_asm *im_asm)
{
	t_cmd			*tmp;
	t_cmd			*tmp2;

	while (*temp)
	{
		if (im_asm->cmd)
		{
			tmp2 = im_asm->cmd;
			while (tmp)
				tmp = tmp->next;
			tmp = (t_cmd*)ft_memalloc(sizeof(t_cmd));
			parse_command_part(temp, &tmp, im_asm->val);
			while (tmp2->next)
				tmp2 = tmp2->next;
			tmp2->next = tmp;
		}
		else
		{
			tmp = (t_cmd*)ft_memalloc(sizeof(t_cmd));
			im_asm->cmd = tmp;
			parse_command_part(temp, &tmp, im_asm->val);
		}
		del_options(&temp);
	}
	return (im_asm->cmd);
}
