/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:59:18 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 18:59:19 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// size_t	ft_strlen(const char *str)
// {
// 	int		num;
// 	char	*ptr;

// 	num = 0;
// 	ptr = (char *)str;
// 	while (true)
// 	{
// 		if (*ptr == '\0')
// 			break ;
// 		ptr++;
// 		num++;
// 	}
// 	return (num);
// }

static size_t	wordcount(const char *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while ((s[i] != '\0') && (s[i] == c))
		i++;
	while (s[i] != '\0')
	{
		count++;
		while ((s[i] != '\0') && (s[i] != c))
			i++;
		while ((s[i] != '\0') && (s[i] == c))
			i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != c))
		i++;
	return (i);
}

static char	*wordsalloc(char const *s, char c)
{
	size_t	i;
	char	*new;
	size_t	len;

	i = 0;
	len = word_len(s, c);
	new = malloc((len + 1) * (sizeof(char)));
	if (!new)
		return (0);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	**splitter(char **words, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
			words[j++] = wordsalloc(&s[i], c);
		while ((s[i] != '\0') && (s[i] != c))
			i++;
	}
	words[j] = 0;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	words = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !words)
		return (0);
	words = splitter(words, s, c);
	return (words);
}

// // int	main(void)
// // {
// // 	char	**strs;

// // 	strs = ft_split("--12345-678-", '-');
// // 	printf("[%s]\n", strs[0]);
// // 	printf("[%s]\n", strs[1]);
// // 	// printf("%s\n", strs[2]);
// // 	// printf("%s\n", strs[3]);
// // 	// printf("%s\n", strs[4]);
// // 	// printf("%s\n", strs[5]);
// // }

// // int main(int c, char **str)
// // {
// // 	char **strs = ft_split(str[1], str[2][0]);
// // 	printf("[%s]\n", strs[0]);
// // 	printf("[%s]\n", strs[1]);
// // 	printf("%s\n", strs[2]);
// // 	printf("%s\n", strs[3]);
// // }
