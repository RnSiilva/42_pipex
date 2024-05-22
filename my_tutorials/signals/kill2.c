/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:45:47 by resilva           #+#    #+#             */
/*   Updated: 2024/05/01 22:25:26 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

int	is_numeric(char *s)
{
	int	i = -1;
	while (s[++i])
	{
		if (s[i] < '0' && s[i] > '9')
			return (0);
	}
	return (1);
}

int	main(void)
{
	int	pid = fork();
	if (pid == -1)
		return (1);
	
	if (pid == 0) {
		while (1) {
			printf("Some text here\n");
			usleep(50000);
		}
	} else {
		kill(pid, SIGSTOP);
		
		char input[100];
		int	t;
		do {
			printf("Enter waiting time: ");
			scanf("%s", input);

			if (strcmp(input, "quit") == 0)
				break;
			else if (is_numeric(input))
				t = atoi(input);
			if (t > 0) {
				kill(pid, SIGCONT);
				sleep(t);
				kill(pid, SIGSTOP);
			}
		} while (t > 0);
		kill(pid, SIGKILL);
		wait(NULL);
	}
}