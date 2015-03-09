/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:41:30 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 15:41:30 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	index;

	if (size == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (size + 1));
	index = 0;
	while (index <= size)
	{
		str[index] = '\0';
		index++;
	}
	return (str);
}
