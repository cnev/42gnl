/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:24:19 by cnev              #+#    #+#             */
/*   Updated: 2013/11/20 17:24:19 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	unsigned char	*buffer;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	buffer = (unsigned char*)malloc(sizeof(unsigned char) * (len + 1));
	ft_memcpy(buffer, tmpsrc, len);
	ft_memcpy(tmpdst, buffer, len);
	free(buffer);
	return (tmpdst);
}
