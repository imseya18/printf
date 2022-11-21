/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:39:15 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/21 16:42:24 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

p_list	*ft_lstnew_pf(void *content)
{
	p_list	*new;

	new = malloc(sizeof(p_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	new->size = 0;
	return (new);
}

void	ft_lstadd_back_pf(p_list **lst, p_list *new)
{
	p_list	*temp;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast_pf(*lst);
	temp->next = new;
}

p_list	*ft_lstlast_pf(p_list *lst)
{
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize_pf(lst);
	while (i < size - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

int	ft_lstsize_pf(p_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}	
	return (i);
}

void	ft_lstdelone_pf(p_list *lst)
{
	if (lst == 0)
		return ;
	if (lst->content != 0)
		free(lst->content);
	free(lst);
}
