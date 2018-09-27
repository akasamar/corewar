/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:26:00 by osapon            #+#    #+#             */
/*   Updated: 2018/09/23 16:26:03 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_is_t_reg(char **op_line)
{
	int	r_num;
	int	r_flag;

	if (**op_line == SEPARATOR_CHAR)
		*op_line += 1;
	r_flag = 0;
	while (**op_line && **op_line != SEPARATOR_CHAR)
	{
		if (**op_line == 'r')
		{
			r_flag += 1;
			*op_line += 1;
			r_num = ft_atoi(*op_line);
			while (ft_isdigit(**op_line))
				*op_line += 1;
			if (r_num < 1 || r_num > 16)
				error_print(error_manager_text(12), g_line_numb);
		}
	}
	if (**op_line == SEPARATOR_CHAR)
		*op_line += 1;
	if (r_flag != 1)
		error_print(error_manager_text(12), g_line_numb);
}

void	ft_is_label_chars(char **op_line)
{
	while (**op_line && **op_line != SEPARATOR_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, **op_line))
			error_print(error_manager_text(11), g_line_numb);
		*op_line += 1;
	}
}

int		ft_is_num(char *op_line)
{
	int	step;

	step = 0;
	if (*op_line == '-')
	{
		op_line++;
		step++;
	}
	while (*op_line)
	{
		if (*op_line == SEPARATOR_CHAR)
			break ;
		if (!ft_isdigit(*op_line))
			error_print(error_manager_text(13), g_line_numb);
		step++;
		op_line++;
	}
	return (step);
}

void	ft_is_t_dir(char **op_line)
{
	int	dir_flag;

	dir_flag = 0;
	while (**op_line != SEPARATOR_CHAR && **op_line)
	{
		if (**op_line == DIRECT_CHAR || **op_line == LABEL_CHAR)
		{
			dir_flag += 1;
			if (**op_line == DIRECT_CHAR)
				*op_line += 1;
			if (**op_line == LABEL_CHAR)
			{
				*op_line += 1;
				ft_is_label_chars(op_line);
			}
			else
				*op_line += ft_is_num(*op_line);
		}
	}
	if (**op_line == SEPARATOR_CHAR)
		*op_line += 1;
	if (dir_flag != 1)
		error_print(error_manager_text(15), g_line_numb);
}

void	ft_is_t_reg_t_dir(char **op_line)
{
	if (**op_line == SEPARATOR_CHAR)
		*op_line += 1;
	if (**op_line == 'r')
		ft_is_t_reg(op_line);
	else if (**op_line == DIRECT_CHAR)
		ft_is_t_dir(op_line);
	else
		error_print(error_manager_text(15), g_line_numb);
}
