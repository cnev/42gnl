/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:50:16 by cnev              #+#    #+#             */
/*   Updated: 2013/11/22 20:50:17 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_trim	*var_init(char const *s)
{
	t_trim			*vardef;

	vardef = (t_trim *)malloc(sizeof(t_trim));
	vardef->index = 0;
	vardef->ps = (char *)s;
	vardef->start = 0;
	return (vardef);
}

static int		ft_isntchar(const char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int		ft_nochar(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (!ft_isntchar(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	t_trim			*var;

	var = var_init(s);
	if (s == NULL)
		return (NULL);
	if (ft_nochar(s))
	{
		var->out = (char *)malloc(sizeof(char) * (1));
		var->out[0] = '\0';
		return (var->out);
	}
	var->end = ft_strlen(var->ps) - 1;
	while (ft_isspace(var->ps[var->start]) && var->start <= var->end)
		var->start++;
	while (ft_isspace(var->ps[var->end]) && var->end >= 0)
		var->end--;
	var->len = var->end - var->start + 1;
	var->out = (char *)malloc(sizeof(char) * (var->len + 1));
	while (var->index < var->len)
	{
		var->out[var->index] = var->ps[var->start + var->index];
		var->index++;
	}
	var->out[var->index] = '\0';
	return (var->out);
}
