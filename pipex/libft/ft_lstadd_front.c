/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:15:01 by resilva           #+#    #+#             */
/*   Updated: 2023/10/18 16:16:27 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Adds a new element to the beginning of a linked list.
RETURN : None.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	char	*str = "Renan";
// 	t_list	*l = NULL;
// 	t_list	*no1;
// 	t_list	*no2;

// 	no1 = ft_lstnew("Primeiro");
// 	ft_lstadd_front(&l, no1);

// 	no2 = ft_lstnew("Segundo");
// 	ft_lstadd_front(&l, no2);

// 	t_list *atual = l;
// 	while (atual)
// 	{
// 		printf("%s\n", (char *)atual->content);
// 		atual = atual->next;
// 	}
// 	return (0);
// }

// // /*int	main(void)
// // {
// // 	char	*str = "Renan";
// // 	t_list	*l = NULL;

// // 	t_list	*elemento1 = (t_list *)malloc(sizeof(t_list));
// // 	elemento1->content = "Primeiro";
// // 	elemento1->next = NULL;
// // 	ft_lstadd_front(&l, elemento1);

// // 	t_list *elemento2 = (t_list *)malloc(sizeof(t_list));
// // 	elemento2->content = "Segundo";
// // 	elemento2->next = NULL;
// // 	ft_lstadd_front(&l, elemento2);

// // 	t_list *atual = l;
// // 	while (atual)
// // 	{
// // 		printf("%s\n", (char *)atual->content);
// // 		atual = atual->next;
// // 	}
// // 	return (0);
// // }*/