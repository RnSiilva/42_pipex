/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:59:33 by resilva           #+#    #+#             */
/*   Updated: 2024/04/29 22:43:47 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	
	if (pid == 0){
		// Child process
		
		int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1) {
			printf("Could not find program to execute!\n");
			return (2);
		}
	} else {
		// Parent process
		int wstatus;
		wait(&wstatus);
		printf("\n");
		if (WIFEXITED(wstatus)) {
			int	statusCode = WEXITSTATUS(wstatus);
			if (statusCode == 0)
				printf("Sucess!\n"); 
			else
				printf("Failure with status code %d\n", statusCode);
		}
		
		printf("Some post processing goes here!\n");
	}
	
	return (0);
}