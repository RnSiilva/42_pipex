/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:17:28 by resilva           #+#    #+#             */
/*   Updated: 2023/10/23 22:48:52 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	while (ptr)
	{
		count++;
		ptr /= 16;
	}
	return (count);
}

void	ft_put_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_ptr(ptr / 16);
		ft_put_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		return (count + ft_print_str("(nil)"));
	}
	else
	{
		count = write(1, "0x", 2);
		ft_put_ptr(ptr);
		count += ft_len_ptr(ptr);
	}
	return (count);
}

// int main(void) 
// {
//     void	*ptr = "42Porto";
// 	int		len;

// 	ft_printf("\n\t >>> ft_ <<<\n");
// 	len = ft_print_ptr((long)ptr);
// 	ft_printf("\nlen ft_: %d\n\n", len);

// 	printf("\n\t >>> orig <<<\n");
// 	len = printf("%p", ptr);
// 	printf("\nlen org: %d\n\n", len);
//     return (0);
// }