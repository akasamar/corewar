/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 18:44:59 by alikhtor          #+#    #+#             */
/*   Updated: 2018/09/27 18:45:01 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "asm.h"

int			check_line_isalnum(char *line)
{
	int		count_alfa;
	int		i;

	count_alfa = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[0] == '\n')
			g_line_numb--;
		if (ft_strchr(LABEL_CHARS, line[i]))
			count_alfa++;
		i++;
	}
	if (!count_alfa)
		return (1);
	return (0);
}

void		shity_norms(t_asm **tmp, char **temp)
{
	if ((*tmp)->cmd && ((*tmp)->next = (t_asm*)ft_memalloc(sizeof(t_asm))))
		(*tmp) = (*tmp)->next;
	(*tmp)->label = get_labels(temp, (*tmp)->label);
}

void		shity_norms2(t_asm **tmp, char **temp)
{
	ft_get_opcode_and_name(tmp, *temp);
	ft_find_op_line_in_tab((*tmp)->val, temp);
}

t_asm		*get_data(t_asm *im_asm)
{
	t_asm	*tmp;
	char	*line;
	char	*temp;

	tmp = (t_asm*)ft_memalloc(sizeof(t_asm));
	while (get_next_line(g_fd, &line) && g_line_numb++)
	{
		if (check_line_isalnum(line))
		{
			ft_strdel(&line);
			continue;
		}
		if (prep_line(&line, &temp))
			break ;
		if (!im_asm)
			im_asm = tmp;
		if (label_name(temp))
			shity_norms(&tmp, &temp);
		if (tmp->cmd && (tmp->next = (t_asm*)ft_memalloc(sizeof(t_asm))))
			tmp = tmp->next;
		shity_norms2(&tmp, &temp);
		tmp->cmd = get_commands(temp, tmp);
		ft_strdel(&temp);
	}
	return (im_asm);
}

void		ft_asm(char *file, t_asm **im_asm)
{
	int		i;

	g_fd = open(file, O_RDONLY);
	i = ft_strlen(file);
	if (*file && file[--i] == 's')
		if (file[--i] != '.')
			error_print(error_manager_text(0), -42);
	i = ft_strlen(file);
	if (*file && file[--i] != 's')
		error_print(error_manager_text(0), -42);
	(*im_asm) = get_name_or_comment();
	(*im_asm)->next->next = get_data((*im_asm)->next->next);
	if (ft_codage_op_sum_labels(*im_asm))
		error_print(error_manager_text(0), -2);
	if (ft_create_file_dot_cor(file))
		error_print(error_manager_text(0), -3);
	ft_fill_cor_file(*im_asm);
}
