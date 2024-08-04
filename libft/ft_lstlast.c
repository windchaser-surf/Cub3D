/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:34:17 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/13 18:10:55 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr -> next != NULL)
	{
		curr = curr -> next;
	}
	return (curr);
}
/*  t_list *create_new_node(void *content)
{
	t_list *result = malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result -> content = content;
	result -> next = NULL; 
	return (result);
}



//fügt den neuen node vor den head; und returnet dann den neuen node
t_list *insert_at_head(t_list *head, t_list *t_listo_insert)
{
	t_listo_insert -> next = head;
	return (t_listo_insert);
}
int main()
{
	t_list *head; 
	long i;
	int result; 
	t_list *tmp;
	t_list  *last;

	result = 0;
	i = 0;
	head = NULL;
	while (i < 10)
	{
		tmp =create_new_node((void *)i);
		head = insert_at_head(head, tmp);
		i++;
	}
	last = ft_lstlast (head);
	printf("%ld", (long)last -> content);
	return (0);
} */
