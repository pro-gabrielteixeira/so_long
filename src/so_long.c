/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:43:01 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/03 19:45:53 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_field(char **str, t_vars *vars)
{
	int	i;
	int	j;
	
	i = 0;
	while (str[i] != NULL)
	{
	    j = 0;
	    while (str[i][j] != '\0')
	    {
	        if (str[i][j] == 'C' || str[i][j] == 'E')
			{
	    		free_mem(str);
				free_mem(vars->map);
	    		mlx_destroy_display(vars->mlx);
				free(vars->mlx);
	    		vars->mlx = NULL;
                write(1, "Error\n", 6);
	    		perror("There's no way to exit here! It's a game not jail!!");
				exit(EXIT_FAILURE);
			}
	        j++;
	    }
	    i++;
	}
}

void	check_all_possibilities(char **str, int i, int j)
{
    str[i][j] = 'F';
    if (str[i][j + 1] && (str[i][j + 1] == 'C' || str[i][j + 1] == '0' || str[i][j + 1] == 'E'))
		check_all_possibilities(str, i, (j + 1));
    if (str[i][j - 1] && (str[i][j - 1] == 'C' || str[i][j - 1] == '0' || str[i][j - 1] == 'E'))
		check_all_possibilities(str, i, (j - 1));
    if (str[i + 1] && (str[i + 1][j] == 'C' || str[i + 1][j] == '0' || str[i + 1][j] == 'E'))
		check_all_possibilities(str, (i + 1), j);
    if (str[i - 1] && (str[i - 1][j] == 'C' || str[i - 1][j] == '0' || str[i - 1][j] == 'E'))
		check_all_possibilities(str, (i - 1), j);
}

void	check_win_path(t_vars *vars)
{
    int i;
    int j;
	char	**str;

	i = ft_strlen(vars->map[0]);
	str = (char**) malloc((i + 1) * sizeof(char *));
	i = 0;
	while (vars->map[i] != NULL)
	{
		str[i] = ft_strdup(vars->map[i]);
		i++;
	}
	str[i] = NULL;
    i = 0;
    while (str[i] != NULL)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            if (str[i][j] == 'P')
                break;
            j++;
        }
        if (str[i][j] == 'P')
            break;
        i++;
    }
	check_all_possibilities(str, i, j);
	check_field(str, vars);
	free_mem(str);
}

void	check_args(int argc, char *str)
{
	int		i;
	int		j;
	char	*str_checker;

	if (argc != 2)
	{
        write(1, "Error\n", 6);
		perror("Hmm... I want ONLY the path to maps, idiot!!");
		exit(EXIT_FAILURE);
	}	
	i = ft_strlen(str);
	if (i < 4)
	{
        write(1, "Error\n", 6);
		perror("I don't have a crystal ball...");
		exit(EXIT_FAILURE);
	}
	str_checker = ".ber";
	i = i - 4;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i++] != str_checker[j++])
		{
            write(1, "Error\n", 6);
			perror("Jeeeezz, I Want a .ber file!!! .ber!!!!");
			exit(EXIT_FAILURE);
		}
	}
}

int     main(int argc, char **argv)
{
    t_vars  vars;

	check_args(argc, argv[1]);
	vars.mlx = mlx_init();
	vars.map = init_map(argv[1], &vars);
	check_win_path(&vars);
    map_build(&vars);
    mlx_key_hook(vars.win, win_action, &vars);
    mlx_mouse_hook(vars.win, win_action, &vars);
    mlx_hook(vars.win, 17, 1L<<0, (void*) &destroy_all, &vars);
	mlx_loop_hook(vars.mlx, (void*) &generate_map_on_window, &vars);
	mlx_loop(vars.mlx);
    free_mem(vars.map);
    return (0);
}
