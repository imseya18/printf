/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:32:12 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/21 17:34:57 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstclear_pf(p_list **lst)
{
	p_list	*temp;
	p_list	*new;

	if (lst == 0)
		return ;
	new = *lst;
	temp = *lst;
	while (new != 0)
	{
		temp = new->next;
		ft_lstdelone_pf(new);
		new = temp;
	}
	new = 0;
}
