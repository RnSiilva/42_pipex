/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 02:21:27 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 19:14:42 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Loops through a linked list and applies a custom function to each element.
RETURN : None.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	ft_delete(void *content)
// {
// 	if (content)
// 	{
// 		printf("Deallocated: '%s'\n", (char *)content);
// 		free(content);
// 	}
// }

// void	ft_iter(void *content)
// {
// 	((char *)content)[0] = 'c'; 
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*tmp;

// 	lst = ft_lstnew(strdup("node1"));
// 	lst->next = ft_lstnew(strdup("node2"));
// 	lst->next->next = ft_lstnew(strdup("node3"));
// 	lst->next->next->next = ft_lstnew(strdup("node4"));

// 	tmp = lst;
// 	if (lst)
// 	{
// 		printf("These are the nodes before the iteration:\n");
// 		while (lst)
// 		{
// 			printf("%s\n", (char *)lst->content);
// 			lst = lst->next;
// 		}
// 	}

// 	lst = tmp;
// 	ft_lstiter(lst, ft_iter);
// 	if (lst)
// 	{
// 		printf("\nThese are the nodes after the iteration:\n");
// 		while (lst)
// 		{
// 			printf("%s\n", (char *)lst->content);
// 			lst = lst->next;
// 		}
// 	}

// 	lst = tmp;
// 	printf("\n\t >>> Dislocating the memories <<<\n");
// 	ft_lstclear(&lst, ft_delete);
// 	return (0);
// }
