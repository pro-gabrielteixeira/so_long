/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:27:58 by gateixei          #+#    #+#             */
/*   Updated: 2023/04/02 17:14:38 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../libft/include/libft.h"

typedef struct	s_img {
    void    *img;
	char	*relative_path;
}	t_img;

typedef struct	s_data_img {
    t_img	collectibles;
    t_img	exit;
    t_img	floor;
    t_img	player;
    t_img	wall;
    int     img_height;
	int		img_width;
}	t_data_img;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_data_img	texture;
}	t_vars;

// map_validation.c
void	free_mem(char **str);
int		is_well_constructed(char **str);
int		is_rectangle(char **str);
char	**join_str(char **str, char *tmp);
char	**init_map(char *map);

// generate_img.c
void	*def_img(char c, t_data_img *data_img);
void	generate_map_on_window(void *mlx, void *mlx_win, char **str, t_data_img *data_img);
void	*create_window_size(void *mlx, char **str);
void    build_data_img(void *mlx, t_data_img *data_img);
void    map_build(t_vars *vars);

// so_long.c
void	destroy_win(t_vars *vars);
int		win_action(int keycode, t_vars *vars);
int		main(int argc, char **argv);

#endif