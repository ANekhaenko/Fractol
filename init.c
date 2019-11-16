/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:52:42 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/13 16:53:06 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_window(t_fractol *fr)
{
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	fr->img = mlx_new_image(fr->mlx_ptr, WIDTH, HEIGHT);
	fr->addr = mlx_get_data_addr(fr->img, &fr->bpp, &fr->sl, &fr->end);
	set_default(fr);
}

void	set_default(t_fractol *fr)
{
	fr->max_iter = 20;
	fr->max_re = 2.0;
	fr->max_im = 2.0;
	fr->min_re = -2.0;
	fr->min_im = -2.0;
	fr->julia_re = -0.4;
	fr->julia_im = 0.6;
	fr->fix_julia = 1;
}
