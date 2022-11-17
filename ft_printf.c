/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:09:23 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/17 17:16:06 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include  "list.c"

void	ft_readlst(p_list *start)
{
	while (start->next != NULL)
	{
		printf("%s", start->content);
		start = start->next;
	}
	printf("%s", start->content);
}

int	ft_string(char *str, p_list **start)
{
	p_list	*new;
	char	*strn;

	strn = ft_strdup(str);
	new = ft_lstnew_pf(str);
	ft_lstadd_back_pf(start, new);
	return (ft_strlen(strn));
}

int	ft_char(char c, p_list **start)
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
	//else if (ftm == 'd')
	//else if (ftm == 'i')
	//else if (ftm == 'u')
	//else if (ftm == 'x')
	//else if (ftm == 'X')
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
	ft_test(fmt, &start, arg);
	ft_readlst(start);
	return (0);
}

int	main()
{
	char	str[] = "salut";
	
	printf("---- TEST VRAI ----\n");
	printf("%%%s\n", str);
	printf("---- TEST MOI ----\n");
	ft_printf("%%%s\n", str);
	printf("---- TEST MOI ----\n");
	return (0);
}