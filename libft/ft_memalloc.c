/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:00:38 by cnev              #+#    #+#             */
/*   Updated: 2013/11/20 15:00:39 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*memory;
	size_t			i;

	memory = (unsigned char*)malloc(size);
	i = 0;
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
