/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 23:10:57 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:22:51 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: stdlib.h
DEF: Converts a string to int.
RETURN : The converted value(int).
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = (nb * 10) + (*nptr - 48);
		nptr++;
	}
	return (nb * sign);
}

// int	main(void)
// {
// 	char	string[] = "   -1234ab567";
// 	printf("\nft: %d\n", ft_atoi(string));
// 	printf("orig: %d\n\n", atoi(string));
// }
