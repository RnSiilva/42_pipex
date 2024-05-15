/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:21:55 by resilva           #+#    #+#             */
/*   Updated: 2023/10/23 17:28:15 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	char	*nb_str;
	int		len;

	nb_str = ft_itoa(n);
	len = ft_print_str(nb_str);
	free(nb_str);
	return (len);
}

// int	main(void)
// {
// 	int	len;
// 	int	n;

// 	n = 42;

// 	ft_printf("\n\t >>> ft_ <<<\n");
// 	len = ft_print_nbr(n);
// 	ft_printf("\nlen ft_: %d\n\n", len);

// 	printf("\n\t >>> orig <<<\n");
// 	len = printf("%d", n);
// 	printf("\nlen org: %d\n\n", len);
// 	return (0);
// }