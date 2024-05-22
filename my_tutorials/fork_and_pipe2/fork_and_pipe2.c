/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_pipe2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:44:23 by resilva           #+#    #+#             */
/*   Updated: 2024/04/23 00:08:51 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int	main(void)
{
	int	p1[2]; // Child to Parent
	int	p2[2]; // Parent to Child
	int	n;
	
	if (pipe(p1) == -1 || pipe(p2) == -1) { return 1; }
	
	int	pid = fork();
	if (pid == -1) { return 2; }
	if (pid == 0) {
		// Child process

		close (p1[0]);
		close (p2[1]);
		
		read (p2[0], &n, sizeof(n));
		printf("Readed %d in son\n", n);
		n *= 4;

		write (p1[1], &n, sizeof(n));
		printf("Wrote %d from child to parent\n", n);
		
		close (p1[1]);
		close (p2[0]);
	} else {
		// Parent process

		close (p1[1]);
		close (p2[0]);
		srand(time(NULL));
		n = rand() % 10;

		write (p2[1], &n, sizeof(n));
		printf("Wrote %d from parent to child\n", n);

		int	res;
		read (p1[0], &res, sizeof(res));
		printf("Received the result from child in parent process: %d\n", res);
		
		close (p1[0]);
		close (p2[1]);
		wait(NULL);
	}
}