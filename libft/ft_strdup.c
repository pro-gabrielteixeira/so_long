/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:11:02 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/16 01:27:57 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*src;
	int		i;
	int		c;

	c = 0;
	i = ft_strlen((char *) s1);
	str = (char *) malloc(i + 1);
	if (!str)
		return (0);
	src = (char *) s1;
	while (src[c] != '\0')
	{
		str[c] = src[c];
		c++;
	}
	str[c] = '\0';
	return (str);
}
