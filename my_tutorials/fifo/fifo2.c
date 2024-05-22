/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:59:42 by resilva           #+#    #+#             */
/*   Updated: 2024/04/17 22:14:17 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define SIZE 5

int	main(void)
{
	int	arr[SIZE];
	int i;
	int	sum;
	int	size;
	
	int	fd = open("sum", O_RDONLY);
	if (fd == -1)
		return (1);
	
	size = sizeof(arr) / sizeof(int);
	printf("Receiving numbers...\n");
	for (i = 0; i < size; i++) {
		if (read(fd, &arr[i], sizeof(int)) == -1)
			return (2);
		printf("Readed %d\n", arr[i]);
	}
	close (fd);
	
	sum = 0;
	for (i = 0; i < size; i++)
		sum += arr[i];
		
	fd = open("sum", O_WRONLY);
	if (fd == -1)
		return (3);
	
	if (write(fd, &sum, sizeof(int)) == -1)
		return (4);
	printf("\nSum made = %d, and sent back in fd -> %d\n", sum, fd);
	
	close (fd);
	return (0);
}
