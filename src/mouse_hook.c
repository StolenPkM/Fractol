/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 18:45:18 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/29 13:55:24 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook_j(int button, int x, int y, t_env *e)
{
	if (button == 5 || button == 1)
	{
		e->x2 = x;
		e->y2 = y;
		e->x1 = (x / e->zoom + e->x1) - ((e->zoom * 1.3) / 2);
		e->x1 += ((e->zoom * 1.3) / 2) - (x / (e->zoom * 1.3));
		e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.3) / 2);
		e->y1 += ((e->zoom * 1.3) / 2) - (y / (e->zoom * 1.3));
		e->zoom *= 1.3;
		e->iter_max++;
	}
	if (button == 4 || button == 2)
	{
		e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.3) / 2);
		e->x1 += ((e->zoom / 1.3) / 2) - (e->x2 / (e->zoom / 1.3));
		e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.3) / 2);
		e->y1 += ((e->zoom / 1.3) / 2) - (e->y2 / (e->zoom / 1.3));
		e->zoom /= 1.3;
		e->iter_max--;
	}
	mlx_clear_window(e->mlx, e->win);
	redraw_j(e);
	return (1);
}

int		mouse_hook_m(int button, int x, int y, t_env *e)
{
	if (button == 5 || button == 1)
	{
		e->x2 = x;
		e->y2 = y;
		e->x1 = (x / e->zoom + e->x1) - ((e->zoom * 1.3) / 2);
		e->x1 += ((e->zoom * 1.3) / 2) - (x / (e->zoom * 1.3));
		e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.3) / 2);
		e->y1 += ((e->zoom * 1.3) / 2) - (y / (e->zoom * 1.3));
		e->zoom *= 1.3;
		e->iter_max++;
	}
	if (button == 4 || button == 2)
	{
		e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.3) / 2);
		e->x1 += ((e->zoom / 1.3) / 2) - (e->x2 / (e->zoom / 1.3));
		e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.3) / 2);
		e->y1 += ((e->zoom / 1.3) / 2) - (e->y2 / (e->zoom / 1.3));
		e->zoom /= 1.3;
		e->iter_max--;
	}
	mlx_clear_window(e->mlx, e->win);
	redraw_m(e);
	return (1);
}

int		mouse_hook_s(int button, int x, int y, t_env *e)
{
	if (button == 5 || button == 1)
	{
		e->x2 = x;
		e->y2 = y;
		e->x1 = (x / e->zoom + e->x1) - ((e->zoom * 1.3) / 2);
		e->x1 += ((e->zoom * 1.3) / 2) - (x / (e->zoom * 1.3));
		e->y1 = (y / e->zoom + e->y1) - ((e->zoom * 1.3) / 2);
		e->y1 += ((e->zoom * 1.3) / 2) - (y / (e->zoom * 1.3));
		e->zoom *= 1.3;
		e->iter_max++;
	}
	if (button == 4 || button == 2)
	{
		e->x1 = (e->x2 / e->zoom + e->x1) - ((e->zoom / 1.3) / 2);
		e->x1 += ((e->zoom / 1.3) / 2) - (e->x2 / (e->zoom / 1.3));
		e->y1 = (e->y2 / e->zoom + e->y1) - ((e->zoom / 1.3) / 2);
		e->y1 += ((e->zoom / 1.3) / 2) - (e->y2 / (e->zoom / 1.3));
		e->zoom /= 1.3;
		e->iter_max--;
	}
	mlx_clear_window(e->mlx, e->win);
	redraw_s(e);
	return (1);
}

int		mouse_j(int x, int y, t_env *e)
{
	if (e->moov % 2)
	{
		if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		{
			if (x < WIDTH / 2 && y < HEIGHT / 2)
				e->c_r += 0.04;
			if (x > WIDTH / 2 && y < HEIGHT / 2)
				e->c_r -= 0.04;
			if (x < WIDTH / 2 && y > HEIGHT / 2)
				e->c_i += 0.04;
			if (x > WIDTH / 2 && y > HEIGHT / 2)
				e->c_i -= 0.04;
			redraw_j(e);
		}
	}
	return (0);
}
