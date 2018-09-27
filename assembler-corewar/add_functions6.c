/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:07:01 by alikhtor          #+#    #+#             */
/*   Updated: 2018/09/25 22:07:04 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

int			ft_create_file_dot_cor(char *old_path)
{
	char	*temp;
	char	*new_path;
	size_t	new_path_len;

	new_path_len = ft_strlen(old_path) + 2;
	new_path = ft_strnew(new_path_len);
	ft_strcpy(new_path, old_path);
	temp = new_path;
	new_path += new_path_len - 4;
	ft_strcpy(new_path, ".cor");
	new_path = temp;
	if ((g_fd = open(new_path, O_CREAT | O_TRUNC | O_WRONLY, 0777)) < 0)
		exit(1);
	ft_printf("Writing output program to %s\n", new_path);
	ft_strdel(&new_path);
	return (0);
}

void		ft_move_through_args_to_codage(t_asm *par)
{
	int		i;
	int		tmp_num;
	t_cmd	*tmp;

	i = 0;
	tmp_num = 0;
	tmp = par->cmd;
	while (tmp)
	{
		if (tmp->type_arg == 1)
			tmp_num = tmp_num | 64;
		else if (tmp->type_arg == 2)
			tmp_num = tmp_num | 192;
		else
			tmp_num = tmp_num | 128;
		tmp = tmp->next;
		if (tmp && ++i)
			tmp_num = tmp_num << 2;
	}
	while (i)
	{
		tmp_num = tmp_num >> 2;
		i--;
	}
	par->octal_codage = tmp_num;
}

void		ft_count_op_sum(t_asm *par)
{
	t_cmd	*temp_args;

	while (par)
	{
		if ((par->type | CMD) == CMD && par->opcode)
		{
			if (par->octal_codage != 0)
				par->size += 2;
			else
				par->size += 1;
			temp_args = par->cmd;
			while (temp_args)
			{
				par->size += temp_args->arg_size;
				temp_args = temp_args->next;
			}
		}
		par = par->next;
	}
}

int			ft_compare_labels(char *label_name, t_lbl *temp_label)
{
	while (temp_label)
	{
		if (ft_strequ(label_name, temp_label->name))
			return (1);
		temp_label = temp_label->next;
	}
	return (0);
}

int			ft_find_distance_size(t_asm *par, int position, int enter)
{
	int		i;
	int		result;
	int		roll_to;

	result = 0;
	roll_to = (enter < position) ? enter + 1 : position + 1;
	i = -1;
	while (par && ++i != roll_to)
		par = par->next;
	roll_to = (enter < position) ? position - enter : enter - position;
	i = -1;
	while (par && ++i < roll_to)
	{
		result += par->size;
		par = par->next;
	}
	if (enter > position)
		result *= -1;
	g_flag_nolbl = 0;
	return (result);
}
