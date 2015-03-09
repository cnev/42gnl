/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:20:16 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 17:20:17 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s2[index2] && (index2 < n))
	{
		s1[index1] = s2[index2];
		index1++;
		index2++;
	}
	if (ft_strlen(s2) <= n)
	{
		while (index1 < n)
		{
			s1[index1] = '\0';
			index1++;
		}
	}
	return (s1);
}
