/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gateixei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:35:14 by gateixei          #+#    #+#             */
/*   Updated: 2023/03/26 02:46:15 by gateixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TRUE 1
# define FALSE 0

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strcat(char *s1, char *temp);
void	ft_strcpy(char *str);
char	*add_char_to_str(char *line, char *buf);

#endif