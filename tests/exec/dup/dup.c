/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:56:44 by resilva           #+#    #+#             */
/*   Updated: 2024/04/30 00:16:45 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int	main(void)
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	
	if (pid == 0) {
		// Child process
		int file = open("pingResult.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		
		printf("The fd to pingResult: %d\n", file);
		int file2 = dup2(file, STDOUT_FILENO);
		printf("The diplicated fd: %d\n\n", file2);
		close(file);
		
		int err = execlp("ping2", "ping", "-c", "3", "google.com", NULL);
		if (err == -1) {
			printf("Could not find program to execute!\n");
			return (3);
		}
	} else {
		// Parent process
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus)) {
			int statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Sucesss!\n");
			else
				printf("Failure with status code: %d\n", statusCode);
		}
	}
}