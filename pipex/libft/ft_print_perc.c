/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:36:35 by resilva           #+#    #+#             */
/*   Updated: 2023/10/23 22:48:18 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_perc(void)
{
	return (write(1, "%", 1));
}

// int	main(void)
// {
// 	int	len;

// 	ft_printf("\n\t >>> ft_ <<<\n");
// 	len = ft_print_perc();
// 	ft_printf("\nlen ft_: %d\n\n", len);

// 	printf("\n\t >>> orig <<<\n");
// 	len = printf("%%");
// 	printf("\nlen org: %d\n\n", len);
// 	return (0);
// }