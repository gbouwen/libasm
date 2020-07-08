/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 14:28:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/07/08 15:58:02 by gbouwen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "header_libasm.h"

int	main(void)
{
	int		len_strlen;
	int		len_ft_strlen;

	printf("--------------------------------------------------------------\n");
	len_strlen = strlen("dit is een string");
	len_ft_strlen = ft_strlen("dit is een string");
	printf("strlen: %d\n", len_strlen);
	printf("my_strlen: %d\n", len_ft_strlen);

	int		diff_strcmp;
	int		diff_ft_strcmp;
	printf("--------------------------------------------------------------\n");
	diff_strcmp = strcmp("\200", "\0");
	diff_ft_strcmp = ft_strcmp("\200", "\0");
	printf("strcmp: %d\n", diff_strcmp);
	printf("my_strcmp: %d\n", diff_ft_strcmp);

	char	*str_strcpy;
	char	*str_ft_strcpy;
	str_strcpy = malloc(50);
	str_ft_strcpy = malloc(50);
	printf("--------------------------------------------------------------\n");
	strcpy(str_strcpy, "hoi");
	ft_strcpy(str_ft_strcpy, "hoi");
	printf("strcpy: %s\n", str_strcpy);
	printf("ft_strcpy: %s\n", str_ft_strcpy);

	int		ret_write;
	int		ret_ft_write;
	int		error_write;
	printf("--------------------------------------------------------------\n");
	ret_write = write(1, NULL, 4);
	ret_ft_write = ft_write(1, NULL, 4);
	error_write = errno;
	printf("write: %d\n", ret_write);
	printf("ft_write: %d\n", ret_ft_write);
	printf("error: %d, error_message: %s\n", error_write, strerror(error_write));

	int		fd;
	int		ret_read;
	int		ret_ft_read;
	int		error_read;
	char	buf[6];

	fd = open("example.txt", O_RDONLY);
	printf("--------------------------------------------------------------\n");
	ret_read = read(fd, buf, 5);
	printf("read: '%s', ret_read: %d\n", buf, ret_read);
	ret_ft_read = ft_read(fd, buf, 5);
	printf("ft_read: '%s', ret_ft_read: %d\n", buf, ret_ft_read);
	error_read = errno;
//	printf("error: %d, error_message: %s\n", error_read, strerror(error_read));

	char	*str_strdup;
	char	*str_ft_strdup;
	int		error_strdup;

	printf("--------------------------------------------------------------\n");
	str_strdup = strdup("hoi");
	str_ft_strdup = ft_strdup("hoi");
	error_strdup = errno;
	printf("strdup: %s\n", str_strdup);
	printf("ft_strdup: %s\n", str_ft_strdup);
//	printf("error: %d, error_message: %s\n", error_strdup, strerror(error_strdup));
}
