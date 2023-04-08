/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:12:42 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/08 15:00:43 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_valid(char **str, t_vars *vars)
{
	if (is_rectangle(str) || is_well_constructed(str) || check_walls(str))
	{
		free_mem(str);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
		write(1, "Error\n", 6);
		perror("Are you kidding!? Ugly map, try to follow the rules!");
		exit(EXIT_FAILURE);
	}
}

void	free_mem(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	destroy_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->texture.collectibles.img);
	mlx_destroy_image(vars->mlx, vars->texture.exit.img);
	mlx_destroy_image(vars->mlx, vars->texture.floor.img);
	mlx_destroy_image(vars->mlx, vars->texture.player.img);
	mlx_destroy_image(vars->mlx, vars->texture.wall.img);
}

void	destroy_all(t_vars *vars)
{
	free_mem(vars->map);
	destroy_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = NULL;
	exit(EXIT_SUCCESS);
}

int	win_action(int keycode, t_vars *vars)
{
	static int	count = 0;

	if (keycode == 65307)
		destroy_all(vars);
	else if (keycode == 97 || keycode == 119 \
	|| keycode == 115 || keycode == 100)
	{
		if (move_action(vars, keycode))
		{
			count++;
			ft_putnbr_fd(count, 1);
			write(1, " moves\n", 7);
		}
	}
	return (0);
}
