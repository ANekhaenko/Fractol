/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:51:36 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/14 17:11:19 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				calculate_color(t_fractol *fr)
{
	fr->t = (float)fr->iter / (float)fr->max_iter;
	fr->i = (fr->x * 32 >> 3) + (fr->y * WIDTH * 4);
	if (fr->t == 1)
		get_black(fr);
	else
		get_color(fr);
}

void				get_black(t_fractol *fr)
{
	fr->addr[fr->i] = (char)0;
	fr->addr[++fr->i] = (char)0;
	fr->addr[++fr->i] = (char)0;
	fr->addr[++fr->i] = (char)0;
}

void				get_color(t_fractol *fr)
{
	fr->addr[fr->i] = (char)(6 * pow((1 - fr->t), 3) * fr->t * 255);
	fr->addr[++fr->i] = (char)(8.5 * (1 - fr->t) * pow(fr->t, 3) * 255);
	fr->addr[++fr->i] = (char)(14.5 * pow((1 - fr->t), 2)
						* pow(fr->t, 2) * 255);
	fr->addr[++fr->i] = (char)0;
}
