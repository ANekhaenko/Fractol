/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:58:48 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/14 15:21:19 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot(t_fractol *fr)
{
	fr->new_temp_dot_re = pow(fr->temp_dot_re, 2.0)
		- pow(fr->temp_dot_im, 2.0) + fr->dot_re;
	fr->temp_dot_im = 2.0 * fr->temp_dot_re * fr->temp_dot_im + fr->dot_im;
	fr->temp_dot_re = fr->new_temp_dot_re;
	fr->iter++;
}

void				burning_ship(t_fractol *fr)
{
	fr->new_temp_dot_re = pow(fr->temp_dot_re, 2.0)
		- pow(fr->temp_dot_im, 2.0) + fr->dot_re;
	fr->temp_dot_im = -2.0 * fabs(fr->temp_dot_re * fr->temp_dot_im)
	+ fr->dot_im;
	fr->temp_dot_re = fr->new_temp_dot_re;
	fr->iter++;
}

void				julia(t_fractol *fr)
{
	fr->new_temp_dot_re = pow(fr->temp_dot_re, 2.0)
		- pow(fr->temp_dot_im, 2.0) + fr->julia_re;
	fr->temp_dot_im = 2.0 * fr->temp_dot_re * fr->temp_dot_im + fr->julia_im;
	fr->temp_dot_re = fr->new_temp_dot_re;
	fr->iter++;
}

void				celtic(t_fractol *fr)
{
	fr->new_temp_dot_re = fabs(pow(fr->temp_dot_re, 2.0)
		- pow(fr->temp_dot_im, 2.0)) + fr->dot_re;
	fr->temp_dot_im = 2.0 * (fr->temp_dot_re * fr->temp_dot_im) + fr->dot_im;
	fr->temp_dot_re = fr->new_temp_dot_re;
	fr->iter++;
}

void				buffalo(t_fractol *fr)
{
	fr->new_temp_dot_re = fabs(pow(fr->temp_dot_re, 2.0)
		- pow(fr->temp_dot_im, 2.0)) + fr->dot_re;
	fr->temp_dot_im = -2.0 * fr->temp_dot_re
		* fabs(fr->temp_dot_im) + fr->dot_im;
	fr->temp_dot_re = fr->new_temp_dot_re;
	fr->iter++;
}
