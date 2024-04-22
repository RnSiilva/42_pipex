/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:56:42 by resilva           #+#    #+#             */
/*   Updated: 2024/04/22 22:01:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>

int	main(void)
{
	int	id1 = fork();
	int	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("We are process y: %d -> parent: %d\n", getpid(), getppid());
		else
			printf("We are process x: %d -> parent: %d\n", getpid(), getppid());
	}
	else
	{
		if (id2 == 0)
			printf("We are process z: %d -> parent: %d\n", getpid(), getppid());
		else
			printf("We are parent process: %d\n", getpid());
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for a child to finish\n"); 
	return (0);
}

// wait(NULL): Esta funcao espera que qualquer processo filho termine. Se houver
// um processo filho em execucao, ele retorna o PID do processo filho que terminou.
// Se nao houver nenhum processo filho em execucao, retorna -1.

// errno != ECHILD: 'errno' eh uma variavel global definida pela biblioteca padrao C
// para relatar erros. 'ECHILD' eh um codigo de erro que indica que nao ha processos
// filhos para o processo atual. Portanto, 'errno != ECHILD' verifica se o erro
// retornado por 'wait()' n eh devido a ausencia de processos filhos. Qnd ainda n ha
// processos filhos em execucao, 'errno' sera diferente de 'ECHILD'.

// errno eh usado como uma redundancia, por garantia.