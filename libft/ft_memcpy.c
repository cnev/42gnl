/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:15:48 by cnev              #+#    #+#             */
/*   Updated: 2013/11/20 17:15:49 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;
	size_t			index;

	index = 0;
	tmp = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while (index < n)
	{
		tmp[index] = (unsigned char)tmp2[index];
		index++;
	}
	return (tmp);
}
