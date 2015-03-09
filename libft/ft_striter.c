/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:17:11 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 16:17:13 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i])
		{
			f(&s[i]);
			i++;
		}
	}
}
