/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:11:00 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/29 13:19:08 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		m_key_hook(int key, t_env *e)
{
	(key == ESC) ? quit(e) : 0;
	direction(key, e, "mandel");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? redraw_m(e) : 0;
	(key == MIN) ? e->zoom /= 1.1 : 0;
	(key == MIN) ? redraw_m(e) : 0;
	(key == P) ? e->iter_max += 20 : 0;
	(key == P) ? redraw_m(e) : 0;
	if (key == M)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == M) ? redraw_m(e) : 0;
	(key == D) ? init_m(e) : 0;
	(key == D) ? redraw_m(e) : 0;
	return (1);
}

int		j_key_hook(int key, t_env *e)
{
	(key == ESC) ? quit(e) : 0;
	direction(key, e, "julia");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? redraw_j(e) : 0;
	(key == MIN) ? e->zoom /= 1.1 : 0;
	(key == MIN) ? redraw_j(e) : 0;
	(key == P) ? e->iter_max += 20 : 0;
	(key == P) ? redraw_j(e) : 0;
	if (key == M)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == M) ? redraw_j(e) : 0;
	(key == D) ? init_j(e) : 0;
	(key == D) ? redraw_j(e) : 0;
	(key == 1) ? e->moov++ : 0;
	return (1);
}

int		s_key_hook(int key, t_env *e)
{
	(key == ESC) ? quit(e) : 0;
	direction(key, e, "sword");
	(key == PLUS) ? e->zoom *= 1.1 : 0;
	(key == PLUS) ? redraw_s(e) : 0;
	(key == MIN) ? e->zoom /= 1.1 : 0;
	(key == MIN) ? redraw_s(e) : 0;
	(key == P) ? e->iter_max += 20 : 0;
	(key == M) ? redraw_s(e) : 0;
	if (key == M)
		(e->iter_max -= 20) == 0 ? e->iter_max = 20 : 0;
	(key == M) ? redraw_s(e) : 0;
	(key == D) ? init_s(e) : 0;
	(key == D) ? redraw_s(e) : 0;
	return (1);
}
