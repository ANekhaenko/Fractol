/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 22:59:48 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/14 14:37:13 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			keyboard(int key, t_fractol *fr)
{
	if (key == 53)
		exit(0);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		arrows(key, fr);
	else if (key == 27)
		fr->max_iter--;
	else if (key == 24)
		fr->max_iter++;
	else if (key == 15)
		set_default(fr);
	else if (key == 3)
	{
		if (fr->fix_julia == 0)
			fr->fix_julia = 1;
		else
			fr->fix_julia = 0;
	}
	make_threads(fr);
	return (0);
}

void		arrows(int key, t_fractol *fr)
{
	if (key == 124)
	{
		fr->min_re -= 0.1;
		fr->max_re -= 0.1;
	}
	else if (key == 123)
	{
		fr->min_re += 0.1;
		fr->max_re += 0.1;
	}
	else if (key == 125)
	{
		fr->min_im += 0.1;
		fr->max_im += 0.1;
	}
	else if (key == 126)
	{
		fr->min_im -= 0.1;
		fr->max_im -= 0.1;
	}
}
