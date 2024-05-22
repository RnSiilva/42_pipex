/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:55:55 by resilva           #+#    #+#             */
/*   Updated: 2024/05/09 23:32:19 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void) {
	int pfd[2];
	if (pipe(pfd) == -1)
		return (1);
	
	int	pid = fork();
	if (pid == -1)
		return (2);
	
	if (pid == 0) {
		close(pfd[0]);
		
		char	str[200];
		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';
	
		int	n = strlen(str) + 1;
		if (write(pfd[1], &n, sizeof(int)) == -1)
			return (3);

		if (write(pfd[1], str, sizeof(char) * n) == -1)
			return (4);

		close(pfd[1]);
	} else {
		close(pfd[1]);

		int	n;
		if (read(pfd[0], &n, sizeof(int)) == -1)
			return (5);

		char	str[200];
		if (read(pfd[0], str, n) == -1)
			return (6);

		printf("Received string: %s\n", str);
		
		close (pfd[0]);
		wait(NULL);
	}
	return (0);
}