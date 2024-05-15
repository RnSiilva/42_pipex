/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:23:14 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:16:13 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: ctype.h
DEF: Checks for an alphanumeric character.
RETURN : Positive number if true, and zero if false.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '4';
// 	if (ft_isalnum(c))
// 		printf("The char '%c' is alphaNumeric\n", c);
// 	else
// 		printf("The char '%c' is not AlphaNumeric\n", c);
// }
