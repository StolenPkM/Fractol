/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 12:38:28 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/28 21:12:17 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	legend(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, WHITE, "Moove = UP/DN/L/R");
	mlx_string_put(e->mlx, e->win, 20, 35, WHITE, "Zoom = + / -");
	mlx_string_put(e->mlx, e->win, 20, 50, WHITE, "Iter = P / M");
	mlx_string_put(e->mlx, e->win, 20, 65, WHITE, "Default = D");
	mlx_string_put(e->mlx, e->win, 20, 80, WHITE, "Exit = ESC");
}

void	fill_pixel(t_env *e)
{
	if (e->i == e->iter_max)
	{
		e->data[(e->s_l * e->y) + (4 * e->x) + 2] = 0;
		e->data[(e->s_l * e->y) + (4 * e->x) + 1] = 0;
		e->data[(e->s_l * e->y) + (4 * e->x)] = 0;
	}
	else
	{
		e->data[(e->s_l * e->y) + (4 * e->x) + 2] =
			(e->i * 255 / e->iter_max) * e->b;
		e->data[(e->s_l * e->y) + (4 * e->x) + 1] =
			(e->i * 255 / e->iter_max) * e->g * e->b;
		e->data[(e->s_l * e->y) + (4 * e->x)] =
			(e->i * 255 / e->iter_max) * e->r * e->g * e->b;
	}
}
