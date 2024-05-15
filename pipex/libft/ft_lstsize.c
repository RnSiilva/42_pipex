/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:16:35 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 21:31:37 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Counts the number of elements in a linked list.
RETURN : The number of elements.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (lst)
	{
		while (lst)
		{
			size++;
			lst = lst->next;
		}
		return (size);
	}
	return (0);
}

// int	main(void)
// {
// 	t_list	*l = NULL;
// 	t_list	*n1;
// 	t_list	*n2;

// 	n1 = ft_lstnew("Primeiro");
// 	n2 = ft_lstnew("Segundo");
// 	ft_lstadd_front(&l, n2);
// 	ft_lstadd_front(&l, n1);

// 	printf("\n\t >>> SIZE: '%d' <<< \n\n", ft_lstsize(l));
// 	return (0);
// }