/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:22:12 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:19:19 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: ctype.h
DEF: Checks for a digit character.
RETURN : Positive number if true, and zero if false.
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '4';
// 	if (ft_isdigit(c))
// 		printf("The char '%c' is digit\n", c);
// 	else
// 		printf("The char '%c' is not digit\n", c);
// }