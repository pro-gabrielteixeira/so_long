/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:33:22 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/08 13:47:28 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*def_img(char c, t_data_img *data_img)
{
	if (c == '0')
		return (data_img->floor.img);
	else if (c == '1')
		return (data_img->wall.img);
	else if (c == 'C')
		return (data_img->collectibles.img);
	else if (c == 'E')
		return (data_img->exit.img);
	else if (c == 'P')
		return (data_img->player.img);
	return (0);
}

void	generate_map_on_window(t_vars *vars)
{
	int	i;
	int	s;

	s = 0;
	while (vars->map && vars->map[s] != NULL)
	{
		i = 0;
		while (vars->map && vars->map[s][i] != '\0' && vars->map[s][i] != '\n')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, \
			def_img(vars->map[s][i], &vars->texture), (i * 64), (s * 64));
			i++;
		}
		s++;
	}
}

void	*create_window_size(void *mlx, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i] != NULL)
	{
		i++;
	}
	while (str && str[0][j] != '\0' && str[0][j] != '\n')
	{
		j++;
	}
	i = i * 64;
	j = j * 64;
	return (mlx_new_window(mlx, j, i, "So_long"));
}

void	build_data_img(void *mlx, t_data_img *data_img)
{
	data_img->collectibles.relative_path = "img/collectibles.xpm";
	data_img->exit.relative_path = "img/exit.xpm";
	data_img->floor.relative_path = "img/floor.xpm";
	data_img->player.relative_path = "img/player.xpm";
	data_img->wall.relative_path = "img/wall.xpm";
	data_img->img_height = 64;
	data_img->img_width = 64;
	data_img->collectibles.img = mlx_xpm_file_to_image(mlx, \
	data_img->collectibles.relative_path, &data_img->img_height, \
	&data_img->img_width);
	data_img->exit.img = mlx_xpm_file_to_image(mlx, \
	data_img->exit.relative_path, &data_img->img_height, &data_img->img_width);
	data_img->floor.img = mlx_xpm_file_to_image(mlx, \
	data_img->floor.relative_path, &data_img->img_height, &data_img->img_width);
	data_img->player.img = mlx_xpm_file_to_image(mlx, \
	data_img->player.relative_path, &data_img->img_height, \
	&data_img->img_width);
	data_img->wall.img = mlx_xpm_file_to_image(mlx, \
	data_img->wall.relative_path, &data_img->img_height, &data_img->img_width);
}

void	map_build(t_vars *vars)
{
	build_data_img(vars->mlx, &vars->texture);
	vars->win = create_window_size(vars->mlx, vars->map);
	generate_map_on_window(vars);
}
