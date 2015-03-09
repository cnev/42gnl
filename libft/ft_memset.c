/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:04:23 by cnev              #+#    #+#             */
/*   Updated: 2013/11/20 15:04:24 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			index;

	index = 0;
	tmp = (unsigned char*)b;
	while (index < len)
	{
		tmp[index] = (unsigned char)c;
		index++;
	}
	return (tmp);
}
