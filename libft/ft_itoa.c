/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:04:03 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 15:04:04 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int n)
{
	size_t			i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i += 1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_testedge(int n)
{
	char			*str;

	if (n == -2147483648)
	{
		if (!(str = (char *)malloc(sizeof(char) * (12))))
			return (NULL);
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	else
		return (NULL);
}

static t_itoa	*create_var(int n)
{
	t_itoa			*var;

	var = (t_itoa *)malloc(sizeof(t_itoa));
	var->i = 0;
	var->neg = (n < 0) ? 1 : 0;
	var->power = 1;
	var->str = (char *)malloc(ft_intlen(n) + 1);
	return (var);
}

char			*ft_itoa(int n)
{
	t_itoa			*var;

	var = create_var(n);
	if (ft_testedge(n) != NULL)
		return (ft_testedge(n));
	if (n < 0)
		n = -n;
	while (n / var->power >= 10)
		var->power *= 10;
	if (var->neg)
	{
		var->str[var->i] = '-';
		var->i = 1;
	}
	while (var->power > 0)
	{
		var->str[var->i] = n / var->power + '0';
		n = n % var->power;
		var->power /= 10;
		var->i++;
	}
	var->str[var->i] = '\0';
	return (var->str);
}
