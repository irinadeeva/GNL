/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:37:32 by bhugo             #+#    #+#             */
/*   Updated: 2019/06/25 19:01:48 by bhugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int		main (int argc, char **argv)
{
	int fd;
	char *line;
	int i;

	if (argc == 1)
		printf("no file as an argument");
	else
	i = 1;
		while (i < argc)
		{
			if ((fd = open(argv[i], R_ONLY)) != -1)
			{
				while (get_next_line(fd,*line) == 1)
				{
					ft_putendl(line);
					free(line);
				}
			}
			i++;
		}
	return (0);
}
