/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header_libasm.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 14:56:19 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/07/10 15:12:57 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_LIBASM_H
# define HEADER_LIBASM_H

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

#endif
