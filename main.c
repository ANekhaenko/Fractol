/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:07:19 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/06 19:45:31 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define MOD(a) ((a < 0 ) ? -a : a)

void    DrawMandelbrot(int iterations,void	*mlx_ptr, void *win_ptr)
{
    float xTemp, yTemp;
	float x, y, t;
	void			*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				end;
	//int				color = 0xffffff;;
	
	img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	addr = mlx_get_data_addr(img, &bpp, &sl, &end);
	
	for (float a = -2; a < 2; a += 0.001)
	{
		for (float b = -2; b < 2; b += 0.001)
		{
			x = a;
			y = b;
			int iterator = 0; 
			while (iterator < iterations && x*x + y*y < 4)
			{
				xTemp = x * x - y * y + a;  
				yTemp = 2 * x*y + b;
				x = xTemp;
				y = yTemp;
				iterator++;
			}
			t = (float)iterator / (float)iterations;
			if (iterator == iterations)
				mlx_pixel_put(mlx_ptr, win_ptr,	a*300+700, b*300+500, 0x000000);
				//(unsigned int *)addr + (a + pixel.y * WIDTH) * frac->image->bpp)    = mlx_get_color_value(mlx_ptr, color);
			else if (iterator > 6)
				//((unsigned int *)addr)[MOD((int)(b*100)) + MOD((int)(a*100))] = mlx_get_color_value(mlx_ptr, color / iterator);
				mlx_pixel_put(mlx_ptr, win_ptr,	a*300+700, b*300+500, 0xd7afd7 * iterator);
		}
	}
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
}

int			key(int key)
{
	if (key == 53)
		exit(0);
	return(0);
}

int		main(void)
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bpp;
	int				sl;
	int				end;
	int				color;
	
	color = 0xffffff;
	
	int i = -1;
		
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Fractol");
	img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	addr = mlx_get_data_addr(img, &bpp, &sl, &end);
	
	((unsigned int *)addr)[i] = mlx_get_color_value(mlx_ptr, color);
	
	DrawMandelbrot(105,mlx_ptr,win_ptr);
	mlx_hook(win_ptr, 2, 5, key,mlx_ptr);
	mlx_loop(mlx_ptr);
	free(addr);
	return (0);
}
