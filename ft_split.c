/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:17:29 by rbicanic          #+#    #+#             */
/*   Updated: 2022/02/02 18:21:46 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_sdup(const char *src, const char c)
{
	char	*dest;
	int		len;

	len = 0;
	if (src == NULL)
		return (NULL);
	while (src[len] && src[len] != c)
		len++;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	len = 0;
	while (src[len] && src[len] != c)
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

static int	count_words(const char *str, const char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i])
			i++;
	}
	return (words);
}

static void	free_strs(char **strs, int index)
{
	while (index > 0)
	{
		free(strs[index]);
		index--;
	}
	free(strs[index]);
	free(strs);
}

static char	**create_strs(char const *s, char c, char **strs)
{
	int		j;

	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		strs[j] = ft_sdup(&(*s), c);
		if (strs[j] == NULL)
		{
			free_strs(strs, j);
			return (NULL);
		}
		while (*s != c && *s)
			s++;
		j++;
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (s == NULL)
		return (NULL);
	strs = malloc(sizeof(*strs) * (count_words(s, c) + 1));
	if (strs == NULL)
	{
		clear_all_lists(lsts()->list_a, lsts()->list_b, lsts()->inst);
		exit(EXIT_FAILURE);
	}
	strs = create_strs(s, c, strs);
	return (strs);
}
