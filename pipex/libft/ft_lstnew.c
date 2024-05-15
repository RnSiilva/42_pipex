/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:11:59 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 21:28:44 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Creates a new node for a linked list.
RETURN : The new node.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	char	*str = "42School";
// 	int		n[] = {0, 4, 2};
// 	t_list	*new;
// 	t_list	*new2;

// 	printf("\n\t>>> TESTING WITH STRING <<<\n\n");
// 	new = ft_lstnew(str);
// 	printf("Content in the 'content' field: \'%s\'\n", (char *)new->content);
// 	printf("Content in the 'next' field: '%s'\n", (char *)new->next);
// 	printf("\n\t>>> TESTING WITH INT <<<\n\n");
// 	new2 = ft_lstnew(n);
// 	printf("Content in the 'content' field: \'%d\'\n",
// 	((int *)new2->content)[1]);
// 	printf("Content in the 'next' field: '%s'\n\n", (char *)new2->next);
// 	free (new);
// 	free (new2);
// 	return (0);
// }
