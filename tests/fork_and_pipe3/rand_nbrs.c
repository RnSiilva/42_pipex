/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:58:42 by resilva           #+#    #+#             */
/*   Updated: 2024/05/09 22:25:28 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

/*	2 process:
	1) Child process should generate random numbers and send them to the parent
	2) Parent is going to sum all the numbers and print the result
*/

int	main(void) {
	int	fd[2];
	if (pipe(fd) == -1)
		return (1);
		
	int pid = fork();
	if (pid == -1)
		return (2);
		
	if (pid == 0) {
		close (fd[0]);
		srand(time(NULL));
		
		int	arr[10], n;
		n = rand() % 10 + 1;
		printf("\n'n' was generated: %d\n", n);
		if (write (fd[1], &n, sizeof(int)) == -1)
			return (3);
		
		printf("Generated numbers:");
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 11;
			printf(" %d", arr[i]);
		}
		printf("\n");
		
		if (write (fd[1], arr, sizeof(int) * 10) == -1)
			return (4);
		printf("\nNumbers sent...\n");
		
		close (fd[1]);
	} else {
		close (fd[1]);

		int	n;
		if (read (fd[0], &n, sizeof(int)) == -1)
			return (5);
		
		int arr[n];
		if (read (fd[0], arr, sizeof(int) * n) == -1)
			return (6);
		printf("Numbers received...\n\n");
		
		int	sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
		}

		printf("The result of the sum is: %d\n", sum);
		wait(NULL);
	}
	return (0);
}