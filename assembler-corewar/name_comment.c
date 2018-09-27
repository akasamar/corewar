/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 15:50:42 by osapon            #+#    #+#             */
/*   Updated: 2018/08/19 16:17:46 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_quote_sign(char *tmp, int *sign)
{
	size_t	i;

	i = -1;
	while (tmp[++i])
		if (tmp[i] == '"')
			(*sign)++;
}

int			ft_get_last_line(char **tmp, char **line, char **name)
{
	*name = ft_strjoin(*tmp, "\n");
	*name = ft_strjoin(*tmp, ((*line)[0] == '\0'
							&& g_line_numb++) ? "\n" : (*line));
	ft_strdel(tmp);
	ft_strdel(line);
	return (0);
}

char		*get_all_parts_name_comment(char **line, int *sign)
{
	char	*name;
	char	*tmp;

	name = get_name_comment(line, sign);
	name[ft_strlen(name)] = '\n';
	while (get_next_line(g_fd, line) && g_line_numb++)
	{
		check_quote_sign(*line, sign);
		tmp = name;
		if ((*sign) == 2 && !ft_get_last_line(&tmp, line, &name))
			break ;
		name = ft_strjoin(tmp,
				((*line)[0] == '\0' && g_line_numb++) ? "\n" : (*line));
		ft_strdel(&tmp);
		ft_strdel(line);
		if ((*sign) > 2)
			error_print(error_manager_text(1), g_line_numb);
	}
	clear_comments(&name);
	trim_end_spaces(&name);
	return (name);
}

t_asm		*name_comment(char **line, t_asm *main)
{
	int		sign;

	if (!main->type)
	{
		main->type = (ft_strstr(*line, ".name")) ? N_E : C_T;
		sign = 0;
		main->val = (is_full(*line, &sign)) ? get_name_comment(line, &sign)
									: get_all_parts_name_comment(line, &sign);
	}
	else
	{
		main->next = (t_asm*)ft_memalloc(sizeof(t_asm));
		main->next->type = (ft_strstr(*line, ".name")) ? N_E : C_T;
		sign = 0;
		main->next->val = (is_full(*line, &sign))
						? get_name_comment(line, &sign)
						: get_all_parts_name_comment(line, &sign);
	}
	return (main);
}

t_asm		*get_name_or_comment(void)
{
	char	*line;
	int		i;
	t_asm	*im_asm;

	i = -1;
	im_asm = (t_asm*)ft_memalloc(sizeof(t_asm));
	while (++i < 2 && get_next_line(g_fd, &line))
	{
		g_line_numb++;
		skip_empty_lines(&line);
		if (i < 2)
			im_asm = name_comment(&line, im_asm);
		else
			break ;
	}
	return (im_asm);
}
