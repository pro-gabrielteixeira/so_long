/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:43:01 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/26 05:18:02 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**join_str(char **str, char *tmp)
{
	char	**new_str;
	int		i;

	i = 0;
	while (str && str[i] != NULL)
		i++;
	new_str = (char**) malloc((i + 2) * sizeof(char *));
	if (!new_str)
		exit(1);
	i = 0;
	while (str && str[i] != NULL)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = tmp;
	new_str[i] = '\0';
	free(str);
	str = NULL;
	return (new_str);
}

char	**init_map()
{
    int 	i;
    int 	j;
    int		fd;
	char	*tmp;
	char	**str;

    i = 1;
    j = 0;
	str = NULL;
	fd = open("maps/map_1.ber", O_RDONLY);
	if (fd < 0)
		exit(1);
	while (tmp = get_next_line(fd))
		str = join_str(str, tmp);
	while (str[j] != NULL)
	{
	    printf("Linha %i:%s\n", i, str[j]);
		i++;
		j++;
	}
	return (str);
}

int	main(void)
{
    // void    *mlx;
    // void    *mlx_win;
    // void    *img;
    // char    *relative_path;
	char	**str;
	int		i;
    // int     h;
    // int     w;

    // relative_path = "img/Idle1.xpm";
	// mlx = mlx_init();
	str = init_map();
	// i = 0;
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long");
	// img = mlx_xpm_file_to_image(mlx, relative_path, &w, &h);
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	// mlx_loop(mlx);
	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
    return (0);
}


/*
MAP
[
    111111111111111
    100000100000001
    100000000000001
    100000000000001
    1P0000000000001
    111111111111111
]

char **str;

str = gnl;
int teste;
int teste2;

fd = open("texto.txt", O_RDONLY);

while (str = get_next_line(fd))
    printf("Linha:%sFIM\n", str);
free(str);
return (0);

while(str[0][teste++] != '\0')
while(str[teste2++] != '\0')
if (teste <= teste2)
    nao é quadrado!!

while (str[i])
{
    while (str)
    {
        if (str[i][c] == 1)
            Parede
        else if (str[i] == 0)
            Livre
    }
}
*/