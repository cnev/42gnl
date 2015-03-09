/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:00:29 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 12:00:30 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		var_init(t_atoi *var)
{
	var->i = 0;
	var->neg = 0;
	var->result = 0;
}

int				ft_atoi(const char *str)
{
	t_atoi	var;

	var_init(&var);
	while (str[var.i] == '\t' || str[var.i] == '\n' || str[var.i] == '\v'
			|| str[var.i] == '\f' || str[var.i] == '\r' || str[var.i] == ' ')
		var.i++;
	if (str[var.i] == '-')
	{
		var.neg = 1;
		var.i++;
	}
	else if (str[var.i] == '+')
		var.i++;
	while (str[var.i] >= '0' && str[var.i] <= '9')
	{
		var.result = var.result + (str[var.i] - '0');
		if (str[var.i + 1] >= '0' && str[var.i + 1] <= '9')
			var.result = (var.result * 10);
		var.i++;
	}
	if (var.neg == 1)
		var.result = var.result * -1;
	return (var.result);
}
