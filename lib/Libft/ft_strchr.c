/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:59:24 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 18:59:25 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char			*f;
	unsigned char	r;

	r = c;
	if (r == '\0')
	{
		f = (char *)(str + ft_strlen(str));
		return (f);
	}
	while (*str != '\0')
	{
		if (*str == r)
		{
			f = (char *)str;
			return (f);
		}
		str++;
	}
	return (NULL);
}

/*int main(int c, char **str)
{
	char *f = ft_strchr(str[1], 'l');
	printf("%s", f);
}*/