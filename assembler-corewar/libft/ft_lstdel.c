/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:31:47 by osapon            #+#    #+#             */
/*   Updated: 2017/11/11 14:31:53 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*buf;
	t_list		*list;

	list = *alst;
	while (list)
	{
		buf = list;
		del((buf->content), buf->content_size);
		free(buf);
		list = list->next;
	}
	*alst = NULL;
}
