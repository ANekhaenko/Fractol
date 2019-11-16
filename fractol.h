/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 23:54:50 by anekhaen          #+#    #+#             */
/*   Updated: 2019/11/14 15:12:26 by anekhaen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <pthread.h>

# define ABS(X) (((X) < 0) ? (-(X)) : (X))

# define WIDTH		600
# define HEIGHT		600

# define THREADS    16

typedef	struct		s_fractol
{
	char			*addr;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	float			t;
	float			temp_dot_re;
	float			temp_dot_im;
	float			new_temp_dot_re;
	float			step;
	float			dot_re;
	float			dot_im;
	float			max_im;
	float			max_re;
	float			min_im;
	float			min_re;
	float			julia_re;
	float			julia_im;
	int				fr_set;
	int				bpp;
	int				max_iter;
	int				iter;
	int				sl;
	int				x;
	int				y;
	int				i;
	int				start;
	int				finish;
	int				end;
	int				fix_julia;
}					t_fractol;

void				set_default(t_fractol *fr);
void				make_window(t_fractol *fr);
void				get_black(t_fractol *fr);
void				get_color(t_fractol *fr);
void				arrows(int key, t_fractol *fr);
int					mouse(int button, int x, int y, t_fractol *fr);
int					keyboard(int key, t_fractol *fr);
float				scale(float start, float end, float zoom_scale);
void				make_threads(t_fractol *fr);
void				draw(t_fractol	*fr);
void				calculate_color(t_fractol *fr);
void				mandelbrot(t_fractol *fr);
void				burning_ship(t_fractol *fr);
void				julia(t_fractol *fr);
int					julia_iterate(int x, int y, t_fractol *fr);
void				celtic(t_fractol *fr);
void				buffalo(t_fractol *fr);
void				wtf(t_fractol *fr);

#endif
