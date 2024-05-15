/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:22:18 by resilva           #+#    #+#             */
/*   Updated: 2023/10/23 22:57:55 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(const char *str, va_list ap, size_t *i)
{
	int	count;

	count = 0;
	if (str[*i] == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (str[*i] == 's')
		count = count + ft_print_str(va_arg(ap, char *));
	else if (str[*i] == 'p')
		count = count + ft_print_ptr(va_arg(ap, unsigned long long));
	else if (str[*i] == 'd' || str[*i] == 'i')
		count = count + ft_print_nbr(va_arg(ap, int));
	else if (str[*i] == 'u')
		count = count + ft_print_unsigned(va_arg(ap, unsigned int));
	else if (str[*i] == 'x' || str[*i] == 'X')
		count = count + ft_print_hex(va_arg(ap, unsigned int), str[*i]);
	else if (str[*i] == '%')
		count = count + ft_print_perc();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count = count + ft_formats(str, ap, &i);
		}
		else
			count = count + ft_print_char(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int	l;
// 	void	*ptr = "42";

// 	l = ft_printf("Hello %d\n", 42);
// 	ft_printf("%d", l);
// 	return (0);
// }