/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:27:16 by fwechsle          #+#    #+#             */
/*   Updated: 2024/02/27 17:20:22 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

// int main()
// {
// 	t_list *head; 
// 	t_list *tmp;
// 	t_list *cur;
// 	head = NULL;
// 	tmp = ft_lstnew((void *)34);
// 	tmp -> next = head;
// 	head = tmp; 

// 	cur = head;
// 	while (cur != NULL)
// 	{
// 		printf("%ld", (long)cur -> content);
// 		cur = cur -> next; 
// 	}
// }