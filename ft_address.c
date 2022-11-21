/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:45:38 by mmorue            #+#    #+#             */
/*   Updated: 2022/11/21 17:06:06 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size_address(unsigned long new)
{
	int	size;

	size = 0;
	while (new >= 16)
	{
		new = new / 16;
		size++;
	}
	size++;
	return (size);
}

static char	*fill_tab_address(char *str, unsigned long new, unsigned long i)
{	
	str[0] = '0';
	str[1] = 'x';
	str[i--] = '\0';
	while (new != 0)
	{
		str[i] = "0123456789abcdef"[new % 16];
		new = new / 16;
		i--;
	}
	return (str);
}

char	*ft_itoa_adress(void *n)
{
	unsigned long	i;
	unsigned long	new;
	char			*str;

	new = n;
	i = get_size_address(new);
	str = malloc((i + 3) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	return (fill_tab_address(str, new, i));
}