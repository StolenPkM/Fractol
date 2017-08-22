/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 11:58:39 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/29 13:41:41 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		fract_error(void)
{
	ft_putstr("Usage : ./fractol [MJS]\n");
	ft_putstr("M -> Mandelbrot\n");
	ft_putstr("J -> Julia\n");
	ft_putstr("S -> Sword\n");
}

void		init_env(t_env *e, char *argv)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, HEIGHT, WIDTH, "Fractol by pabonnin");
	e->img = mlx_new_image(e->win, HEIGHT, WIDTH);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->endian));
	if (!(ft_strcmp("M", argv)))
		init_m(e);
	else if (!(ft_strcmp("J", argv)))
		init_j(e);
	else if (!(ft_strcmp("S", argv)))
		init_s(e);
}

int			main(int argc, char **argv)
{
	t_env	e;

	if (argc == 2)
	{
		if (!(ft_strcmp("M", argv[1])))
			pick_m(&e, argv[1]);
		else if (!(ft_strcmp("J", argv[1])))
			pick_j(&e, argv[1]);
		else if (!(ft_strcmp("S", argv[1])))
			pick_s(&e, argv[1]);
		else
			fract_error();
	}
	else
		fract_error();
	return (0);
}
