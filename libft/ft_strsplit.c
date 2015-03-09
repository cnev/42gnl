/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnev <cnev@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 23:39:55 by cnev              #+#    #+#             */
/*   Updated: 2013/11/22 23:39:56 by cnev             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t		j;
	size_t		countword;

	j = 0;
	countword = 0;
	while (s[j])
	{
		while (s[j] == c && s[j])
			j++;
		if (s[j] != c && s[j])
		{
			countword = countword + 1;
			while (s[j] != c && s[j])
				j++;
		}
	}
	return (countword);
}

static void		var_init(t_split *var, size_t mod)
{
	if (mod == 0)
	{
		var->i = 0;
		var->k = 0;
		var->start = -1;
		var->len = 0;
		var->wc = 0;
	}
	else if (mod == 1)
	{
		var->len++;
		var->i++;
	}
	if (mod == 2)
	{
		var->start = -1;
		var->len = 0;
		var->k++;
	}
}

char			**ft_strsplit(const char *s, char c)
{
	t_split		*var;
	char		**tab;

	var = (t_split *)malloc(sizeof(t_split));
	var_init(var, 0);
	var->wc = ft_countword(s, c);
	tab = (char **)malloc(sizeof(char *) * (var->wc + 1));
	while (s[var->i] && var->k < var->wc)
	{
		while (s[var->i] != c && s[var->i])
		{
			if (var->start == -1)
				var->start = var->i;
			var_init(var, 1);
		}
		if (var->len != 0)
		{
			tab[var->k] = ft_strsub(s, var->start, var->len);
			var_init(var, 2);
		}
		var->i++;
	}
	tab[var->k] = (char *)malloc(sizeof(char) * 1);
	tab[var->k] = NULL;
	return (tab);
}
