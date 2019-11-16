/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:03:52 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/13 17:41:15 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_fractol		*fr;

	fr = (t_fractol *)malloc(sizeof(t_fractol));
	if (argc == 3 && argc--)
		if (fork())
			argv[1] = argv[2];
	if (argc == 2 && (!ft_strcmp(argv[1], "1") || !ft_strcmp(argv[1], "2") ||
		!ft_strcmp(argv[1], "3") || !ft_strcmp(argv[1], "4") ||
		!ft_strcmp(argv[1], "5")))
		fr->fr_set = ft_atoi(argv[1]);
	else
		return (write(1, "please use: ./fractol [ 1 | 2 | 3 | 4 | 5 ]\n", 44));
	make_window(fr);
	make_threads(fr);
	mlx_hook(fr->win_ptr, 2, 0, keyboard, fr);
	mlx_hook(fr->win_ptr, 4, 0, mouse, fr);
	if (!ft_strcmp(argv[1], "3"))
		mlx_hook(fr->win_ptr, 6, 0, julia_iterate, fr);
	mlx_loop(fr->mlx_ptr);
	free(fr);
	return (0);
}
