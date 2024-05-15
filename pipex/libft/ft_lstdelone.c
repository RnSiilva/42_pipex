/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:32:00 by resilva           #+#    #+#             */
/*   Updated: 2023/10/17 17:30:23 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
DEF: Deletes and frees the memory of a node, using a custom function.
RETURN : None.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}

// void	ft_delete(void *content)
// {
// 	free(content);
// }

// int main(void)
// {
//     t_list  *new = ft_lstnew(strdup("42Porto"));

//     if (new->content != NULL)
//         printf("\nContent before deletion: '%s'\n", (char *)new->content);

//     ft_lstdelone(new, ft_delete);
//     printf("Content after deletion: '%s'\n\n", (char *)new->content);

//     return (0);
// }
