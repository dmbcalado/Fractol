/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:51:52 by dmendonc          #+#    #+#             */
/*   Updated: 2022/10/06 19:28:41 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "math.h"
# include "pthread.h"

//%%%%%%%%%%%%%%%%%%%%%		STRUCTURES	%%%%%%%%%%%%%%%%%%%%%%%
//----- COMPLEX SYSTEM -----

typedef struct s_vars
{
	int		x;
	int		y;
	double	c_x;
	double	c_y;
	double	j_c_x;
	double	j_c_y;
	double	real;
	double	imag;
	double	offset_x;
	double	offset_y;
	double	real_mouse;
	double	img_mouse;
}			t_complex;

//----- MLX INFO --------

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx_data;

//----- WINDOW INFO --------

typedef struct windowsxp
{
	int	lenght;
	int	height;
	int	center_x;
	int	center_y;
}				t_w_data;

typedef struct z_data
{
	double	v_zoom;
	double	h_zoom;
}				t_zoom;

// ------ KEY INFO --------

typedef struct s_key
{
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_n;
	int		key_scr_u;
	int		key_scr_d;
	int		key_esc;
	int		click;
	int		lol_key;
	int		np_plus;
	int		np_minus;
}			t_keys;

typedef struct s_kint
{
	int		k_w;
	int		k_a;
	int		k_s;
	int		k_d;
	int		k_esc;
	int		k_ar_l;
	int		k_ar_u;
	int		k_ar_r;
	int		k_ar_d;
	int		k_np_min;
	int		k_np_plu;
	int		m_scr_u;
	int		m_scr_d;
	int		m_click;
	int		k_n;
}			t_kint;

//-------- MOTHER STRUCT-------

typedef struct s_move
{
	t_mlx_data	img;
	t_w_data	win;
	t_keys		keys;
	t_complex	nbr;
	t_complex	initial;
	t_zoom		zoom;
	t_kint		kint;
	int			wich_fractal;
	int			times_zoomed;
	int			max_it;
	int			it;
}			t_hooks;

//%%%%%%%%%%%%%%%%%%%%%		FUNCTIONS	%%%%%%%%%%%%%%%%%%%%%%%
//------------- INITIALIZING FUNCTIONS ---------------
t_keys		starting_keys(void);
t_kint		starting_kint(void);
t_zoom		starting_zoom(void);
t_complex	starting_numbers(void);
t_w_data	starting_window(int lenght, int height);
t_mlx_data	starting_image(t_w_data win);
void		starting_class(t_hooks *class);
t_mlx_data	starting_image(t_w_data win);
void		refreshing_image(t_hooks *class);


//------------- AUX FUNCTIONS
int			compare(const char *s1, const char *s2);
double		char_to_double(const char *str);

//------------- TAKING CARE OF THE ARGUMENTS
void		choosing_fractal(char *str, t_hooks *class);
void		getting_c_for_julia(char *c_x, char *c_y, t_hooks *class);

//------------- FILLING AND COLOURING PIXELS
void		palletes(int flag, t_hooks *class);
void		colour_pixel(int flag, t_hooks *class);
void		day_pallete(int flag, t_hooks *class);
void		night_pallete(int flag, t_hooks *class);
void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);

//------------ HOOK FUNCTIONS
//------ KEYS
int			key_press(int keys, t_hooks *class);
int			key_release(int key, t_hooks *class);
int			key_move(t_hooks *class);
int			cross(t_hooks *class);
void		key_up(t_hooks *class);
void		key_down(t_hooks *class);
void		key_left(t_hooks *class);
void		key_right(t_hooks *class);
void		n_key_press(t_hooks *class);

//------ MOUSE
void		new_mouse_posit(t_hooks *class, int x, int y);
void		calc_mouse_posit(t_hooks *class, int x, int y);
int			mouse_press(int key, int x, int y, t_hooks *class);
int			mouse_press_mandelbrot(int key, t_hooks *class);
int			mouse_press_julia(int key, t_hooks *class);
int			mouse_release(int key, t_hooks *class);

//----------- ZOOM FUNCTIONS
void		zoom_mandelbrot(t_hooks *class);
void		unzoom_mandelbrot(t_hooks *class);
void		zoom_julia(t_hooks *class);
void		unzoom_julia(t_hooks *class);

//----------- RESOLUTION FUNCTIONS
void		increase_resolution(t_hooks *class);
void		decrease_resolution(t_hooks *class);

//----------- COORDINATES FUNCTIONS
void		set_coordinates_mandelbrot(int x, int y, t_hooks *class);
void		set_coordinates_julia(int x, int y, t_hooks *class);

//----------- MANDELBROT

void		fill_mandelbrot(t_hooks *class);
int			recursive_mandelbrot(double real, double imag, t_hooks *class);
double		calculate_radius(double x, double y);

//----------- MANDELBROT
int			recursive_julia(double real, double imag, t_hooks *class);
void		fill_julia(t_hooks *class);
#endif


//------------- SAFETIES & FREES
void		safety_one(void);
void		safety_two(void);
void		manual(void);
void		free_rest(t_hooks *class);