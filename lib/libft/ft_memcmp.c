/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:58:35 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 18:58:36 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return ((*(unsigned char *)ptr1 - *(unsigned char *)ptr2));
		ptr1++;
		ptr2++;
	}
	return (0);
}
