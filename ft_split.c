/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpastran <jpastran@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:13:31 by jimenapastr       #+#    #+#             */
/*   Updated: 2024/02/01 18:32:23 by jpastran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *s, char c)
{
	int	wordcount;
	int	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			wordcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordcount);
}

static int	ft_size_word(char const *s, char c)
{
	int	size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

static char	**ft_fill(char **new, const char *s, char c, int count)
{
	int	words;
	int	len;
	int	i;

	i = 0;
	words = 0;
	while (words < count)
	{
		while (s[i] == c)
			i++;
		len = ft_size_word(&s[i], c);
		new[words] = ft_substr(s, i, len);
		if (!new[words])
		{
			ft_free(new, words);
			return (NULL);
		}
		while (s[i] && s[i] != c)
			i ++;
		words++;
	}
	new[words] = NULL;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**new;

	if (!s)
		return (NULL);
	count = ft_word_count(s, c);
	new = malloc((count + 1) * sizeof(char **));
	if (!new)
		return (NULL);
	return (ft_fill(new, s, c, count));
}
