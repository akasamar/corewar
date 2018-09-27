/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <osapon@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:17:50 by osapon            #+#    #+#             */
/*   Updated: 2018/08/19 16:21:43 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_check_args_amount(t_op tab, char *op_line)
{
	int		separator_count;

	separator_count = 1;
	while (*op_line)
	{
		if (*op_line == SEPARATOR_CHAR)
			separator_count++;
		op_line++;
	}
	if (separator_count != tab.args_amount)
		error_print(error_manager_text(5), g_line_numb);
}

char		*check_name_line(char *tmp, int type)
{
	int		sign;

	sign = -1;
	while (++sign < type)
		tmp++;
	while (*tmp && (*tmp == ' ' || *tmp == '\t'))
		tmp++;
	if (*tmp != '"')
		error_print(error_manager_text(1), g_line_numb);
	return (ft_strdup(tmp));
}

int			fst(char *line)
{
	if (ft_strstr(line, ".name"))
		return (1);
	else if (ft_strstr(line, ".comment"))
		return (0);
	return (42);
}

int			is_full(char *line, int *sign)
{
	while (*line)
	{
		if (*(line) == '"')
			(*sign)++;
		line++;
	}
	if ((*sign) == 2)
		return (1);
	else if ((*sign) > 2)
		error_print(error_manager_text(1), g_line_numb);
	return (0);
}

char		*get_name_comment(char **line, int *sign)
{
	size_t	i;
	char	*tmp;
	char	*name;
	char	*bucket;

	bucket = NULL;
	if ((*sign) == 2)
		clear_comments(line);
	tmp = ft_trim(*line);
	if (tmp[0] != '.')
		error_print(error_manager_text(1), g_line_numb);
	ft_strdel(line);
	if ((i = fst(tmp)) != 42)
		bucket = check_name_line(tmp, (fst(tmp) == 1) ? 5 : 8);
	if (i == 42)
		error_print(error_manager_text(1), g_line_numb);
	i = ft_strlen(&bucket[1]);
	name = ft_memalloc(i);
	ft_strncpy(name, &bucket[1], i);
	ft_strdel(&bucket);
	ft_strdel(&tmp);
	return (name);
}
