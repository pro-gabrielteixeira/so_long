/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:43:01 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/27 01:33:55 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(void)
{
    void    *mlx;
	char	**str;

	mlx = mlx_init();
	str = init_map();
    map_build(str, mlx);
    free_mem(str);
    return (0);
}
