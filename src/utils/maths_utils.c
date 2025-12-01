/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:02:55 by amaligno          #+#    #+#             */
/*   Updated: 2025/11/29 15:26:51 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_hyp(t_vectord side1, t_vectord side2)
{
	return (sqrt((pow(side1.x - side2.x, 2)) + (pow(side1.y - side2.y, 2))));
}

double	reset_angle(double angle)
{
	if (angle < 0)
		angle += M_PI * 2;
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	return (angle);
}
