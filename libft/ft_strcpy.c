/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:08:44 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 17:08:45 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s2[index2] != '\0')
	{
		s1[index1] = s2[index2];
		index1++;
		index2++;
	}
	s1[index1] = '\0';
	return (s1);
}
