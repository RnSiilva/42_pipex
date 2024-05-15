/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:19:13 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 19:13:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
LIBRARY: ctype.h
DEF: Converts a lowercase character to upper
RETURN : The characater in upper case
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

// int	main(void)
// {
// 	char	c = 'e';
// 	printf("'%c' to uppercase: '%c'", c, ft_toupper(c));
// }