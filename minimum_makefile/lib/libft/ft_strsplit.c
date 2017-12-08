/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:36:40 by gtertysh          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:37 by gtertysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *str, char c)
{
	int		words;
	int		has_word;

	words = 0;
	has_word = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		while (*str != c && *str)
		{
			str++;
			has_word = 1;
		}
		if (has_word)
			words++;
		has_word = 0;
	}
	return (words);
}

static int	fill_table(char const *str, char **table, char c)
{
	int		chars;
	int		char_position;
	int		word_position;

	word_position = 0;
	while (*str)
	{
		chars = 0;
		char_position = 0;
		while (*str == c)
			str++;
		while (*str != c && *str && ++chars)
			str++;
		if (chars != 0)
		{
			if (!(table[word_position] = malloc(sizeof(char) * (chars + 1))))
				return (1);
			while (chars)
				table[word_position][char_position++] = *(str - chars--);
			table[word_position++][char_position] = '\0';
		}
	}
	table[word_position] = 0;
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**table;
	int		words;

	table = NULL;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!words)
	{
		if (!(table = (char **)malloc(sizeof(char *))))
			return (NULL);
	}
	else if (!(table = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	if (fill_table(s, table, c))
		return (table);
	return (table);
}
