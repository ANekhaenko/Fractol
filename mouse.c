/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:02:47 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/14 14:56:21 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse(int key, int x, int y, t_fractol *fr)
{
	float		mouse_re;
	float		mouse_im;
	float		zoom_scale;
	float		zoom;

	if (key == 4 || key == 5)
	{
		mouse_re = (float)x / (WIDTH / (fr->max_re - fr->min_re)) + fr->min_re;
		mouse_im = (float)y / (HEIGHT / (fr->max_im - fr->min_im))
					* -1 + fr->max_im;
		if (key == 4)
			zoom = 0.85;
		else
			zoom = 1.15;
		zoom_scale = 1.0 / zoom;
		fr->min_re = scale(mouse_re, fr->min_re, zoom_scale);
		fr->min_im = scale(mouse_im, fr->min_im, zoom_scale);
		fr->max_re = scale(mouse_re, fr->max_re, zoom_scale);
		fr->max_im = scale(mouse_im, fr->max_im, zoom_scale);
		make_threads(fr);
	}
	return (0);
}

float			scale(float start, float end, float zoom_scale)
{
	return (start + ((end - start) * zoom_scale));
}

int				julia_iterate(int x, int y, t_fractol *fr)
{
	if (fr->fix_julia == 1)
	{
		fr->julia_re = 4 * ((float)x / WIDTH - 0.5);
		fr->julia_im = 4 * ((float)(HEIGHT - y) / HEIGHT - 0.5);
		make_threads(fr);
	}
	return (0);
}
