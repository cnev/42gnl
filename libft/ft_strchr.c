/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:57:51 by cnev              #+#    #+#             */
/*   Updated: 2013/11/21 16:57:52 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	*ptr;

	index = 0;
	ptr = (char *)s;
	while ((s[index] != c) && (s[index] != '\0'))
	{
		index++;
		ptr = (char *)s + index;
	}
	if ((c != '\0') && (s[index] == '\0'))
		return (NULL);
	return (ptr);
}
