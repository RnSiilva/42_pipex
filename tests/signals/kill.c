/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:54:00 by resilva           #+#    #+#             */
/*   Updated: 2024/04/30 01:02:24 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int	main(void)
{
	int pid = fork();
	if (pid == -1)
		return (1);
	
	if (pid == 0) {
		while (1) {
			printf("Some text goes here!\n");
			usleep(50000);
		}
	} else {
		sleep(1);
		kill(pid, SIGKILL);
		wait(NULL);
		printf("Sucess!\n");
	}
}