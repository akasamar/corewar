/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:25:52 by osapon            #+#    #+#             */
/*   Updated: 2018/09/23 16:25:56 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_operation(char *line)
{
	int		i;
	char	*tmp;

	tmp = ft_strnew(ft_strlen(line));
	i = 0;
	while (line[i] && (line[i] != LABEL_CHAR && line[i] != ' '))
	{
		tmp[i] = line[i];
		i++;
	}
	i = 0;
	while (i < 17)
	{
		if (ft_strequ(op_tab[i].op_name, tmp))
		{
			ft_strdel(&tmp);
			return (1);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}

int			label_name(char *temp)
{
	int		i;
	char	*tmp;

	if (is_operation(temp))
		return (0);
	tmp = ft_strchr(temp, ':');
	i = -1;
	if (tmp && *(tmp + 1) == '\0')
	{
		while (temp[++i] && temp[i] != ':')
			if (!ft_isalnum(*temp) && *temp != '_')
				error_print(error_manager_text(0), g_line_numb);
		return (1);
	}
	else if (tmp)
	{
		if (link_to_label(temp))
			return (0);
		while (temp[++i] && temp[i] != ':')
			if (!ft_strchr(LABEL_CHARS, temp[i]))
				error_print(error_manager_text(0), g_line_numb);
		return (1);
	}
	return (0);
}

int			check_for_op(char *temp)
{
	int		i;
	char	*line;

	if (!ft_isalnum(*temp) && *temp != '_')
		line = ft_trim(temp);
	else
		line = ft_strdup(temp);
	i = -1;
	while (g_operations[++i])
		if (ft_strnstr(line, g_operations[i], ft_strlen(g_operations[i])))
		{
			ft_strdel(&line);
			g_flag_op_lbl = 1;
			return (1);
		}
	ft_strdel(&line);
	return (0);
}

int			commands(char *temp)
{
	if (!*temp)
	{
		free(temp);
		return (2);
	}
	while (*temp != '\0')
	{
		if (check_for_op(temp))
			return (1);
		if (*temp == ':')
		{
			while (*temp)
			{
				temp++;
				if (!*temp)
					return (0);
				else if (*temp != ' ' && *temp != '\t')
					return (3);
			}
		}
		else if (!ft_isalnum(*temp) && *temp != '_')
			error_print(error_manager_text(0), g_line_numb);
		temp++;
	}
	return (0);
}

const char	*get_command_name(char *str)
{
	int		i;
	char	*tmp;

	tmp = ft_strdup(str);
	ft_strclr(&tmp[ft_strchr(tmp, ' ') - tmp]);
	i = -1;
	while (g_operations[++i])
		if (ft_strnstr(tmp, g_operations[i], ft_strlen(g_operations[i])))
		{
			ft_strdel(&tmp);
			return (g_operations[i]);
		}
	ft_strdel(&tmp);
	return (0);
}
