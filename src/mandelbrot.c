/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:00:04 by lomeress          #+#    #+#             */
/*   Updated: 2017/02/01 19:14:56 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"
#include "mlx.h"

int		color(int a, int i)
{
	i += a;
	if (a < 14)
		return (2 * i + 2);
	if (a > 30 && a < 40)
		return (7 * i - 6);
	if (a > 50 && a < 60)
		return (9 * i + 3);
	if (a > 100)
		return (15 * i - 1);
	return (19 * i - 5);
}

t_mlx	calc(t_mlx st)
{
	if (st.p.i == st.p.iter)
	{
		*(unsigned*)(st.gda + (int)st.p.x * (st.bpx / 8)
				+ (int)st.p.y * st.size) = 0xFFFFAA;
	}
	else
	{
		*(unsigned*)(st.gda + (int)st.p.x * (st.bpx / 8) +
				(int)st.p.y * st.size) = 0x3366FF * color(st.p.color, st.p.i);
	}
	st.p.y++;
	return (st);
}

t_mlx	declaration(t_mlx st)
{
	st.p.imgx = 800;
	st.p.imgy = 600;
	st.p.x = 0;
	return (st);
}

void	mandelbrot(t_mlx st)
{
	st = declaration(st);
	while (st.p.x < st.p.imgx)
	{
		st.p.y = 0;
		while (st.p.y < st.p.imgy)
		{
			st.p.cr = st.p.x / st.p.zoom + st.p.x1;
			st.p.ci = st.p.y / st.p.zoom + st.p.y1;
			st.p.zr = 0;
			st.p.zi = 0;
			st.p.i = 0;
			while (st.p.zr * st.p.zr + st.p.zi *
					st.p.zi < 4 && st.p.i < st.p.iter)
			{
				st.p.tmp = st.p.zr;
				st.p.zr = st.p.zr * st.p.zr - st.p.zi * st.p.zi + st.p.cr;
				st.p.zi = 2 * st.p.zi * st.p.tmp + st.p.ci;
				st.p.i += 1;
			}
			st = calc(st);
		}
		st.p.x++;
	}
	mlx_put_image_to_window(st.mlx, st.win, st.img, 0, 0);
}
