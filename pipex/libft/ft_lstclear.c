/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:02:05 by resilva           #+#    #+#             */
/*   Updated: 2023/10/27 00:41:56 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Deletes and frees the memory of a node and all its successors.
RETURN : None.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

// void	ft_delete(void *content)
// {
// 	if (content)
// 	{
// 		printf("Deallocated: '%s'\n", (char *)content);
// 		free(content);
// 	}
// }

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew(strdup("node1"));
// 	lst->next = ft_lstnew(strdup("node2"));
// 	lst->next->next = ft_lstnew(strdup("node3"));
// 	lst->next->next->next = ft_lstnew(strdup("node4"));
// 	ft_lstclear(&(lst), ft_delete);

// 	if (lst)
// 	{
// 		printf("\nThese nodes have not deallocated:\n");
// 		while (lst)
// 		{
// 			printf("%s\n", (char *)lst->content);
// 			lst = lst->next;
// 		}
// 	}
// 	ft_lstdelone(lst, ft_delete);
// }