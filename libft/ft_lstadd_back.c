/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:56 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/13 17:10:15 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(tmp);
	tmp -> next = new;
}
/* 
void printall(t_list *head)
{
	t_list *temp;
	
	temp = head;
	while (temp != NULL)
	{
		printf("%ld - ", (long)(temp -> content));
		temp = temp -> next;
	}
}

int main()
{
	long i; 
	t_list *lst;
	t_list	*new;
	
	
	lst = NULL;
	i = 0;
	while (i < 10)
	{
		new = ft_lstnew((void *)i);
		ft_lstadd_back(&lst, new);
		
		i++;
	}
	printall(lst);
	return (0);
} */