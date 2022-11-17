/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:10:08 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/17 16:58:07 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>


typedef struct pf_list
{
	void			*content;
	//int				size;
	struct pf_list	*next;
}	p_list;

p_list	*ft_lstnew_pf(void *content);
void	ft_lstadd_back_pf(p_list **lst, p_list *new);
p_list	*ft_lstlast_pf(p_list *lst);
int		ft_lstsize_pf(p_list *lst);

#endif