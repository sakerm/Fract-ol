/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:37:26 by lomeress          #+#    #+#             */
/*   Updated: 2017/02/01 19:18:26 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>

int		my_key_funct(int kc, void *param)
{
	t_mlx	*st;
	int		i;

	if (kc == 53 || kc == 83)
	{
		st = (t_mlx*)param;
		mlx_destroy_image(st->mlx, st->img);
		st->img = mlx_new_image(st->mlx, 800, 600);
		st->gda = mlx_get_data_addr(st->img, &st->bpx, &st->size, &st->end);
		kc == 53 ? exit(1) : NULL;
		kc == 83 && st->p.color != 12 ? st->p.color += 1 : (st->p.color -= 11);
		st->p.ch == 1 ? mandelbrot(*st) : i == 0;
		st->p.ch == 2 ? julia(*st) : i == 0;
		st->p.ch == 3 ? burningship(*st) : i == 0;
		st->p.ch == 4 ? julio(*st) : i == 0;
		mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	}
	return (0);
}

int		my_mouse_funct(int x, int y, void *param)
{
	t_mlx	*st;
	int		i;

	if (x < 0 || x >= 800 || y < 0 || y >= 600)
		return (0);
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
	st = (t_mlx*)param;
	mlx_destroy_image(st->mlx, st->img);
	st->img = mlx_new_image(st->mlx, 800, 600);
	st->gda = mlx_get_data_addr(st->img, &st->bpx, &st->size, &st->end);
	x > 300 && x < 600 && y > 200 && y < 450 && st->p.ci < 1 ?
		st->p.ci += 0.01 : (st->p.ci -= 0.01);
	st->p.ch == 1 ? mandelbrot(*st) : i == 0;
	st->p.ch == 2 ? julia(*st) : i == 0;
	st->p.ch == 3 ? burningship(*st) : i == 0;
	st->p.ch == 4 ? julio(*st) : i == 0;
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	return (0);
}

int		my_mouse_mov(int kc, int x, int y, int *param)
{
	int		i;
	t_mlx	*st;

	i = 0;
	st = (t_mlx*)param;
	st->m.tmpx = (x / st->p.zoom) + st->p.x1;
	st->m.tmpy = (y / st->p.zoom) + st->p.y1;
	if (kc)
	{
		mlx_destroy_image(st->mlx, st->img);
		st->img = mlx_new_image(st->mlx, 800, 600);
		st->gda = mlx_get_data_addr(st->img, &st->bpx, &st->size, &st->end);
		kc == 1 ? st->p.zoom /= 0.8 : i == 0;
		kc == 2 ? st->p.zoom *= 0.8 : i == 0;
		st->p.x1 = st->m.tmpx - (x / st->p.zoom);
		st->p.y1 = st->m.tmpy - (y / st->p.zoom);
		kc == 1 ? st->p.iter /= 0.95 : st->p.iter--;
		st->p.ch == 1 ? mandelbrot(*st) : i == 0;
		st->p.ch == 2 ? julia(*st) : i == 0;
		st->p.ch == 3 ? burningship(*st) : i == 0;
		st->p.ch == 4 ? julio(*st) : i == 0;
		mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	}
	return (0);
}

t_mlx	*error(int argc, char **argv, t_mlx *st)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0 ||
			(ft_strcmp(argv[1], "burningship") == 0))
	{
		st->p.x1 = -2.1;
		st->p.y1 = -1.2;
		st->p.x2 = 0.5;
		st->p.y2 = 1.2;
		ft_strcmp(argv[1], "mandelbrot") == 0 ? st->p.ch = 1 : (st->p.ch == 3);
		ft_strcmp(argv[1], "burningship") == 0 ? st->p.ch = 3 : (st->p.ch == 1);
		return (st);
	}
	if (ft_strcmp(argv[1], "julia") == 0 || ft_strcmp(argv[1], "julio") == 0)
	{
		st->p.x1 = -1;
		st->p.y1 = -1.2;
		st->p.x2 = 1;
		st->p.y2 = 1.2;
		st->p.ci = 0.01;
		strcmp(argv[1], "julia") == 0 ? st->p.ch = 2 : st->p.ch == 4;
		strcmp(argv[1], "julio") == 0 ? st->p.ch = 4 : st->p.ch == 2;
		return (st);
	}
	ft_putstr("usage: ./fractol \"mandelbrot\" or \"julia\"");
	ft_putstr("or \"burningship\" or \"julio\"");
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_mlx st;

	if (argc != 2)
		return (0);
	if (!error(argc, argv, &st))
		return (0);
	st.mlx = mlx_init();
	st.win = mlx_new_window(st.mlx, 800, 600, "fractol");
	st.img = mlx_new_image(st.mlx, 800, 600);
	st.gda = mlx_get_data_addr(st.img, &st.bpx, &st.size, &st.end);
	mlx_key_hook(st.win, my_key_funct, &st);
	mlx_mouse_hook(st.win, my_mouse_mov, &st);
	mlx_hook(st.win, 6, (1L << 6), my_mouse_funct, &st);
	st.p.iter = 40;
	st.p.zoom = 280;
	st.p.ch == 1 ? mandelbrot(st) : NULL;
	st.p.ch == 2 ? julia(st) : NULL;
	st.p.ch == 3 ? burningship(st) : NULL;
	st.p.ch == 4 ? julio(st) : NULL;
	mlx_loop(st.mlx);
	return (0);
}
