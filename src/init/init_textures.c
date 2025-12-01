/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 23:38:01 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 23:38:02 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_mlx_image(t_image *image)
{
	image->addr = mlx_get_data_addr(
			image->image,
			&image->bpp,
			&image->line_len,
			&image->endian
			);
}

void	set_image_struct(void *mlx, t_image *image, char *path)
{
	image->image = mlx_xpm_file_to_image(
			mlx, path, &image->width, &image->height);
	if (!image->image)
		exit_error("Xpm file error\n");
	set_mlx_image(image);
}

void	init_engine(t_data *data, t_paths paths)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	data->image.image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(
			data->image.image,
			&data->image.bpp,
			&data->image.line_len,
			&data->image.endian
			);
	set_image_struct(data->mlx, &data->textures.north, paths.north);
	set_image_struct(data->mlx, &data->textures.east, paths.east);
	set_image_struct(data->mlx, &data->textures.south, paths.south);
	set_image_struct(data->mlx, &data->textures.west, paths.west);
	data->textures.ceiling = paths.ceiling;
	data->textures.floor = paths.floor;
}
