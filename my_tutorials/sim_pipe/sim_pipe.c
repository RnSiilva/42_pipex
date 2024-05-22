/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 00:29:18 by resilva           #+#    #+#             */
/*   Updated: 2024/05/10 00:39:43 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void) {
	int	pfd[2];
	if (pipe(pfd) == -1)
		return (1);
	
	int pid1 = fork();
	if (pid1 == -1)
		return (2);
	if (pid1 == 0) {
		dup2(pfd[1], STDOUT_FILENO);
		close(pfd[0]);
		close(pfd[0]);
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}

	int	pid2 = fork();
	if (pid2 == -1)
		return (3);
	if (pid2 == 0) {
		dup2(pfd[0], STDIN_FILENO);
		close(pfd[0]);
		close(pfd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	
	close(pfd[0]);
	close(pfd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}