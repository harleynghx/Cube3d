/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:58:47 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 18:58:48 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!to && !from)
		return (NULL);
	d = (unsigned char *)to;
	s = (unsigned char *)from;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (to);
}

// int main(void)
// {
// 	char g[] = "34";
// 	char r[] = "123456789";
// 	char *s = ft_memmove(r, r + 2, 5);
// 	printf("%s", s);
// }