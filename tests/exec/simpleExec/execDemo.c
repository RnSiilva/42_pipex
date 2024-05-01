/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execDemo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:46:03 by resilva           #+#    #+#             */
/*   Updated: 2024/04/29 20:49:38 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(void)
{
	// A null terminated array of character
	// pointers
	char *args[] = {"./exec1", NULL};
	execvp(args[0], args);

	/* All statments are ignored after execvp() call as this whole process 
	(execDemo.c) is replaced by another process (exec1.c) */
	printf("Ending-----");

	return (0);
}