/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_plan2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:28:22 by resilva           #+#    #+#             */
/*   Updated: 2024/05/08 17:38:39 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	handle_sigtstp(int sig) {
	printf("\nStop not allowed\n");
}

void	handle_sigcont(int sig) {
	printf("Input number: ");
	fflush(stdout);
}
int	main(void)
{
	/*Para mostrar uma mensagem quando o sinal SIGCONT for recebido, ou seja, 
	quando fg for digitado*/
	/*
	struct sigaction sa1;
	sa1.sa_handler = &handle_sigcont;
	sa1.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa1, NULL);
	*/

	struct sigaction sa2;
	sa2.sa_handler = &handle_sigtstp;
	sa2.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &sa2, NULL);
	
	int	x;
	printf("Input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);
	return (0);
}