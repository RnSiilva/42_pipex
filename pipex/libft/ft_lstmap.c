/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:26:21 by resilva           #+#    #+#             */
/*   Updated: 2023/10/27 00:51:18 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Creates a new linked list by applying a custom function to each element.
RETURN : A pointer to the new list.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	new_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// void	ft_delete(void *content)
// {
// 	if (content)
// 	{
// 		printf("Deallocated: '%s'\n", (char *)content);
// 		free(content);
// 	}
// }

// void	*ft_iter(void *content)
// {
// 	((char *)content)[0] = 'n';
// 	return (content);
// }

// int	main(void)
// {
// 	t_list	*lst = NULL;
// 	t_list	*new = NULL;
// 	t_list	*temp;

// 	lst = ft_lstnew(strdup("code1"));
// 	lst->next = ft_lstnew(strdup("code2"));
// 	lst->next->next = ft_lstnew(strdup("code3"));
// 	lst->next->next->next = ft_lstnew(strdup("code4"));

// 	printf("This is the 'new' before de ft_lstmap: %s\n", (char *)new);
// 	new = ft_lstmap(lst, ft_iter, ft_delete);
// 	temp = new;
// 	if (new)
// 	{
// 		printf("\nThis is the 'new' after the iteration:\n");
// 		while (new)
// 		{
// 			printf("%s\n", (char *)new->content);
// 			new = new->next;
// 		}
// 	}
// 	new = temp;
// 	printf("\n\t>>> Dislocating the memories <<<\n");
// 	ft_lstclear(&new, ft_delete);
// 	return (0);
// }