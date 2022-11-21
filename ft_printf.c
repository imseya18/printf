/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:09:23 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/21 17:08:54 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_list.c"
#include "ft_itoa_u.c"
#include "ft_hexa.c"
#include "ft_hexa_maj.c"
#include "ft_list_s.c"
#include "ft_address.c"

int	ft_tab(p_list *start, int size)
{
	char	*tab;
	char	*temp;
	int		i;
	int		j;

	j = 0;
	tab = malloc((size + 1 * sizeof(char)));
	if (!tab)
		return (-1);
	while (start->next != NULL)
	{
		i = 0;
		temp = start->content;
		while (i < start->size)
			tab[j++] = temp[i++];
		start = start->next;
	}
	temp = start->content;
	i = 0;
	while (i < start->size)
		tab[j++] = temp[i++];
	tab[j] = '\0';
	write(1, tab, size);
	free(tab);
	return (0);
}

int	ft_p(void *p, p_list **start)
{
	p_list	*new;
	char	*str;

	str = ft_itoa_address(p);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(str);
	return (ft_strlen(str));
}

int	ft_di(int i, p_list **start)			//Pour nombre decimal
{
	p_list	*new;
	char	*str;

	str = ft_itoa(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(str);
	return (ft_strlen(str));
}

int	ft_u(unsigned int i, p_list **start)			//Pour unsigned int		
{
	p_list	*new;
	char	*str;

	str = ft_itoa_u(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(str);
	return (ft_strlen(str));
}

int	ft_x(unsigned int i, p_list **start)			//Pour Hexa minuscule		
{
	p_list	*new;
	char	*str;

	str = ft_itoa_hexa(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(str);
	return (ft_strlen(str));
}

int	ft_x_maj(unsigned int i, p_list **start)			//Pour Hexa Majuscule
{
	p_list	*new;
	char	*str;

	str = ft_itoa_hexa_maj(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(str);
	return (ft_strlen(str));
}

int	ft_string(char *str, p_list **start)	//Pour afficher string
{
	p_list	*new;
	char	*strn;

	if (str == NULL)
		strn = ft_strdup("(null)");
	else
		strn = ft_strdup(str);
	new = ft_lstnew_pf(strn);
	ft_lstadd_back_pf(start, new);
	new->size = ft_strlen(strn);
	return (ft_strlen(strn));
}

int	ft_char(char c, p_list **start)			//Pour afficher char
{
	p_list	*new;
	char	str[2];
	char	*strn;

	str[0] = c;
	str[1] = '\0';
	strn = ft_strdup(str);
	new = ft_lstnew_pf(strn);
	new->size = 1;
	ft_lstadd_back_pf(start, new);
	return (1);
}

int	ft_pars(char ftm, p_list **start, va_list arg)
{	
	int	size;

	size = 0;
	if (ftm == 'c')
		size = ft_char(va_arg(arg, int), start);
	else if (ftm == 's')
		size = ft_string(va_arg(arg, char *), start);
	else if (ftm == 'p')
		size = ft_p(va_arg(arg, void *), start);
	else if (ftm == 'd')
		size = ft_di(va_arg(arg, int), start);
	else if (ftm == 'i')
		size = ft_di(va_arg(arg, int), start);
	else if (ftm == 'u')
		size = ft_u(va_arg(arg, unsigned int), start);
	else if (ftm == 'x')
		size = ft_x(va_arg(arg, unsigned int), start);
	else if (ftm == 'X')
		size = ft_x_maj(va_arg(arg, unsigned int), start);
	else if (ftm == '%')
		size = ft_char(ftm, start);
	return (size);
}

int	ft_test(const char *ftm, p_list **start, va_list arg)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ftm[i])
	{
		if (ftm[i] == '%')
		{
			size = size + ft_pars(ftm[i + 1], start, arg);
			i++;
		}
		else
			size = size + ft_char(ftm[i], start);
		i++;
	}
	return (size);
}

int	ft_printf(const char *fmt, ...)
{
	p_list	*start;
	va_list	arg;
	int		size;

	start = 0;
	if (fmt[0] == '\0')
		return (0);
	va_start(arg, fmt);
	size = ft_test(fmt, &start, arg);
	ft_tab(start, size);
	va_end(arg);
	ft_lstclear_pf(&start);
	return (size);
}

//int	main()
//{
//	char	str[] = "hello";
//	unsigned int		i;
//
//	i = 124363467;
//	printf("---- TEST VRAI ----\n");
//	printf("%d\n", printf("%c%s%sok%c0ok%xdac\n" , 0 ,str, str, 0 , i));
//	printf("---- TEST MOI ----\n");
//	ft_printf("%d\n", ft_printf("%c%s%sok%c0ok%xdac\n", 0,str, str, 0, i));
//	return (0);
//}