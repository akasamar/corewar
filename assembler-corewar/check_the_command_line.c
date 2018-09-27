/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_command_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:35:09 by alikhtor          #+#    #+#             */
/*   Updated: 2018/09/12 14:35:11 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_is_t_ind(char **op_line)
{
	if (**op_line == DIRECT_CHAR || **op_line == LABEL_CHAR)
		ft_is_t_dir(op_line);
	else
		*op_line += ft_is_num(*op_line);
}

void		ft_is_t_reg_t_ind(char **op_line)
{
	if (**op_line == 'r')
		ft_is_t_reg(op_line);
	else
		ft_is_t_ind(op_line);
}

void		ft_is_t_reg_t_dir_t_ind(char **op_line)
{
	if (**op_line == 'r')
		ft_is_t_reg(op_line);
	else if (**op_line == DIRECT_CHAR || **op_line == LABEL_CHAR)
		ft_is_t_dir(op_line);
	else
	{
		*op_line += ft_is_num(*op_line);
		if (**op_line == ',')
			*op_line += 1;
	}
}

void		ft_check_args_type(t_op tab, char *op_line)
{
	int		i;

	i = -1;
	while (++i < tab.args_amount)
	{
		if (tab.args_sum[i] == 1)
			ft_is_t_reg(&op_line);
		else if (tab.args_sum[i] == 2)
			ft_is_t_dir(&op_line);
		else if (tab.args_sum[i] == 4)
			ft_is_t_ind(&op_line);
		else if (tab.args_sum[i] == 3)
			ft_is_t_reg_t_dir(&op_line);
		else if (tab.args_sum[i] == 5)
			ft_is_t_reg_t_ind(&op_line);
		else if (tab.args_sum[i] == 6)
			ft_is_t_ind(&op_line);
		else if (tab.args_sum[i] == 7)
			ft_is_t_reg_t_dir_t_ind(&op_line);
		else
			exit(0);
	}
}

void		ft_find_op_line_in_tab(char *op, char **op_line)
{
	int		i;
	char	*temp;

	del_args(op, op_line);
	if (ft_strchr(*op_line, ' '))
	{
		temp = ft_strdup(*op_line);
		ft_strdel(op_line);
		*op_line = get_of_spaces(temp);
		ft_strdel(&temp);
	}
	i = -1;
	while (++i < 17)
	{
		if (ft_strequ(op, op_tab[i].op_name))
		{
			ft_check_args_amount(op_tab[i], *op_line);
			ft_check_args_type(op_tab[i], *op_line);
			break ;
		}
	}
}
