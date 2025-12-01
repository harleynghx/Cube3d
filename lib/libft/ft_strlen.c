/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:00:28 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 19:00:29 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int		num;
	char	*ptr;

	num = 0;
	ptr = (char *)str;
	while (true)
	{
		if (*ptr == '\0')
			break ;
		ptr++;
		num++;
	}
	return (num);
}
