/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:48:44 by resilva           #+#    #+#             */
/*   Updated: 2024/04/22 22:26:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// O objetivo eh criar um programa que some os numeros de uma array, porem que
// isso seja feito separadamente em tres processos, cada processo soma uma parte,
// e envia para o processo principal para que a soma seja feita.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int	arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17};
	int	arrSize = sizeof(arr) / sizeof(int);
	int	start, end;
	int	fd1[2], fd2[2];
	int	id1, id2;

	if (pipe(fd1) == -1 || pipe(fd2) == -1)
		return (1);
	
	id1 = fork();
	if (id1 == -1)
		return (2);
		
	if (id1 == 0) {
		id2 = fork();
		if (id2 == -1)
			return (3);
		
		if (id2 == 0) {
			start = 0;
			end = arrSize / 3;
		} else {
			start = arrSize / 3;
			end = start + arrSize / 3;
			wait(NULL);
		}
	} else {
		start = (arrSize * 2) / 3;
		end = arrSize;
		wait(NULL);
	}

	int	sum = 0;
	for (int i = start; i < end; i++)
		sum += arr[i];
	
	printf ("Parcial sum: %d\n", sum);

	if (id1 == 0) {
		if (id2 == 0) {
			close(fd1[0]);
			write(fd1[1], &sum, sizeof(int));
			close(fd1[1]);
		} else {
			close(fd2[0]);
			write(fd2[1], &sum, sizeof(int));
			close(fd2[1]);
		}
	} else {
		close(fd1[1]);
		close(fd2[1]);
		int	sumParc, sumTotal;
		read(fd1[0], &sumParc, sizeof(int));
		sum += sumParc;
		read(fd2[0], &sumParc, sizeof(int));
		sumTotal = sumParc + sum;
		close(fd1[0]);
		close(fd2[0]);
		printf("Sum total is %d\n", sumTotal);
		wait(NULL);
	}
	return (0);
}

// int	main(void)
	
// {
// 	int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17};
// 	int	arrSize = sizeof(arr) / sizeof(int);
// 	int	fd[2];
// 	int	start, end;
// 	int	id, id1;

// 	if (pipe(fd) == -1)
// 		return (1);
	
// 	id = fork();
// 	if (id == -1)
// 		return (2);

// 	if (id == 0) {
// 		id1 = fork();
// 		if (id1 == 0) {
// 			start = 0;
// 			end = arrSize / 3;
// 		} else {
// 			start = arrSize / 3;
// 			end = arrSize / 3 + start;
// 			wait(NULL);
// 		}
// 	} else {
// 		start = arrSize / 3 * 2;
// 		end = arrSize;
// 		wait(NULL);
// 	}

// 	int	sum = 0;
// 	for (int i = start; i < end; i++)
// 		sum += arr[i];
	
// 	printf("Partial sum = %d -> process: %d\n", sum, getpid());

// 	if (id == 0) {
// 		if (id1 == 0) {
// 			close(fd[0]);
// 			if (write(fd[1], &sum, sizeof(int)) == -1)
// 				return (5);
// 			close(fd[1]);
// 		} else {
// 			int	sumParc;
// 			if (read(fd[0], &sumParc, sizeof(int)) == -1)
// 				return (6);
// 			close(fd[0]);
// 			sumParc += sum;
// 			if (write(fd[1], &sumParc, sizeof(int)) == -1)
// 				return 3;
// 			close(fd[1]);
// 			wait(NULL);
// 		}
// 	} else {
// 		close(fd[1]);
// 		int	sumTotal;
// 		if (read(fd[0], &sumTotal, sizeof(int)) == -1)
// 			return 4;
// 		close(fd[0]);
// 		sumTotal += sum;
// 		printf("Total sum = %d\n", sumTotal); 
// 		wait(NULL);
// 	}
// 	return (0);
// }
