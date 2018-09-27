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

void		shity_norms3(t_lbl **tmp, char **temp)
{
	while ((*tmp)->next)
		(*tmp) = (*tmp)->next;
	(*tmp)->next = (t_lbl *)ft_memalloc(sizeof(t_lbl));
	(*tmp)->next->name = ft_strsub(*temp, 0, ft_strchr(*temp, ':') - *temp);
	if (!g_flag_op_lbl)
		clear_label(temp);
	else
		ft_strdel(temp);
}

int			shity_norms4(char **temp)
{
	clear_label(temp);
	return (1);
}

void		shity_norms5(t_lbl **tmp, char **temp, t_lbl **im_asm)
{
	(*tmp) = (t_lbl*)ft_memalloc(sizeof(t_lbl));
	(*tmp)->name = ft_strsub(*temp, 0, ft_strchr(*temp, ':') - *temp);
	(*im_asm) = (*tmp);
}

int			shity_norms6(char **temp2, char **temp)
{
	(*temp2) = *temp;
	clear_comments(temp2);
	*temp = ft_strtrim(*temp2);
	ft_strdel(temp2);
	return (1);
}

t_lbl		*get_labels(char **temp, t_lbl *im_asm)
{
	t_lbl	*tmp;
	int		i;
	char	*temp2;

	shity_norms5(&tmp, temp, &im_asm);
	if (commands(*temp))
		if (shity_norms4(temp))
			return (tmp);
	ft_strdel(temp);
	while (get_next_line(g_fd, temp))
	{
		i = commands(*temp);
		if (i == 2)
			continue;
		g_line_numb++;
		if (i == 1)
			if (shity_norms6(&temp2, temp))
				break ;
		if (i == 3)
			break ;
		shity_norms3(&tmp, temp);
	}
	if (!g_flag_op_lbl)
		shity_norms3(&tmp, temp);
	return (im_asm);
}
