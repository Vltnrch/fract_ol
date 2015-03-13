/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:44:35 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 14:48:14 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH 500
# define HEIGHT 500
# define SQUARE(x) (x * x)

typedef struct		s_mdb
{
	double			pr;
	double			pi;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
	int				maxiter;
	int				x;
	int				y;
	int				i;
	int				info;
	int				mouse;
	int				coloroff;
}					t_mdb;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img2;
	int				bpp;
	int				bpp2;
	int				sizeline;
	int				sizeline2;
	int				endian;
	int				endian2;
	char			*data;
	char			*data2;
	struct s_mdb	*mdb;
}					t_env;

void				ft_init_bnsstruct(t_mdb *mdb);
int					ft_expose_bns(t_env *env);
void				ft_burningship(t_env *env, t_mdb *mdb);

int					ft_hsvtorgb(int h, int s, int v);

void				ft_init_jlastruct(t_mdb *mdb);
int					ft_expose_jla(t_env *env);
void				ft_julia(t_env *env, t_mdb *mdb);

void				ft_put_pixel_to_image(unsigned long img_color, \
											t_env *env, int x, int y);
void				init_conf(t_env *env, t_mdb *mdb);
void				ft_fract_usage(char *str);
int					key_hook(int keycode, t_mdb *mdb);
void				ft_printkey_color(void);

int					key_hook_bns(int keycode, t_env *env);
int					mouse_hook_bns(int mouse, int x, int y, t_env *env);

int					key_hook_jla(int keycode, t_env *env);
int					mouse_hook_jla(int mouse, int x, int y, t_env *env);
int					mouse_motion_jla(int x, int y, t_env *env);

int					key_hook_mdb(int keycode, t_env *env);
int					mouse_hook_mdb(int mouse, int x, int y, t_env *env);

void				ft_init_mdbstruct(t_mdb *mdb);
int					ft_expose_mdb(t_env *env);
void				ft_mandelbrot(t_env *env, t_mdb *mdb);

#endif
