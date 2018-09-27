/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:22:41 by osapon            #+#    #+#             */
/*   Updated: 2018/08/30 21:13:20 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*get_of_spaces(char *line)
{
	char	*new;
	int		i;

	new = ft_strnew(ft_strlen(line) + 1);
	i = 0;
	while (*line)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		new[i] = *line;
		i++;
		line++;
	}
	return (new);
}

int			prep_line(char **line, char **temp)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	skip_empty_lines(line);
	if (*line == NULL)
		return (1);
	clear_comments(line);
	tmp = ft_trim(*line);
	if (ft_strchr(tmp, ':'))
	{
		i = -1;
		while (tmp[++i] && tmp[i] != ':')
			if (!is_operation(tmp))
				if (!ft_isalnum(tmp[i]) && tmp[i] != '_')
					error_print(error_manager_text(2), g_line_numb);
	}
	*temp = get_of_spaces(tmp);
	ft_strdel(&tmp);
	ft_strdel(line);
	return (0);
}

void		clear_label(char **str)
{
	char	*temp;

	clear_comments(str);
	temp = ft_strsub(*str, ft_strchr(*str, ':') - *str + 1,
			ft_strlen(*str) - (ft_strchr(*str, ':') - *str));
	ft_strdel(str);
	*str = ft_trim(temp);
	ft_strdel(&temp);
}

int			link_to_label(char *temp)
{
	while (*temp)
	{
		if (*temp == ':')
			return (0);
		if (*temp == '%' && *(temp + 1) == ':')
			return (1);
		temp++;
	}
	return (0);
}

void		skip_empty_lines(char **line)
{
	char	*tmp;

	if (*line && ((**line) == '\t' || (**line) == ' '))
	{
		tmp = ft_trim(*line);
		free(*line);
		*line = ft_strdup(tmp);
		free(tmp);
	}
	if ((*line) && ((**line) == '\0' || (**line) == '#'))
	{
		ft_strdel(line);
		while (get_next_line(g_fd, line))
		{
			tmp = ft_trim(*line);
			if (**line != '\0' && *tmp != '#')
			{
				ft_strdel(&tmp);
				break ;
			}
			ft_strdel(&tmp);
			g_line_numb++;
			ft_strdel(line);
		}
	}
}
