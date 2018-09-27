/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:21:47 by osapon            #+#    #+#             */
/*   Updated: 2018/08/21 20:17:56 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*error_manager_text(int index)
{
	char	*errors[20];

	errors[0] = "Invalid file name :(\n";
	errors[1] = "Invalid \".name\" or \".comment\" line my friend :(\n";
	errors[2] = "It's bad line dude :(\n";
	errors[3] = "It's bad \"label\" name :(\n";
	errors[4] = "It's bad \"operation\" name :(\n";
	errors[5] = "Arguments are badly separated! :(\n";
	errors[6] = "The argument is not valid! :(\n";
	errors[7] = "Invalid \".name\" line my friend :(\n";
	errors[8] = "It's bad \".comment\" line dude :(\n";
	errors[9] = "It's bad \"label\" name :(\n";
	errors[10] = "It's bad \"operation\" name :(\n";
	errors[11] = "Wrong chars in label name in argument! :(\n";
	errors[12] = "A mistake in T_REG type argument! :(\n";
	errors[13] = "A mistake in T_IND type argument! :(\n";
	errors[14] = "A mistake in T_DIR type argument! :(\n";
	errors[15] = "A mistake in a some type argument! :(\n";
	return (errors[index]);
}

void		error_print(char *text, int line)
{
	if (line == -1)
		ft_printf("%s\n", text);
	if (line == -42)
		ft_printf("%s", text);
	else
		ft_printf("%s\n Check line: %d\n", text, line);
	exit(0);
}

char		*ft_trim(char *src)
{
	char	*tmp;
	size_t	i;

	while (*src == ' ' || *src == '\t')
		src++;
	i = ft_strlen(src);
	if (i == 0)
		return (ft_strnew(0));
	i--;
	while (src[i] == ' ' || src[i] == '\t')
		i--;
	tmp = (char*)ft_memalloc(i + 1);
	ft_strncpy(tmp, src, i + 1);
	if (tmp[ft_strlen(tmp) - 1] == '"')
		tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

void		clear_comments(char **str)
{
	size_t	i;

	if (!ft_strchr(*str, '#') && !ft_strchr(*str, ';'))
		return ;
	i = ft_strlen(*str);
	while ((*str)[--i])
		if ((*str)[i] == '#' || (*str)[i] == ';' || (*str)[i] == '"')
			break ;
	i++;
	ft_bzero(&(*str)[i], ft_strlen(&(*str)[i]));
	if ((*str)[ft_strlen(*str) - 1] == '#')
		(*str)[ft_strlen(*str) - 1] = '\0';
}

void		trim_end_spaces(char **name)
{
	size_t	i;

	i = ft_strlen(*name);
	while ((*name)[--i])
	{
		if ((*name)[i] == '"')
			break ;
		else if ((*name)[i] != ' ' && (*name)[i] != '\t')
			error_print(error_manager_text(1), g_line_numb);
	}
	(*name)[i] = '\0';
}
