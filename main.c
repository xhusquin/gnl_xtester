/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhusquin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:22:01 by xhusquin          #+#    #+#             */
/*   Updated: 2025/08/21 20:02:17 by xhusquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../get_next_line.h"

char	*get_next_line(int fd);

int	main(int argc, char **argv)
{
	int	number_line;
	int	fd;
	char	*filename;
	char	command[256];
	char	*line;

	if (argc > 2)
		return (printf("\033[33m!!! Wrong number of arguments !!!\033[0m\n"), 1);
	if (argc == 1)
		filename = "test.txt";
	else
		filename = argv[1];
	printf("\n\033[37;44mResults from cat -En command:\033[0m\n\n");
	sprintf(command, "cat -En %s; echo \n\n\n", filename);
	system(command);
	printf("\033[37;44mResults from Get_Next_Line:\033[0m\n\n");
	printf("buffer: %d\n\n", BUFFER_SIZE);
//	fd = 1;
	fd = open(filename, O_RDONLY);
	number_line = 1;
	while ( number_line < 1024 )
	{
		line = get_next_line(fd);
		printf("\033[32m[%d]\t\033[0m%s\033[31m$\033[0m", number_line, line);
		if (!line)
		{
			free(line);
			printf("\n\nNumber of lines: %d\n\n", number_line -1);
			close(fd);
			return (0);
		}
		free(line);
		number_line++;
	}
	printf("\n\033[33m !!! DID NOT REACH END OF FILE !!!\n(Max line number is set to 1024 by default, check main to change it)\033[0m\n\n");
	free(line);
	close(fd);
	return (0);
}
