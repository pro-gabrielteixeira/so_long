/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:55:15 by gateixei          #+#    #+#             */
/*   Updated: 2022/07/28 01:55:15 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strcat(char *s1, char *temp)
{
	char	*cat;
	int		c;

	c = 0;
	cat = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!cat)
		return (0);
	while (s1 && s1[c] != '\0')
	{
		cat[c] = s1[c];
		c++;
	}
	cat[c++] = temp[0];
	cat[c] = '\0';
	free(s1);
	return (cat);
}

void	ft_strcpy(char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = &str[1];
	while (str[i] != '\0' && ptr[i] != '\0' && str)
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	else
	{
		while (str[len] != '\0')
			len++;
	}
	return (len);
}

char	*add_char_to_str(char *line, char *buf)
{
	line = ft_strcat(line, buf);
	ft_strcpy(buf);
	return (line);
}
