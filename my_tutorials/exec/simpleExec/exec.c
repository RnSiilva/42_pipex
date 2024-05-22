/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:06:41 by resilva           #+#    #+#             */
/*   Updated: 2024/04/29 21:36:58 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// execl = This function expects a list of arguments terminated by a null pointer.
// execv = This function expects a vector of argv argument string, and first element is the program name.
// letter p = Indicates that the system will search for the program in the system PATH directory.
// letter e = Allows you to pass an array of environment variable string as an additional parameter.

int	main(void)
{
	//EXECL
	/*
	execl(
		"/usr/bin/ping", 
		"/usr/bin/ping", 
		"google.com", 
		NULL
	);
	*/

	//EXECLP
	/*
	execlp("ping", "ping", "google.com", NULL);
	*/

	//EXECLE
	/*
	char *env[] = { "TEST=environment variable", NULL};
	execle("/usr/bin/ping", "ping", "google.com", NULL, env);
	*/
	

	
	//EXECV
	/*char *arr[] = { "/usr/bin/ping", "google.com", NULL};
	execv(
		"/usr/bin/ping",
		arr
	);*/

	//EXECVP
	/*
	char *arr[] = {"ping", "google.com", NULL};
	execvp("ping", arr);
	*/

	//EXECVE
	char *arr[] = {"ping", "google.com", NULL};
	char *env[] = {"TEST=environment variable", NULL};
	execve("/usr/bin/ping", arr, env);



	printf("This message appears if something has gone wrong\n");
	return (0);
}
