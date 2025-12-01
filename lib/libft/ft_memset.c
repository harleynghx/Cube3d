/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:58:52 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 18:58:53 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s;

	s = (char *)b;
	i = -1;
	while (++i < len)
	{
		s[i] = c;
	}
	return (b);
}

/*int main(void)
{
	int	a = 'h';
	char c[] = "hello";
	int f[6] = {1,2,3,4,5,6};
	int *d = ft_memset(f, 0, 3);
}*/