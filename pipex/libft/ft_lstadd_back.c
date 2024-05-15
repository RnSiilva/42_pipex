/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:40:56 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:24:14 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Adds a new element to the end of a linked list.
RETURN : None.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

// int	main(void)
// {
// 	t_list	*l = NULL;
// 	t_list	*no1;
// 	t_list	*no2;
// 	t_list	*no3;

// 	no1 = ft_lstnew(strdup("Tail"));
// 	no2 = ft_lstnew(strdup("Body"));
// 	no3 = ft_lstnew(strdup("Head"));
// 	ft_lstadd_back(&l, no3);
// 	ft_lstadd_back(&l, no2);
// 	ft_lstadd_back(&l, no1);

// 	t_list *atual = l;
// 	while (atual)
// 	{
// 		printf("%s\n", (char *)atual->content);
// 		atual = atual->next;
// 	}
// 	return (0);
// }
