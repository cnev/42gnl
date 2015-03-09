/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:37:56 by cnev              #+#    #+#             */
/*   Updated: 2013/11/19 12:37:56 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*output;
	size_t	index;

	len = ft_strlen(s1);
	output = (char *)malloc(sizeof(char) * (len + 1));
	index = 0;
	while (s1[index])
	{
		output[index] = s1[index];
		index++;
	}
	output[index] = '\0';
	return (output);
}
