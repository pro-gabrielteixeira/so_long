/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:04:46 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/08 15:19:37 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_col(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	write(1, "You Won!\n", 9);
	return (1);
}

int	move(t_vars *vars, int ns, int ew)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i] != NULL)
	{
		j = 0;
		while (vars->map[i][j] != '\0' && vars->map[i][j] != 'P')
			j++;
		if (vars->map[i][j] == 'P')
			break ;
		i++;
	}
	if (vars->map[i + ns] && (vars->map[i + ns][j + ew] == 'C'\
	|| vars->map[i + ns][j + ew] == '0'))
	{
		vars->map[i][j] = '0';
		vars->map[i + ns][j + ew] = 'P';
		return (1);
	}
	else if (vars->map[i + ns] && vars->map[i + ns][j + ew] == 'E'\
	&& check_col(vars->map))
		destroy_all(vars);
	return (0);
}

int	move_action(t_vars *vars, int keycode)
{
	if (keycode == 97)
		return (move(vars, 0, -1));
	else if (keycode == 119)
		return (move(vars, -1, 0));
	else if (keycode == 115)
		return (move(vars, 1, 0));
	else if (keycode == 100)
		return (move(vars, 0, 1));
	return (0);
}
