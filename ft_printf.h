/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:16:46 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/22 16:13:54 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <stdarg.h>


typedef struct pf_list
{
	void			*content;
	int				size;
	struct pf_list	*next;
}	p_list;

p_list	*ft_lstnew_pf(void *content);
void	ft_lstadd_back_pf(p_list **lst, p_list *new);
p_list	*ft_lstlast_pf(p_list *lst);
int		ft_lstsize_pf(p_list *lst);
char	*ft_itoa_hexa_maj(unsigned int n);
char	*ft_itoa_hexa(unsigned int n);
char	*ft_itoa_u(unsigned int n);
int		ft_printf(const char *fmt, ...);
int		ft_test(const char *ftm, p_list **start, va_list arg, int *error);
int		ft_pars(char ftm, p_list **start, va_list arg, int *error);
int		ft_char(char c, p_list **start, int *error);
int		ft_string(char *str, p_list **start, int *error);
int		ft_x_maj(unsigned int i, p_list **start, int *error);
int		ft_x(unsigned int i, p_list **start, int *error);
int		ft_u(unsigned int i, p_list **start, int *error);
int		ft_di(int i, p_list **start, int *error);
int		ft_p(void *p, p_list **start, int *error);
void	ft_lstdelone_pf(p_list *lst);
void	ft_lstclear_pf(p_list **lst);
char	*ft_itoa_address(unsigned long n);
#endif