/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:41:26 by resilva           #+#    #+#             */
/*   Updated: 2024/04/17 22:25:28 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define SIZE 5

int	main(void)
{
	int	arr[SIZE];
	int	i, size, sum;
	
	int	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (1);
		
	srand(time(NULL));
	size = sizeof(arr) / sizeof(int);
	printf("Sending numbers...\n");
	for (i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		if (write (fd, &arr[i], sizeof(int)) == -1)
			return (2);
		printf("Wrote and sent %d\n", arr[i]);
	}
	printf("fd -> %d\n\n", fd);
	close(fd);

	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return (3);
	
	printf("Receiving sum...\n");
	if (read(fd, &sum, sizeof(int)) == -1)
		return (4);
	printf("Sum received is %d\n", sum);
	close (fd);
	return (0);
}
