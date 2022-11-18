/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:09:23 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/18 16:53:13 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "ft_list.c"
#include "ft_itoa.c"
#include "ft_hexa.c"
#include "ft_hexa_maj.c"

void	ft_readlst(p_list *start)			//Lire la liste
{
	while (start->next != NULL)
	{
		printf("%s", start->content);
		start = start->next;
	}
	printf("%s", start->content);
}

int	ft_di(int i, p_list **start)			//Pour nombre decimal
{
	p_list	*new;
	char	*str;

	str = ft_itoa(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	return (ft_strlen(str));
}

int	ft_u(unsigned int i, p_list **start)			//Pour unsigned int		
{
	p_list	*new;
	char	*str;

	str = ft_itoa_u(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	return (ft_strlen(str));
}

int	ft_x(unsigned int i, p_list **start)			//Pour Hexa minuscule		
{
	p_list	*new;
	char	*str;

	str = ft_itoa_hexa(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	return (ft_strlen(str));
}

int	ft_x_maj(unsigned int i, p_list **start)			//Pour Hexa Majuscule
{
	p_list	*new;
	char	*str;

	str = ft_itoa_hexa_maj(i);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	return (ft_strlen(str));
}

int	ft_string(char *str, p_list **start)	//Pour afficher string
{
	p_list	*new;
	char	*strn;

	strn = ft_strdup(str);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
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
	//else if (ftm == 'p')
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

	start = 0;
	va_start(arg, fmt);
	va_end(arg);
	ft_test(fmt, &start, arg);
	ft_readlst(start);
	return (0);
}

int	main()
{
	char	str[] = "salut";
	unsigned int		i;

	i = 124363467;
	printf("---- TEST VRAI ----\n");
	printf("%sokok%x\n", str, i);
	printf("---- TEST MOI ----\n");
	ft_printf("%sokok%x\n",str, i);
	return (0);
}