/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:15:12 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 18:15:12 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_dst;
	size_t	i_src;

	i_src = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i_dst = ft_strlen(dst);
	while (src[i_src])
	{
		if (i_dst + i_src < size - 1)
			dst[i_dst + i_src] = src[i_src];
		else
			dst[i_dst + i_src] = '\0';
		i_src++;
	}
	if (i_src != size)
		dst[i_dst + i_src] = '\0';
	return (i_dst + i_src);
}
