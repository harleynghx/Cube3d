/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:09 by amaligno          #+#    #+#             */
/*   Updated: 2025/11/29 15:10:56 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* big endian, MSB is the leftmost bit */
/* little endian, LSB is the leftmost bit */
void	img_pix_put(t_image *img, int x, int y, unsigned int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	paint_background(t_image *img, t_rect rect)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < rect.size.y && y + rect.pos.y <= WIN_HEIGHT
		&& x + rect.pos.x <= WIN_WIDTH)
	{
		x = 0;
		while (x < rect.size.x && y + rect.pos.y >= 0)
		{
			if (x + rect.pos.x >= 0)
				img_pix_put(img, x + rect.pos.x, y + rect.pos.y,
					rect.color);
			x++;
		}
		y++;
	}
}
