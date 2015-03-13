/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:32:33 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 14:51:02 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Main file !
** Init every windows for all fractals
*/

#include "fract_ol.h"

static void	ft_jla(char *str, int *fract)
{
	t_env	env;
	t_mdb	mdb;
	int		i;

	*fract = 1;
	i = fork();
	if (i == 0)
	{
		init_conf(&env, &mdb);
		env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, str);
		env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
		env.data = mlx_get_data_addr(env.img, &(env.bpp), \
					&(env.sizeline), &(env.endian));
		env.img2 = mlx_new_image(env.mlx, 250, 85);
		env.data2 = mlx_get_data_addr(env.img2, &(env.bpp2), \
					&(env.sizeline2), &(env.endian2));
		ft_init_jlastruct(&mdb);
		ft_julia(&env, &mdb);
		mlx_key_hook(env.win, &key_hook_jla, &env);
		mlx_mouse_hook(env.win, &mouse_hook_jla, &env);
		mlx_hook(env.win, 6, 1L << 6, &mouse_motion_jla, &env);
		mlx_expose_hook(env.win, &ft_expose_jla, &env);
		mlx_loop(env.mlx);
	}
}

static void	ft_mdb(char *str, int *fract)
{
	t_env	env;
	t_mdb	mdb;
	int		i;

	*fract = 1;
	i = fork();
	if (i == 0)
	{
		init_conf(&env, &mdb);
		env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, str);
		env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
		env.data = mlx_get_data_addr(env.img, &(env.bpp), \
					&(env.sizeline), &(env.endian));
		env.img2 = mlx_new_image(env.mlx, 220, 40);
		env.data2 = mlx_get_data_addr(env.img2, &(env.bpp2), \
					&(env.sizeline2), &(env.endian2));
		ft_init_mdbstruct(&mdb);
		ft_mandelbrot(&env, &mdb);
		mlx_key_hook(env.win, &key_hook_mdb, &env);
		mlx_mouse_hook(env.win, &mouse_hook_mdb, &env);
		mlx_expose_hook(env.win, &ft_expose_mdb, &env);
		mlx_loop(env.mlx);
	}
}

static void	ft_bns(char *str, int *fract)
{
	t_env	env;
	t_mdb	mdb;
	int		i;

	*fract = 1;
	i = fork();
	if (i == 0)
	{
		init_conf(&env, &mdb);
		env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, str);
		env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
		env.data = mlx_get_data_addr(env.img, &(env.bpp), \
					&(env.sizeline), &(env.endian));
		env.img2 = mlx_new_image(env.mlx, 220, 40);
		env.data2 = mlx_get_data_addr(env.img2, &(env.bpp2), \
					&(env.sizeline2), &(env.endian2));
		ft_init_bnsstruct(&mdb);
		ft_burningship(&env, &mdb);
		mlx_key_hook(env.win, &key_hook_bns, &env);
		mlx_do_key_autorepeaton(env.mlx);
		mlx_mouse_hook(env.win, &mouse_hook_bns, &env);
		mlx_expose_hook(env.win, &ft_expose_bns, &env);
		mlx_loop(env.mlx);
	}
}

int			main(int ac, char **av)
{
	int		fract[3];
	int		i;

	fract[0] = 0;
	fract[1] = 0;
	fract[2] = 0;
	i = 1;
	if (ac == 1)
		ft_fract_usage(av[0]);
	while (i < ac)
	{
		if (ft_strcmp(av[i], "julia") == 0 && fract[0] == 0)
			ft_jla("Julia", &fract[0]);
		else if (ft_strcmp(av[i], "mandelbrot") == 0 && fract[1] == 0)
			ft_mdb("Mandelbrot", &fract[1]);
		else if (ft_strcmp(av[i], "burningship") == 0 && fract[2] == 0)
			ft_bns("Burningship", &fract[2]);
		i++;
	}
	if (fract[0] == 0 && fract[1] == 0 && fract[2] == 0)
		ft_fract_usage(av[0]);
	ft_printkey_color();
	return (0);
}
