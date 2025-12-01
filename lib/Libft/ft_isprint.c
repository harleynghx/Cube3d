/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:57:25 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 18:57:26 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

/*int	main(int argc, char **argv)
{	
	int	f;

	if (argc != 2)
	{
		return(0);
	}
	f = ft_isprint(argv[1]);
	printf("%d", f);
}*/