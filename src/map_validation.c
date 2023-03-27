/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:35:45 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/26 21:57:32 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	is_well_constructed(char **str)
{
    int i;
    int j;
	int	n;
	int	s;

	j = 0;
	n = 0;
	s = 0;
	while (str && str[s] != NULL)
	{
		i = 0;
		while (str && str[s][i] != '\0' && str[s][i] != '\n')
		{
			if (str[s][i] != 'C' && str[s][i] != '0' && str[s][i] != '1')
			{
				if (str[s][i] == 'E' )
					j++;
				else if (str[s][i] == 'P')
					n++;
				else
					return (1);
			}
			i++;
		}
		s++;
	}
	if (j != 1 || n != 1)
		return (1);
	return (0);
}

int is_rectangle(char **str)
{
    int i;
    int j;
	int	s;

	i = 0;
	j = 0;
	s = 0;	
    while (str && str[i] != NULL)
        i++;
    while (str && str[0][j] != '\0' && str[0][j] != '\n')
        j++;
    if (i >= j)
        return (1);
	while (str && str[s] != NULL)
	{
		i = 0;
		while (str && str[s][i] != '\0' && str[s][i] != '\n')
			i++;
		if (i != j)
			return (1);
		s++;
	}
	return (0);
}

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

char	**init_map(void)
{
    int		fd;
	char	*tmp;
	char	**str;

	str = NULL;
	fd = open("maps/map_1.ber", O_RDONLY);
	if (fd < 0)
		exit(1);
	while (tmp = get_next_line(fd))
		str = join_str(str, tmp);
	if (is_rectangle(str) || is_well_constructed(str))
	{
		free_mem(str);
		exit(1);
	}
	return (str);
}