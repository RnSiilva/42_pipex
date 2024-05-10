/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:41:10 by resilva           #+#    #+#             */
/*   Updated: 2024/05/10 01:22:13 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

// incomplete
int	main(int ac, char **av)
{
	if (ac != 5)
		return (printf("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2"));
	
	char	*cmd1 = split(av[2], );
	
	char	*cmd2 = av[3];
	
	int	fd[2];
	if (pipe(fd) == -1)
		return (1);

	
	int	pid1 = fork();
	if (pid1 == -1)
		return (2);
	if (pid1 == 0) {
		int	fd_in;
		fd_in = open(av[1], O_RDONLY, 0777);
		
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd_in, STDIN_FILENO);
		close (fd[0]);
		close (fd[1]);
		
		execlp(cmd1, cmd1, NULL, NULL);
	}

	int	pid2 = fork();
	if (pid2 == -1)
		return (3);
	if (pid2 == 0) {
		int	fd_out;
		fd_out = open(av[4], O_WRONLY, 0777);
		
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], fd_out);

		execlp(cmd2, cmd2, NULL, NULL);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}