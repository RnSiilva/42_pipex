/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 04:11:57 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:22:44 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Converts an int to a string.
RETURN : The converted value(string).
*/

#include "libft.h"

static char	*ft_conversion(char *str, int size, int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	str[size] = '\0';
	while (n != 0)
	{
		str[--size] = (char)((n % 10) * sign + '0');
		n = n / 10;
	}
	if (sign < 0)
		str[--size] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		nb;
	int		size;
	char	*str;

	size = 0;
	nb = n;
	while (nb != 0)
	{
		nb = nb / 10;
		size++;
	}
	size = size + (n <= 0);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = ft_conversion(str, size, n);
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return (0);
// }