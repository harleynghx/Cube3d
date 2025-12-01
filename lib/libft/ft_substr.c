/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:01:15 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 19:01:16 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	allocsize(const char *s, size_t start, size_t len)
{
	if (ft_strlen(s) < len)
		return (ft_strlen(s) - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (allocsize(s, start, len) + 1));
	i = 0;
	if (!sub)
		return (0);
	while ((*(s + start + i) != '\0') && (i < len))
	{
		sub[i] = *(s + start + i);
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// int main(void)
// {
// 	char *s = ft_substr("tripouille", 0, 100);
// 	printf("%s$\n", s);
// }