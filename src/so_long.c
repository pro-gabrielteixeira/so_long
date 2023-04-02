/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:43:01 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/02 18:39:49 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    destroy_img(t_vars *vars)
{
    mlx_destroy_image(vars->mlx, vars->texture.collectibles.img);
    mlx_destroy_image(vars->mlx, vars->texture.exit.img);
    mlx_destroy_image(vars->mlx, vars->texture.floor.img);
    mlx_destroy_image(vars->mlx, vars->texture.player.img);
    mlx_destroy_image(vars->mlx, vars->texture.wall.img);
}

void    destroy_win(t_vars *vars)
{
    free_mem(vars->map);
    destroy_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
    vars->mlx = NULL;
    exit(EXIT_SUCCESS); 
}

int     win_action(int keycode, t_vars *vars)
{
    static int  count = 0;
    
    if (keycode == 65307)
    {
        free_mem(vars->map);
        destroy_img(vars);
	    mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
        exit(EXIT_SUCCESS);
    }
    else if (keycode == 97 || keycode == 119 || keycode == 115 || keycode == 100)
        count++;
    else
    {
        ft_putnbr_fd(keycode, 1);
        return (0);
    }
    ft_putnbr_fd(count, 1);
    write(1, " moves\n", 7);
	return (0);
}

int     main(int argc, char **argv)
{
    t_vars  vars;

    if (argc != 2)
    {
        return (1);
    }
	vars.mlx = mlx_init();
	vars.map = init_map(argv[1]);
    map_build(&vars);
    mlx_key_hook(vars.win, win_action, &vars);
    mlx_mouse_hook(vars.win, win_action, &vars);
    mlx_hook(vars.win, 17, 1L<<17, (void*) &destroy_win, &vars);
	mlx_loop(vars.mlx);
    free_mem(vars.map);
    return (0);
}
