/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:10:22 by lomeress          #+#    #+#             */
/*   Updated: 2017/02/01 18:52:01 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"
#include "mlx.h"

void	julia(t_mlx st)
{
	st.p.imgx = 800;
	st.p.imgy = 600;
	st.p.x = 0;
	while (st.p.x < st.p.imgx)
	{
		st.p.y = 0;
		while (st.p.y < st.p.imgy)
		{
			st.p.cr = 0.285;
			st.p.zr = st.p.x / st.p.zoom + st.p.x1;
			st.p.zi = st.p.y / st.p.zoom + st.p.y1;
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
