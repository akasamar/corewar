/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:07:14 by alikhtor          #+#    #+#             */
/*   Updated: 2018/09/25 22:07:18 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void				ft_fill_name_or_comment(t_asm *par, int size)
{
	char			*temp;
	int				null;
	int				i;

	temp = par->val;
	null = 0;
	i = 0;
	while (i < size)
	{
		if (*temp)
		{
			write(g_fd, temp, 1);
			temp++;
		}
		else
			write(g_fd, &null, 1);
		i++;
	}
}

unsigned int		bit_magic(int enter_num, size_t size)
{
	unsigned int	rev_num;
	unsigned int	num;
	unsigned char	*n1;
	unsigned char	*n2;

	num = (unsigned int)enter_num;
	n1 = (unsigned char *)&num;
	n2 = (unsigned char *)&rev_num;
	if (size <= 2)
	{
		n2[0] = n1[1];
		n2[1] = n1[0];
	}
	else
	{
		n2[0] = n1[3];
		n2[1] = n1[2];
		n2[2] = n1[1];
		n2[3] = n1[0];
	}
	if (size == 1)
		return (num);
	else
		return (rev_num);
}

void				ft_fill_total_size(t_asm *par)
{
	int				result;
	unsigned int	final_size;

	result = 0;
	while (par)
	{
		if ((par->type | CMD) == CMD)
			result += par->size;
		par = par->next;
	}
	final_size = bit_magic(result, 4);
	write(g_fd, &final_size, 4);
}

void				ft_fill_body(t_asm *par)
{
	t_cmd			*temp_args;
	unsigned int	temp_value;

	while (par)
	{
		if ((par->type | CMD) == CMD && par->opcode)
		{
			write(g_fd, &par->opcode, 1);
			if (par->octal_codage)
				write(g_fd, &par->octal_codage, 1);
			temp_args = par->cmd;
			while (temp_args)
			{
				temp_value = bit_magic(temp_args->value, temp_args->arg_size);
				write(g_fd, &temp_value, temp_args->arg_size);
				temp_args = temp_args->next;
			}
		}
		par = par->next;
	}
}

void				ft_fill_cor_file(t_asm *par)
{
	unsigned int	null;

	null = 0;
	ft_fill_magic_header();
	ft_fill_name_or_comment(par, PROG_NAME_LENGTH);
	write(g_fd, &null, 4);
	ft_fill_total_size(par);
	par = par->next;
	ft_fill_name_or_comment(par, COMMENT_LENGTH);
	write(g_fd, &null, 4);
	par = par->next;
	ft_fill_body(par);
}
