/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:44:59 by alikhtor          #+#    #+#             */
/*   Updated: 2018/09/27 18:45:01 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_get_opcode_and_name(t_asm **tmp, char *temp)
{
	int		i;

	i = 0;
	(*tmp)->type |= CMD;
	(*tmp)->val = ft_strsub(temp, 0, ft_strlen(get_command_name(temp)));
	while (i < 17)
	{
		if (ft_strequ(op_tab[i].op_name, (*tmp)->val))
		{
			(*tmp)->opcode = op_tab[i].opcode;
			(*tmp)->octal_codage = op_tab[i].octal_codage;
			break ;
		}
		i++;
	}
	if (ft_strchr(temp, ':'))
		(*tmp)->flabel = 1;
}
