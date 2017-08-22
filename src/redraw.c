/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 13:56:22 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/28 20:53:18 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_m(t_env *e)
{
	mandelbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	legend(e);
}

void	redraw_j(t_env *e)
{
	julia(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	legend(e);
}

void	redraw_s(t_env *e)
{
	sword(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	legend(e);
}
