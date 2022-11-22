/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:09:23 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/22 16:13:53 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "ft_list.c"
//#include "ft_itoa_u.c"
//#include "ft_hexa.c"
//#include "ft_hexa_maj.c"
//#include "ft_list_s.c"
//#include "ft_address.c"

void	ft_fill_tab_f(p_list *start, char *tab)
{	
	int		i;
	int		j;
	char	*temp;

	j = 0;
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
}

int	ft_tab(p_list *start, int size)
{
	char	*tab;
	int		sz;

	tab = malloc((size + 1 * sizeof(char)));
	if (!tab)
		return (-1);
	ft_fill_tab_f(start, tab);
	sz = write(1, tab, size);
	free(tab);
	if (sz == -1)
		return (sz);
	return (0);
}

//int	ft_p(void *p, p_list **start, int *error)
//{
//	p_list			*new;
//	char			*str;
//	unsigned long	i;
//
//	i = (unsigned long)p;
//	str = ft_itoa_address(i);
//	if (str == NULL)
//	{
//		*error = 1;
//		return (0);
//	}
//	new = ft_lstnew_pf(str);
//	if (new == NULL)
//	{
//		free(str);
//		*error = 1;
//		return (0);
//	}
//	ft_lstadd_back_pf(start, new);
//	new->size = ft_strlen(str);
//	return (ft_strlen(str));
//}
//
//int	ft_di(int i, p_list **start, int *error)
//{
//	p_list	*new;
//	char	*str;
//
//	str = ft_itoa(i);
//	if (str == NULL)
//	{
//		*error = 1;
//		return (0);
//	}
//	new = ft_lstnew_pf(str);
//	if (new == NULL)
//	{
//		free(str);
//		*error = 1;
//		return (0);
//	}
//	ft_lstadd_back_pf(start, new);
//	new->size = ft_strlen(str);
//	return (ft_strlen(str));
//}

//int	ft_u(unsigned int i, p_list **start, int *error)
//{
//	p_list	*new;
//	char	*str;
//
//	str = ft_itoa_u(i);
//	if (str == NULL)
//	{
//		*error = 1;
//		return (0);
//	}
//	new = ft_lstnew_pf(str);
//	if (new == NULL)
//	{
//		free(str);
//		*error = 1;
//		return (0);
//	}
//	ft_lstadd_back_pf(start, new);
//	new->size = ft_strlen(str);
//	return (ft_strlen(str));
//}
//
//int	ft_x(unsigned int i, p_list **start, int *error)
//{
//	p_list	*new;
//	char	*str;
//
//	str = ft_itoa_hexa(i);
//	if (str == NULL)
//	{
//		*error = 1;
//		return (0);
//	}
//	new = ft_lstnew_pf(str);
//	if (new == NULL)
//	{
//		free(str);
//		*error = 1;
//		return (0);
//	}
//	ft_lstadd_back_pf(start, new);
//	new->size = ft_strlen(str);
//	return (ft_strlen(str));
//}
//
//int	ft_x_maj(unsigned int i, p_list **start, int *error)	
//{
//	p_list	*new;
//	char	*str;
//
//	str = ft_itoa_hexa_maj(i);
//	if (str == NULL)
//	{
//		*error = 1;
//		return (0);
//	}
//	new = ft_lstnew_pf(str);
//	if (new == NULL)
//	{
//		free(str);
//		*error = 1;
//		return (0);
//	}
//	ft_lstadd_back_pf(start, new);
//	new->size = ft_strlen(str);
//	return (ft_strlen(str));
//}
//
//int	ft_string(char *str, p_list **start, int *error)
//{
//	p_list	*new;
//	char	*strn;
//
//	if (str == NULL)
//		strn = ft_strdup("(null)");
//	else
//		strn = ft_strdup(str);
//	if (strn == NULL)
//	{
//		*error = 1;
//		return (0);
//	}
//	new = ft_lstnew_pf(strn);
//	if (new == NULL)
//	{
//		free(strn);
//		*error = 1;
//		return (0);
//	}
//	ft_lstadd_back_pf(start, new);
//	new->size = ft_strlen(strn);
//	return (ft_strlen(strn));
//}
//
//int	ft_char(char c, p_list **start, int *error)
//{
//	p_list	*new;
//	char	str[2];
//	char	*strn;
//
//	str[0] = c;
//	str[1] = '\0';
//	strn = ft_strdup(str);
//	if (strn == NULL)
//	{
//		*error = 1;
//		return (0);
//	}
//	new = ft_lstnew_pf(strn);
//	if (new == NULL)
//	{
//		free(strn);
//		*error = 1;
//		return (0);
//	}
//	new->size = 1;
//	ft_lstadd_back_pf(start, new);
//	return (1);
//}

int	ft_pars(char ftm, p_list **start, va_list arg, int *error)
{	
	int	size;

	size = 0;
	if (ftm == 'c')
		size = ft_char(va_arg(arg, int), start, error);
	else if (ftm == 's')
		size = ft_string(va_arg(arg, char *), start, error);
	else if (ftm == 'p')
		size = ft_p(va_arg(arg, void *), start, error);
	else if (ftm == 'd')
		size = ft_di(va_arg(arg, int), start, error);
	else if (ftm == 'i')
		size = ft_di(va_arg(arg, int), start, error);
	else if (ftm == 'u')
		size = ft_u(va_arg(arg, unsigned int), start, error);
	else if (ftm == 'x')
		size = ft_x(va_arg(arg, unsigned int), start, error);
	else if (ftm == 'X')
		size = ft_x_maj(va_arg(arg, unsigned int), start, error);
	else if (ftm == '%')
		size = ft_char(ftm, start, error);
	return (size);
}

int	ft_test(const char *ftm, p_list **start, va_list arg, int *error)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (ftm[i] && *error == 0)
	{
		if (ftm[i] == '%')
		{
			size = size + ft_pars(ftm[i + 1], start, arg, error);
			i++;
		}
		else
			size = size + ft_char(ftm[i], start, error);
		i++;
	}
	return (size);
}

int	ft_printf(const char *fmt, ...)
{
	p_list	*start;
	va_list	arg;
	int		size;
	int		error;
	int		check;

	error = 0;
	start = 0;
	check = 0;
	if (fmt[0] == '\0')
		return (0);
	va_start(arg, fmt);
	size = ft_test(fmt, &start, arg, &error);
	if (error == 1)
		size = -1;
	else
		check = ft_tab(start, size);
	if (check == -1)
		size = -1;
	va_end(arg);
	ft_lstclear_pf(&start);
	return (size);
}

//int	main()
//{
//	//char	str[] = "hello";
//	int		i;
//	int	*b;
//	unsigned long p;
//
//	i = 124363467;
//	b = &i;
//	p = 36027577325496340;
//	//printf("---- TEST VRAI ----\n");
//	//printf("%d\n", printf("%c%s%sok%c0ok%xdac\n" , 0 ,str, str, 0 , i));
//	//printf("---- TEST MOI ----\n");
//	//ft_printf("%d\n", ft_printf("%c%s%sok%c0ok%xdac\n", 0,str, str, 0, i));
//
//	//printf("%s",ft_itoa_address(p));
//	printf("---- TEST VRAI ----\n");
//	printf("%d\n", printf("%p", NULL));
//	printf("---- TEST MOI ----\n");
//	ft_printf("%d\n", ft_printf("%p", NULL));
//	return (0);
//}
