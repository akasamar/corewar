/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlogin <xlogin@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:06:00 by xlogin            #+#    #+#             */
/*   Updated: 2018/03/08 11:06:00 by xlogin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char space)
{
	if (space == ' ' || space == '\n' || space == '\t' ||
			space == '\r' || space == '\b' || space == '\v' || space == '\f')
		return (1);
	else
		return (0);
}
