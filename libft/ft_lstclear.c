/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:18 by fwechsle          #+#    #+#             */
/*   Updated: 2023/10/13 17:08:47 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
void    delete_content(void *content)
{
	free(content);
} */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	while (*lst != NULL)
	{
		curr = *lst;
		*lst = curr -> next;
		ft_lstdelone(curr, del);
	}
	*lst = NULL;
}

/* int main()
{
	t_list *lst;
	
	ft_lstclear(&lst, &delete_content);
	
} */