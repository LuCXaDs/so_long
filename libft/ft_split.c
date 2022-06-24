/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:35:07 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 14:30:49 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_tab(const char *s, char c, char **final_tab);
static size_t	ft_words(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**final_tab;

	if (!s)
		return (NULL);
	final_tab = malloc(sizeof(char *) * (ft_words(s, c)));
	if (!final_tab)
		return (NULL);
	final_tab = ft_tab(s, c, final_tab);
	return (final_tab);
}

static size_t	ft_words(const char *s, char c)
{
	size_t	i;
	size_t	cmpt;

	i = 0;
	if (s[i] == c || s[i] == 0)
		cmpt = 0;
	else
		cmpt = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			cmpt++;
		i++;
	}
	return (cmpt + 1);
}

char	**ft_tab(const char *s, char c, char **final_tab)
{
	unsigned int	i;
	size_t			len;
	size_t			y;

	y = 0;
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i + len] != c && s[i + len])
			len++;
		if (len > 0)
		{
			final_tab[y] = ft_substr(s, i, len);
			y++;
		}
		i += len;
		while (s[i] == c && s[i])
			i++;
		len = 0;
	}
	final_tab[y] = NULL;
	return (final_tab);
}
