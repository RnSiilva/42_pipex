/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 03:27:55 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 18:04:31 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Writes a character to a file associated with a file descriptor(fd).
RETURN : None.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putchar_fd('R', 1);
// }