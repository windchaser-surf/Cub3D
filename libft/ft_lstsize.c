/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:11:30 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/13 17:44:54 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		j;

	curr = lst;
	j = 0;
	while (curr != NULL)
	{
		j++;
		curr = curr -> next;
	}
	return (j);
}
/* t_list *create_new_node(void *content)
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

	result = 0;
	i = 0;
	head = NULL;
	while (i < 10)
	{
		tmp =create_new_node((void *)i);
		head = insert_at_head(head, tmp);
		i++;
	}
	result = ft_lstsize(head);
	printf("%d", result);
	return (0);
} */