/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:28:00 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:34:47 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Search for the last node in the list.
RETURN : A pointer to the last node found.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	*l;
// 	t_list *n1;
// 	t_list *n2;
// 	t_list *n3;

// 	n1 = ft_lstnew("Head");
// 	n2 = ft_lstnew("Body");
// 	n3 = ft_lstnew("Tail");

// 	ft_lstadd_front(&l, n3);
// 	ft_lstadd_front(&l, n2);
// 	ft_lstadd_front(&l, n1);

// 	l = ft_lstlast(l);
// 	printf("\n\t >>> LAST: '%s' <<<\n\n", (char *)l->content);
// }