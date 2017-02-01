/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:34:37 by lomeress          #+#    #+#             */
/*   Updated: 2017/02/01 19:08:27 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>

typedef	struct		s_mouse
{
	int				i;
	double			tmpx;
	double			tmpy;
}					t_mouse;

typedef	struct		s_point
{
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			imgx;
	double			imgy;
	int				iter;
	double			cr;
	double			ci;
	double			zr;
	double			zi;
	double			i;
	double			zoom;
	double			tmp;
	int				color;
	int				ch;
}					t_point;

typedef	struct		s_mlx
{
	int				*mlx;
	int				*win;
	int				*img;
	int				bpx;
	int				size;
	int				end;
	char			*gda;
	double			zoomx;
	double			zoomy;
	struct s_point	p;
	struct s_mouse	m;
}					t_mlx;

void				mandelbrot(t_mlx st);
void				julia(t_mlx st);
void				burningship(t_mlx st);
void				julio(t_mlx st);
t_mlx				calc(t_mlx st);

#endif
