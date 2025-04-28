/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:16:21 by ertrigna          #+#    #+#             */
/*   Updated: 2025/04/28 14:06:55 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

/*ascii to int or long int*/
long int	ft_atol(const char *str);
int			ft_atoi(const char *str);
/*split*/
char		**ft_split(char const *s, char c);
/*free_tab*/
void		ft_free_tab(char **tab);
/*str dup concat or copy*/
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t n);
char		*ft_strjoin(char *s1, const char *s2);
/*print c or str*/
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
/*sub*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
/*size function*/
size_t		ft_strlen(const char *s);
#endif