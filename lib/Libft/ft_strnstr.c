/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:00:49 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 19:00:50 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*h;

	if ((!haystack || !needle) && !len)
		return (0);
	i = 0;
	h = (char *)haystack;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (h);
	while (h[i] != '\0' && i < len)
	{
		c = 0;
		while (h[i + c] != '\0' && needle[c] != '\0'
			&& h[i + c] == needle[c] && i + c < len)
			c++;
		if (c == n_len)
			return (h + i);
		i++;
	}
	return (0);
}
