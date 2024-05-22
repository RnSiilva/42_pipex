/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigusr1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:07:39 by resilva           #+#    #+#             */
/*   Updated: 2024/05/08 19:33:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int	x = 0;

void	handle_sigusr1(int sig) {
	if (x == 0)
		printf("(HINT) Remember that multiplication is repetitive addition\n");
}

int	main(void) {
	int	pid = fork();
	if (pid == -1)
		return (1);
	
	if (pid == 0) {
		sleep(5);
		kill(getppid(), SIGUSR1);	
	} else {
		struct sigaction sa = { 0 };
		sa.sa_handler = &handle_sigusr1;
		sa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sa, NULL); 

		printf("What the result of 5 x 3?\n");
		scanf("%d", &x);
		if (x == 15){
			printf("Right!\n");
			kill(pid, SIGUSR2);
		}
		else {
			printf("Wrong!\n");
			
		}
		kill(pid, SIGUSR2);
		wait(NULL);
	}
	return (0);
}