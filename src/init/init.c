/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 23:38:06 by liyu-her          #+#    #+#             */
/*   Updated: 2025/12/01 23:38:07 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hooks(t_data *data)
{
	mlx_hook(data->window, ON_DESTROY, 0, on_destroy, NULL);
	mlx_hook(data->window, ON_KEY_DOWN, (1L), on_key_down, (void *)data);
	mlx_key_hook(data->window, on_key_up, (void *)data);
	mlx_loop_hook(data->mlx, loop, (void *)data);
}

void	init_map(t_map *map)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	map->width = 0;
	map->length = 0;
	map->wall_size = 1;
	while (map->str[y])
	{
		x = 0;
		while (map->str[y][x])
			x++;
		if (x > map->width)
			map->width = x;
		y++;
		if (y > map->length)
			map->length = y;
	}
}

void	init(t_data *data, t_paths paths)
{
	init_map(&data->map);
	init_engine(data, paths);
	init_hooks(data);
	init_player(&data->player, &data->map);
}
