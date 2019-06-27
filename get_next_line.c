/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:23:50 by bhugo             #+#    #+#             */
/*   Updated: 2019/06/27 20:19:41 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_list	*begin_tail;
	t_list				*tail;
	
	if (fd < 0 || fd > 10240 || *line == NULL)
		return (-1);
	if (begin_tail == NULL)
	{
		if ((tail = ft_memalloc(sizeof(*tail))) == NULL)
				return (-1);




	}
}
