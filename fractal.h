/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:51:52 by dmendonc          #+#    #+#             */
/*   Updated: 2022/05/16 15:42:45 by dmendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "math.h"
# include "pthread.h"

//%%%%%%%%%%%%%%%%%%%%%		STRUCTURES	%%%%%%%%%%%%%%%%%%%%%%%
//----- COMPLEX SYSTEM -----

typedef struct s_vars
{
	int		x;
	int		y;
	double	real;
	double	imag;
	double	offset_x;
	double	offset_y;
	double	c_x;
	double	c_y;
	double	j_c_x;
	double	j_c_y;
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

typedef struct z_data{
	double	v_zoom;
	double	h_zoom;
	double	v_unzoom;
	double	h_unzoom;
}				t_zoom;

// ------ KEY INFO --------

typedef struct s_key
{
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_scr_u;
	int		key_scr_d;
	int		key_esc;
	int		click;
	int		lol_key;
	int		np_plus;
	int		np_minus;
}			t_keys;

//-------- MOTHER STRUCT-------

typedef struct s_move
{
	t_mlx_data	img;
	t_w_data	win;
	t_keys		keys;
	t_complex	nbr;
	t_complex	initial;
	t_zoom		zoom;
	int			wich_fractal;
	int			times_zoomed;
	int			max_it;
	int			it;
}			t_hooks;

//%%%%%%%%%%%%%%%%%%%%%		FUNCTIONS	%%%%%%%%%%%%%%%%%%%%%%%
//------------- INITIALIZING FUNCTIONS ---------------
t_keys		starting_keys(void);
t_zoom		starting_zoom(void);
t_complex	starting_numbers(void);
t_w_data	starting_window(int lenght, int height);
t_mlx_data	starting_image(t_w_data win);
t_complex	starting_point(void);
int			close(int keycode, t_mlx_data *img);
void		starting_class(t_hooks *class);
void		fill_image(t_hooks *class);
void		starting_new_class(t_hooks *class, t_hooks *new_class);
t_mlx_data	starting_image(t_w_data win);
void		fill_new_image(t_hooks *class, t_complex *point);
void		refreshing_image(t_hooks *class);

//------------- SAFETIES
void		safety_one(void);
void		safety_two(void);
void		manual(void);

//------------- AUX FUNCTIONS
int			compare(const char *s1, const char *s2);
double		char_to_double(const char *str);

//------------- TAKING CARE OF THE ARGUMENTS
void		choosing_fractal(char *str, t_hooks *class);
void		getting_c_for_julia(char *c_x, char *c_y, t_hooks *class);

//------------- FILLING AND COLOURING PIXELS
void		colour_pixel(double flag, t_hooks *class);
void		best_pallete(double flag, t_hooks *class);
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

//------ MOUSE
int			mouse_press(int key, int x, int y, t_hooks *class);
int			mouse_press_mandelbrot(int key, t_hooks *class);
int			mouse_press_julia(int key, t_hooks *class);
int			mouse_release(int key, t_hooks *class);

//----------- ZOOM FUNCTIONS
void		zoom_mandelbrot(t_hooks *class);
void		unzoom_mandelbrot(t_hooks *class);
void		zoom_julia(t_hooks *class);
void		unzoom_julia(t_hooks *class);
void		set_pixel(t_hooks *class);

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
void		sqrcomplex(t_complex *nbr);

void		draw_circle(t_hooks *class);

//----------- MANDELBROT
int			recursive_julia(double real, double imag, t_hooks *class);
void		fill_julia(t_hooks *class);
#endif

//a norminette atrofia com eu escolher as teclas
#define K_ESC 53
#define K_W 13
#define K_A 0
#define K_S 1
#define K_D 2
#define K_NP_MIN 78
#define K_NP_PLU 69
#define K_AR_L 123
#define K_AR_R 124
#define K_AR_U 126
#define K_AR_D 125

// MOUSE

#define M_SCR_U 4
#define M_SCR_D 5
