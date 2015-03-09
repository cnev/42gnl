/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:04:47 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 18:04:48 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*ps1;
	const char	*ps2;

	if (*s2 == 0)
		return ((char *)s1);
	while (*s1 != 0)
	{
		ps1 = s1;
		ps2 = s2;
		while (*ps1 == *ps2 && *ps1 != 0 && *ps2 != 0)
		{
			ps1++;
			ps2++;
		}
		if (*ps2 == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
