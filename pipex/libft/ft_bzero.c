/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:58:01 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:05:22 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: strings.h
DEF: Fill a memory block with zeros.
RETURN : None.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = -1;
	while (++i < n)
		p[i] = 0;
}

// int	main(void)
// {
// 	char	str[] = "42School";
// 	printf("\nbefore ft_bzero: %s\n", str);
// 	ft_bzero(str, 1);
// 	printf("after ft_bzero: %s\n\n", str);
// }
