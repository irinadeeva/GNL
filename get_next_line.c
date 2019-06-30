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

int 	ft_drobilka(char *buff, char *line, char *content)
{
	char 			*tmp;
	char			*tmp_freedom;

	if (tmp = ft_strchr(buff, '\n') == NULL)
	{
		tmp_freedom = content;
		content = ft_strjoin(content, buff);
		free(tmp_freedom);
		return (0);
	}
	else
	line = ft_strsub(buff, 0, tmp - buff);
	tmp_freedom = content;
	content = ft_strjoin(content, tmp);
	free(tmp_freedom);
	return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*begin_tail;
	t_list			*tail;
	char 			*buff[BUFFSIZE + 1];
	char            *content;
	int             read_result;
	
	
	if (fd < 0 || fd > 10240 || *line == NULL)
		return (-1);
	if (begin_tail == NULL)
	{
		ft_lstadd(*begin_tail, ft_lstnew('', fd));
	}
	begin_tail = begin_tail->next;
	content = begin_tail->content;
	while ((read_result = read(fd,buff, BUFFSIZE)) > 0)
	{
		buff[read_result] = '\0';
		if (ft_drobilka(buff, line, content) == 1)
			break;	
	}








	if (begin_tail != NULL)
	{
		begin_tail = begin_tail->next;
		while (begin_tail->content_size != fd || begin_tail->next != NULL)
			begin_tail = begin_tail->next;
		if (fd == begin_tail->content_size)
			ft_lstadd(ft_lstnew('\0', fd),  )
					// как создать новый лист, если мы заняли предыдущий хвостом, 
		//и если мы работаем с множествнным дискрипторам сколько листов запланировать я не знаю
		// получается надо на ходу новые стряпать / круто / только разве я так умею 
		else
		ft_strchr(tail->content,'\n');
	if (begin_tail == NULL)
	{
		if ((tail = ft_lstnew('\0', fd) == NULL)
				return (-1);
		ft_lstadd(tail, begin_tail);
	}
	
	
}
