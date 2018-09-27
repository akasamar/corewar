/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osapon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:35:15 by osapon            #+#    #+#             */
/*   Updated: 2017/11/10 19:01:39 by osapon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*xy;

	xy = (t_list*)malloc(sizeof(t_list));
	if (!xy)
		return (NULL);
	xy->next = NULL;
	if (!content)
	{
		xy->content = NULL;
		xy->content_size = 0;
		return (xy);
	}
	xy->content = ft_voiddup(content, content_size);
	if (!(xy->content))
	{
		free(xy);
		return (NULL);
	}
	xy->content_size = content_size;
	return (xy);
}
