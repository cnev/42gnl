/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:05:57 by cnev              #+#    #+#             */
/*   Updated: 2013/11/21 14:05:58 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*ptr1;
	const char	*ptr2;
	size_t		index;
	size_t		index2;

	index = 0;
	index2 = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && (index < n))
	{
		ptr1 = s1;
		ptr2 = s2;
		while (((index2 + index) < n) && (*ptr1 == *ptr2) && (*ptr2 != '\0'))
		{
			ptr1++;
			ptr2++;
			index2++;
		}
		if (*ptr2 == '\0')
			return ((char *)s1);
		s1++;
		index++;
	}
	return (NULL);
}
