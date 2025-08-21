/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhusquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:22:01 by xhusquin          #+#    #+#             */
/*   Updated: 2025/08/21 20:26:12 by xhusquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../get_next_line_bonus.h"
#define NB_FILES 3

char	*get_next_line(int fd);

int	main(void)
{
	int	finished;
	int	fd[NB_FILES];
	char	*filename[NB_FILES] = {"smil1.txt", "smil2.txt", "smil3.txt"};
	char	command[256];
	char	*line[NB_FILES];
	int	i;

	i = 0;
	while (i < NB_FILES)
	{
		printf("\n\033[37;44mResults from cat -En command:%s\033[0m\n\n", filename[i]);
		sprintf(command, "cat -En %s; echo \n\n\n", filename[i]);
		system(command);
		i++;
	}
	printf("\033[37;44mResults from Get_Next_Line:\033[0m\n\n");
	i = 0;
	while (i < NB_FILES)
	{
		fd[i] = open(filename[i], O_RDONLY);
		i++;
	}
	finished = 0;
	while (!finished)
	{
		finished = 1;
		i = 0;
		while (i < NB_FILES)
		{
			line[i] = get_next_line(fd[i]);
			if (line[i])
			{
				printf("\033[32m[fd%d]\t\033[93m%s\033[31m$\033[0m", i + 1, line[i]);
				free(line[i]);
				finished = 0;
			}
			i++;
		}
	}
	i = 0;
	while (i < NB_FILES)
	{
		close(fd[i]);
		i++;
	}
	return (0);
}

