/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:26:24 by amaligno          #+#    #+#             */
/*   Updated: 2025/11/28 00:27:24 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_image *image, t_textures textures)
{
	t_rect	background;

	background.pos.x = 0;
	background.pos.y = 0;
	background.size.y = WIN_HEIGHT;
	background.size.x = WIN_WIDTH;
	background.color = textures.ceiling;
	paint_background(image, background);
	background.pos = (t_vectord){0, WIN_HEIGHT / 2};
	background.color = textures.floor;
	paint_background(image, background);
}

void	draw_rays_3d(t_image *image, t_ray *rays,
	t_player player, t_textures textures)
{
	t_rect	line;
	double	angle;
	double	len;
	int		i;

	i = 0;
	line.size.x = WIN_WIDTH / RAYS;
	line.pos.x = 0;
	while (i < RAYS)
	{
		angle = player.angle - rays[i].angle;
		angle = reset_angle(angle);
		len = (rays[i].len * cos(angle));
		line.size.y = (WIN_HEIGHT) / len;
		line.pos.y = (WIN_HEIGHT - line.size.y) / 2;
		draw_textured_ray(image, line, rays[i], textures);
		line.pos.x += line.size.x;
		i++;
	}
}
