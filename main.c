/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gbouwen <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 14:28:33 by gbouwen       #+#    #+#                 */
/*   Updated: 2020/08/05 14:54:17 by gbouwen       ########   odam.nl         */
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
	printf("--------------------------------------------------------------\n");
	printf("TESTING STRLEN\n");
	int		len_strlen;
	int		len_ft_strlen;

	printf("1:\n");
	len_strlen = strlen("dit is een string");
	len_ft_strlen = ft_strlen("dit is een string");
	printf("   strlen: %d\n", len_strlen);
	printf("ft_strlen: %d\n", len_ft_strlen);

	printf("2:\n");
	len_strlen = strlen("");
	len_ft_strlen = ft_strlen("");
	printf("   strlen: %d\n", len_strlen);
	printf("ft_strlen: %d\n", len_ft_strlen);

	printf("--------------------------------------------------------------\n");
	printf("TESTING STRCMP\n");
	int		diff_strcmp;
	int		diff_ft_strcmp;

	printf("1\n");
	diff_strcmp = strcmp("hoihoihoi", "hoihoihallo");
	diff_ft_strcmp = ft_strcmp("hoihoihoi", "hoihoihallo");
	printf("   strcmp: %d\n", diff_strcmp);
	printf("ft_strcmp: %d\n", diff_ft_strcmp);

	printf("2:\n");
	diff_strcmp = strcmp("\200", "\0");
	diff_ft_strcmp = ft_strcmp("\200", "\0");
	printf("   strcmp: %d\n", diff_strcmp);
	printf("ft_strcmp: %d\n", diff_ft_strcmp);

	printf("3\n");
	diff_strcmp = strcmp("h", "h");
	diff_ft_strcmp = ft_strcmp("h", "h");
	printf("   strcmp: %d\n", diff_strcmp);
	printf("ft_strcmp: %d\n", diff_ft_strcmp);

	printf("4\n");
	diff_strcmp = strcmp("hoa", "hoz");
	diff_ft_strcmp = ft_strcmp("hoa", "hoz");
	printf("   strcmp: %d\n", diff_strcmp);
	printf("ft_strcmp: %d\n", diff_ft_strcmp);

	printf("--------------------------------------------------------------\n");
	printf("TESTING STRCPY\n");
	char	*str_strcpy;
	char	*str_ft_strcpy;
	str_strcpy = malloc(30);
	str_ft_strcpy = malloc(30);

	printf("1:\n");
	strcpy(str_strcpy, "dit is de eerste test");
	ft_strcpy(str_ft_strcpy, "dit is de eerste test");
	printf("   strcpy: %s\n", str_strcpy);
	printf("ft_strcpy: %s\n", str_ft_strcpy);

	printf("2:\n");
	strcpy(str_strcpy, "");
	ft_strcpy(str_ft_strcpy, "");
	printf("   strcpy: %s\n", str_strcpy);
	printf("ft_strcpy: %s\n", str_ft_strcpy);

	printf("3:\n");
	strcpy(str_strcpy, "a");
	ft_strcpy(str_ft_strcpy, "a");
	printf("   strcpy: %s\n", str_strcpy);
	printf("ft_strcpy: %s\n", str_ft_strcpy);

	printf("--------------------------------------------------------------\n");
	printf("TESTING WRITE\n");
	int		fd_write_1;
	int		fd_write_2;
	int		fd_write_error;
	int		ret_write;
	int		ret_ft_write;
	int		error_write;

	printf("1:\n");
	ret_write = write(1, "hey\n", 5);
	ret_ft_write = ft_write(1, "hey\n", 5);
	error_write = errno;
	printf("   write: %d\n", ret_write);
	printf("ft_write: %d\n", ret_ft_write);
	printf("error: %d, error_message: %s\n", error_write, strerror(error_write));

	printf("2:\n");
//	ret_write = write(1, NULL, 5);
	ret_ft_write = ft_write(1, NULL, 5);
	error_write = errno;
//	printf("   write: %d\n", ret_write);
	printf("ft_write: %d\n", ret_ft_write);
	printf("error: %d, error_message: %s\n", error_write, strerror(error_write));

	printf("3:\n");
	fd_write_error = open("this_file_doesnt_exist.txt", O_RDONLY);
//	ret_write = write(fd_write_error, "test\n", 5);
	ret_ft_write = ft_write(fd_write_error, "test\n", 5);
	error_write = errno;
//	printf("   write: %d\n", ret_write);
	printf("ft_write: %d\n", ret_ft_write);
	printf("error: %d, error_message: %s\n", error_write, strerror(error_write));

	printf("4:\n");
	fd_write_1 = open("txt_files/example_1.txt", O_WRONLY);
	fd_write_2 = open("txt_files/example_2.txt", O_WRONLY);
	ret_write = write(fd_write_1, "test\n", 5);
	ret_ft_write = ft_write(fd_write_2, "test\n", 5);
	printf("   write: %d\n", ret_write);
	printf("ft_write: %d\n", ret_ft_write);

	printf("--------------------------------------------------------------\n");
	printf("TESTING READ\n");
	int		fd_read_1;
	int		fd_read_2;
	int		fd_read_error;
	int		fd_read_long;
	int		ret_read;
	int		ret_ft_read;
	int		error_read;
	char	*buf;

	buf = malloc(500);
	printf("1:\n");
	fd_read_1 = open("example_1.txt", O_RDONLY);
	fd_read_2 = open("example_2.txt", O_RDONLY);
	ret_read = read(fd_read_1, buf, 4);
	printf("   read: '%s',    ret_read: %d\n", buf, ret_read);
	ret_ft_read = ft_read(fd_read_2, buf, 4);
	printf("ft_read: '%s', ret_ft_read: %d\n", buf, ret_ft_read);

	printf("2:\n");
	fd_read_error = open("this_file_doesnt_exist.txt", O_RDONLY);
//	ret_read = read(fd_read_error, buf, 4);
//	printf("   read: '%s',    ret_read: %d\n", buf, ret_read);
	ret_ft_read = ft_read(fd_read_error, buf, 4);
	printf("ft_read: '%s', ret_ft_read: %d\n", buf, ret_ft_read);
	error_read = errno;
	printf("error: %d, error_message: %s\n", error_read, strerror(error_read));

	printf("3:\n");
	fd_read_long = open("txt_files/long_text.txt", O_RDONLY);
	ret_read = read(fd_read_long, buf, 500);
	printf("   read: \n%s,    ret_read: %d\n", buf, ret_read);
	ret_ft_read = ft_read(fd_read_long, buf, 500);
	printf("ft_read: \n%s, ret_ft_read: %d\n", buf, ret_ft_read);

	printf("--------------------------------------------------------------\n");
	printf("TESTING STRDUP\n");
	char	*str_strdup;
	char	*str_ft_strdup;
//	int		error_strdup;

	printf("1:\n");
	str_strdup = strdup("hoi");
	str_ft_strdup = ft_strdup("hoi");
	printf("   strdup: %s\n", str_strdup);
	printf("ft_strdup: %s\n", str_ft_strdup);

	printf("2:\n");
	str_strdup = strdup("");
	str_ft_strdup = ft_strdup("");
	printf("   strdup: %s\n", str_strdup);
	printf("ft_strdup: %s\n", str_ft_strdup);

	printf("3:\n");
	str_strdup = strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	str_ft_strdup = strdup("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	printf("   strdup: %s\n", str_strdup);
	printf("ft_strdup: %s\n", str_ft_strdup);
//	error_strdup = errno;
//	printf("error: %d, error_message: %s\n", error_strdup, strerror(error_strdup));
}
