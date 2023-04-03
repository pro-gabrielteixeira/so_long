/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:04:46 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/03 19:46:46 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		check_col(char **map)
{
    int i;
    int j;

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

int    move_right(char **map, int i, int j, t_vars *vars)
{
    if (map[i][j + 1] && (map[i][j + 1] == 'C' || map[i][j + 1] == '0'))
    {
        map[i][j] = '0';
        map[i][j + 1] = 'P';
        return (1);
    }
    else if (map[i][j + 1] && map[i][j + 1] == 'E' && check_col(map))
        destroy_all(vars);
    return (0);
}

int    move_left(char **map, int i, int j, t_vars *vars)
{
    if (map[i][j - 1] && (map[i][j - 1] == 'C' || map[i][j - 1] == '0'))
    {
        map[i][j] = '0';
        map[i][j - 1] = 'P';
        return (1);
    }
    else if (map[i][j - 1] && map[i][j - 1] == 'E' && check_col(map))
        destroy_all(vars);
    return (0);
}

int    move_down(char **map, int i, int j, t_vars *vars)
{
    if (map[i + 1] && (map[i + 1][j] == 'C' || map[i + 1][j] == '0'))
    {
        map[i][j] = '0';
        map[i + 1][j] = 'P';
        return (1);
    }
    else if (map[i + 1] && map[i + 1][j] == 'E' && check_col(map))
        destroy_all(vars);
    return (0);
}

int    move_up(char **map, int i, int j, t_vars *vars)
{
    if (map[i - 1] && (map[i - 1][j] == 'C' || map[i - 1][j] == '0'))
    {
        map[i][j] = '0';
        map[i - 1][j] = 'P';
        return (1);
    }
    else if (map[i - 1] && map[i - 1][j] == 'E' && check_col(map))
        destroy_all(vars);
    return (0);
}

int    move_action(t_vars *vars, int keycode)
{
    int i;
    int j;

    i = 0;
    while (vars->map[i] != NULL)
    {
        j = 0;
        while (vars->map[i][j] != '\0')
        {
            if (vars->map[i][j] == 'P')
                break;
            j++;
        }
        if (vars->map[i][j] == 'P')
            break;
        i++;
    }
    if (keycode == 97)
        return (move_left(vars->map, i, j, vars));
    else if (keycode == 119)
        return (move_up(vars->map, i, j, vars));
    else if (keycode == 115)
        return (move_down(vars->map, i, j, vars));
    else if (keycode == 100)
        return (move_right(vars->map, i, j, vars));
    return (0);
}