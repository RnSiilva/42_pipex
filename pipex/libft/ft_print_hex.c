/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 22:05:35 by resilva           #+#    #+#             */
/*   Updated: 2023/10/23 22:49:42 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, format);
		ft_put_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			if (format == 'X')
				ft_putchar_fd(n - 10 + 'A', 1);
		}
	}
}

int	ft_print_hex(unsigned int n, const char format)
{
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	else
		ft_put_hex(n, format);
	return (ft_hex_len(n));
}

// int	main(void)
// {
// 	int				len;
// 	unsigned int	n;

// 	n = 42;

// 	ft_printf("\n\t >>> ft_ <<<\n");
// 	len = ft_print_hex(n, 'x');
// 	ft_printf("\nlen ft_: %d\n\n", len);

// 	printf("\n\t >>> orig <<<\n");
// 	len = printf("%x", n);
// 	printf("\nlen org: %d\n\n", len);
// 	return (0);
// }