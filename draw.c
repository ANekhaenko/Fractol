/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:36:31 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/14 15:12:26 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				make_threads(t_fractol *fr)
{
	t_fractol		new_fr[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	fr->step = (fr->max_re - fr->min_re) / (WIDTH - 1);
	while (i < THREADS)
	{
		new_fr[i] = *fr;
		new_fr[i].start = i * (HEIGHT / THREADS);
		new_fr[i].finish = (i + 1) * (HEIGHT / THREADS);
		pthread_create(&threads[i], NULL, (void *)draw, (void *)&new_fr[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img, 0, 0);
}

void				draw(t_fractol *fr)
{
	fr->y = fr->start;
	while (fr->y < fr->finish)
	{
		fr->dot_im = fr->max_im - fr->y * fr->step;
		fr->x = 0;
		while (fr->x < WIDTH)
		{
			fr->dot_re = fr->min_re + fr->x * fr->step;
			fr->temp_dot_re = fr->dot_re;
			fr->temp_dot_im = fr->dot_im;
			fr->iter = 0;
			while ((pow(fr->temp_dot_re, 2.0) + pow(fr->temp_dot_im, 2.0) <= 4
					&& fr->iter < fr->max_iter))
				wtf(fr);
			calculate_color(fr);
			fr->x++;
		}
		fr->y++;
	}
}

void				wtf(t_fractol *fr)
{
	if (fr->fr_set == 1)
		mandelbrot(fr);
	else if (fr->fr_set == 2)
		burning_ship(fr);
	else if (fr->fr_set == 3)
		julia(fr);
	else if (fr->fr_set == 4)
		celtic(fr);
	else if (fr->fr_set == 5)
		buffalo(fr);
}
