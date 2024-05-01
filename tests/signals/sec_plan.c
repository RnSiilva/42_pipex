/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:32:19 by resilva           #+#    #+#             */
/*   Updated: 2024/05/01 22:48:30 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ao rodar o programa abaixo no temrinal, enquanto 'scanf()' estiver esperando 
 por um numero, podemos pressionar 'CTRL + Z' para enviar um sinal de SIGSTOP, 
 fazendo com que o programa seja colocado em segundo plano, e fique "pausado".
  Para voltar a execucao, deve digitar 'fg', e continuar normalmente, inserindo o 
  numero que foi pedido, neste caso em especifico.*/
  
#include <stdio.h>

int	main(void)
{
	int	x;
	printf("Insert number: ");
	scanf("%d", &x);
	printf("Result %d * 3 = %d\n", x, x * 3);
	return (0);
}