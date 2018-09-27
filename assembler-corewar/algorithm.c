/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:26:30 by osapon            #+#    #+#             */
/*   Updated: 2018/09/23 16:26:47 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

void		ft_check_flag_nolbl(void)
{
	if (g_flag_nolbl == 1)
	{
		ft_printf("NOLABEL!\n");
		exit(0);
	}
}

void		ft_find_distance_to_label(t_cmd *args, t_asm *head, int enter)
{
	int		position;
	t_asm	*par;

	while (args)
	{
		if (args->name != NULL)
		{
			position = 0;
			g_flag_nolbl = 1;
			par = head;
			while (par)
			{
				if ((par->type | CMD) == CMD)
					position++;
				if (ft_compare_labels(args->name, par->label))
				{
					args->value = ft_find_distance_size(head, position, enter);
					ft_strdel(&args->name);
				}
				par = par->next;
			}
			ft_check_flag_nolbl();
		}
		args = args->next;
	}
}

int			ft_check_labels(t_asm *par)
{
	t_asm	*head;
	int		enter_position;

	enter_position = 0;
	head = par;
	while (par)
	{
		if ((par->type | CMD) == CMD)
			enter_position++;
		if (par->flabel)
		{
			g_flag_nolbl = 1;
			ft_find_distance_to_label(par->cmd, head, enter_position);
		}
		par = par->next;
	}
	return (0);
}

int			ft_codage_op_sum_labels(t_asm *par)
{
	t_asm	*par_head;

	par_head = par;
	while (par)
	{
		if (par->octal_codage == 1)
		{
			par->octal_codage = 0;
			ft_move_through_args_to_codage(par);
		}
		par = par->next;
	}
	par = par_head;
	ft_count_op_sum(par);
	par = par_head;
	return (ft_check_labels(par));
}

void		ft_fill_magic_header(void)
{
	int		header;

	header = 0xf383ea << 8;
	write(g_fd, &header, 4);
}
