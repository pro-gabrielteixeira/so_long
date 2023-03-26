/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:55:34 by gateixei          #+#    #+#             */
/*   Updated: 2022/07/28 17:58:00 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (TRUE)
	{
		if (buf[0] != '\0' && buf[0] != '\n')
			line = add_char_to_str(line, buf);
		else if (buf[0] == '\n')
			return (add_char_to_str(line, buf));
		else if (!read(fd, buf, BUFFER_SIZE))
			return (line);
	}
}
