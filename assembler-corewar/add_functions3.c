/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:25:31 by osapon            #+#    #+#             */
/*   Updated: 2018/09/23 16:25:47 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_link_to_label_size(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	return (i);
}

void		del_options(char **str)
{
	char	*temp;
	int		i;

	temp = *str;
	i = 0;
	if (*temp && *temp == ',')
	{
		temp++;
		i++;
	}
	while (*temp && *temp != ',')
	{
		temp++;
		i++;
	}
	i = (*temp == '\0') ? i : ft_strlen(temp);
	ft_strncpy(str[0], temp, i);
	ft_bzero(&(str[0][i]), i);
}

void		ft_skip(char **str)
{
	if (**str == 'r' && !ft_isdigit(*(*str + 1)))
		return ;
	while (**str == ' ' || **str == '\t' || **str == ',' || **str == 'r'
			|| (**str == '%' && (*(*str + 1) == ':' || *(*str + 1) == '-'
			|| ft_isdigit(*(*str + 1)))))
		(*str)++;
}

int			option_length(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] && (ft_isdigit(str[i])))
		i++;
	return (i);
}

int			assigning_option_values(char *str, int i, t_cmd **im_asm)
{
	if (*str == 'r' && !ft_isdigit(*(str + 1)) &&
		(i = ft_link_to_label_size(str)) > 0)
		(*im_asm)->name = ft_strsub(str, 0, (size_t)i);
	if (*str == '-' || ft_isdigit(*str)
		|| (*str == ':' && ft_isdigit(*(str + 1))))
		(*im_asm)->value |= ft_atoi(str);
	if (*str == ':')
	{
		str++;
		i = ft_link_to_label_size(str);
		if (i > 0)
			(*im_asm)->name = ft_strsub(str, 0, (size_t)(i));
	}
	return (i);
}
