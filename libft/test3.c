/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yplag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 19:17:50 by yplag             #+#    #+#             */
/*   Updated: 2014/12/11 13:44:07 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET	"\e[0m"
#define BOLD	"\e[1m"
#define	UNBOLD	"\e[21m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define MAGENTA	"\e[35m"
#define UNCOLOR	"\e[39m"

static void	set(char *color_code)
{
	printf(color_code);
}

static void init(int tab[], int n, int c)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tab[i] = c;
		++i;
	}
}
static void print_test_name(char *str)
{
	set(BLUE);
	set(BOLD);
	printf(str);
	set(RESET);
	if (strlen(str) > 6)
		printf(":\t");
	else
		printf(":\t\t");
}

static void	print_test_results(int	return_value[], int control_value[], int n)
{
	int		i;

	if (n)
	{
		i = 0;
		while (i < n)
		{
			printf("test %d", i);
			if (return_value[i] == control_value[i])
			{
				set(GREEN);
				printf(" OK");
				set(UNCOLOR);
				if (i != n - 1)
					printf(", ");
			}
			else
			{
				set(RED);
				printf(" failed");
				set(UNCOLOR);
				printf(" [ctrl=%d, test=%d]", control_value[i], return_value[i]);
				if (i != n - 1)
					printf(", ");
			}
			++i;
		}
		printf("\n");
	}
	else
	{
		set(YELLOW);
		printf("no test was performed\n");
		set(UNCOLOR);
	}
}

static void	print_test_results_summary(int	return_value[], int control_value[], int n)
{
	int		i;

	if (n)
	{
		if (n == 1)
			printf("1 test ");
		else
			printf("%d tests ", n);
		i = 0;
		while (i < n && return_value[i] == control_value[i])
			++i;
		if (i == n && return_value[i - 1] == control_value[i - 1])
		{
			set(GREEN);
			printf("OK");
			set(UNCOLOR);
		}
		else
		{
			if (i == n)
				--i;
			set(RED);
			printf("failed");
			set(UNCOLOR);
			printf(" @ [i=%d, ctrl=%d, test=%d]", i, control_value[i], return_value[i]);
		}
		printf("\n");
	}
	else
	{
		set(YELLOW);
		printf("no test was performed\n");
		set(UNCOLOR);
	}
}

static void	test_sign(int test[], int ctrl[], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (test[i] * ctrl[i] > 0)
			test[i] = ctrl[i];
		++i;
	}
}

static void	test_atoi(void)
{
	int		test[32], ctrl[32];

	ctrl[0] = atoi("1230978");
	ctrl[1] = atoi("test");
	ctrl[2] = atoi("1230978");
	ctrl[3] = atoi("a1230978");
	ctrl[4] = atoi("1230978ébpo");
	ctrl[5] = atoi("1230978bépo");
	ctrl[6] = atoi("    + 001230978");
	ctrl[7] = atoi("    - 001230978");
	ctrl[8] = atoi("    -+0001230978");
	ctrl[9] = atoi("    +-0001230978");
	ctrl[10] = atoi("    --0001230978");
	ctrl[11] = atoi("    ++0001230978");
	ctrl[12] = atoi("    -1230978");
	ctrl[13] = atoi("    +1230978");
	ctrl[14] = atoi("0009990");
	ctrl[15] = atoi("00000");
	ctrl[16] = atoi("00001");
	ctrl[17] = atoi("00100");
	ctrl[18] = atoi("\t123");
	ctrl[19] = atoi("\n123");
	ctrl[20] = atoi("\e123");
	ctrl[21] = atoi("");
	ctrl[22] = atoi(" 01+1");
	ctrl[23] = atoi(" 01-1");
	ctrl[24] = atoi("3.14");
	ctrl[25] = atoi("3,14");
	ctrl[26] = atoi("9999999999");
	ctrl[27] = atoi("2147483647");
	ctrl[28] = atoi("-2147483648");
	ctrl[29] = atoi("\v123");
	ctrl[30] = atoi("\f123");
	ctrl[31] = atoi("\r123");
	test[0] = ft_atoi("1230978");
	test[1] = ft_atoi("test");
	test[2] = ft_atoi("1230978");
	test[3] = ft_atoi("a1230978");
	test[4] = ft_atoi("1230978ébpo");
	test[5] = ft_atoi("1230978bépo");
	test[6] = ft_atoi("    + 001230978");
	test[7] = ft_atoi("    - 001230978");
	test[8] = ft_atoi("    -+0001230978");
	test[9] = ft_atoi("    +-0001230978");
	test[10] = ft_atoi("    --0001230978");
	test[11] = ft_atoi("    ++0001230978");
	test[12] = ft_atoi("    -1230978");
	test[13] = ft_atoi("    +1230978");
	test[14] = ft_atoi("0009990");
	test[15] = ft_atoi("00000");
	test[16] = ft_atoi("00001");
	test[17] = ft_atoi("00100");
	test[18] = ft_atoi("\n123");
	test[19] = ft_atoi("\t123");
	test[20] = ft_atoi("\e123");
	test[21] = ft_atoi("");
	test[22] = ft_atoi(" 01+1");
	test[23] = ft_atoi(" 01-1");
	test[24] = ft_atoi("3.14");
	test[25] = ft_atoi("3,14");
	test[26] = ft_atoi("9999999999");
	test[27] = ft_atoi("2147483647");
	test[28] = ft_atoi("-2147483648");
	test[29] = ft_atoi("\v123");
	test[30] = ft_atoi("\f123");
	test[31] = ft_atoi("\r123");
	print_test_name("atoi");
	print_test_results_summary(test, ctrl, 32);
}

static void	test_bzero(void)
{
	int		test[2], ctrl[2];
	char	str1[]="test string",
			str2[]="test string",
			str3[]="one test string",
			str4[]="two test string";

	init(ctrl, 2, 0);
	init(test, 2, 0);
	bzero(str1, 0);
	ft_bzero(str2, 0);
	test[0] = strcmp(str1, str2);
	bzero(str3, 10);
	ft_bzero(str4, 10);
	while (!(str3[ctrl[1]]))
		++(ctrl[1]);
	while (!(str4[test[1]]))
		++(test[1]);
	print_test_name("bzero");
	print_test_results(test, ctrl, 2);
}

static void	test_isalnum(void)
{
	int		i, test[1024], ctrl[1024];

	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isalnum(i);
		test[i] = ft_isalnum(i);
		++i;
	}
	print_test_name("isalnum");
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isalpha(void)
{
	int		i, test[1024], ctrl[1024];

	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isalpha(i);
		test[i] = ft_isalpha(i);
		++i;
	}
	print_test_name("isalpha");
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isascii(void)
{
	int		i, test[1024], ctrl[1024];

	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isascii(i);
		test[i] = ft_isascii(i);
		++i;
	}
	print_test_name("isascii");
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isdigit(void)
{
	int		i, test[1024], ctrl[1024];

	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isdigit(i);
		test[i] = ft_isdigit(i);
		++i;
	}
	print_test_name("isdigit");
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isprint(void)
{
	int		i, test[1024], ctrl[1024];

	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isprint(i);
		test[i] = ft_isprint(i);
		++i;
	}
	print_test_name("isprint");
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_memalloc(void)
{
	int		test[2], ctrl[2];
	void	*ptr;

	ctrl[0] = 512;
	if (!(ptr = ft_memalloc(ctrl[0])))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	test[0] = 0;
	while (test[0] < ctrl[0] && !(*((unsigned char*)ptr)))
		++(test[0]);
	free(ptr);
	ctrl[1] = 0;
	test[1] = 1;
	if (!(ptr = ft_memalloc(SIZE_MAX)))
		test[1] = 0;
	free(ptr);
	print_test_name("memalloc");
	print_test_results(test, ctrl, 2);
}

static void	test_memccpy(void)
{
	int		test[6], ctrl[6];
	char	dst1[]="abcdefghijklmnopqrstuvwxyz", src1[]="test",
			dst2[]="abcdefghijklmnopqrstuvwxyz", src2[]="test",
			dst3[]="abcdefghijklmnopqrstuvwxyz", src3[]="test\200string",
			dst4[]="abcdefghijklmnopqrstuvwxyz", src4[]="test\200string";
	void	*ptr1, *ptr2;

	init(ctrl, 6, 0);
	ptr1 = memccpy(dst1, src1, '0', 4);
	ptr2 = ft_memccpy(dst2, src2, '0', 4);
	test[0] = strcmp(dst1, dst2);
	if (ptr1 == ptr2)
		test[1] = 0;
	else
		test[1] = 1;
	memccpy(dst1, src1, '0', 5);
	ft_memccpy(dst2, src2, '0', 5);
	test[2] = strcmp(dst1, dst2);
	memccpy(dst3, src3, '\200', 12);
	ft_memccpy(dst4, src4, '\200', 12);
	test[3] = strcmp(dst3, dst4);
	memccpy(dst3, src3, 'r', 12);
	ft_memccpy(dst4, src4, 'r', 12);
	test[4] = strcmp(dst3, dst4);
	ptr1 = memccpy(dst3, src3, 'g', 12);
	ptr2 = ft_memccpy(dst3, src3, 'g', 12);
	if (ptr1 == ptr2)
		test[5] = 0;
	else
		test[5] = 1;
	print_test_name("memccpy");
	print_test_results(test, ctrl, 6);
}

static void	test_memchr(void)
{
	int				test[4], ctrl[4];
	unsigned char	str1[]="test\200string";

	init(ctrl, 4, 0);
	init(test, 4, 1);
	if (memchr(str1, 'a', 12) == ft_memchr(str1, 'a', 12))
		test[0] = 0;
	if (memchr(str1, '\200', 12) == ft_memchr(str1, '\200', 12))
		test[1] = 0;
	if (memchr(str1, 'g', 10) == ft_memchr(str1, 'g', 10))
		test[2] = 0;
	if (memchr(str1, 'g', 11) == ft_memchr(str1, 'g', 11))
		test[3] = 0;
	print_test_name("memchr");
	print_test_results(test, ctrl, 4);
}

static void	test_memcmp(void)
{
	int		test[3], ctrl[3];
	char	str1[]="test string", str2[]="test spring";

	test[0] = memcmp(str1, str2, 12);
	ctrl[0] = ft_memcmp(str1, str2, 12);
	test[1] = memcmp(str1, str2, 6);
	ctrl[1] = ft_memcmp(str1, str2, 6);
	test[2] = memcmp("a", "b", 0);
	ctrl[2] = ft_memcmp("a", "b", 0);
	print_test_name("memcmp");
	print_test_results(test, ctrl, 3);
}

static void	test_memcpy(void)
{
	int		test[1], ctrl[1];
	char	str1[]="test string", *str2, *str3;

	if (!(str2 = malloc(sizeof(*str2) * 20)) || !(str3 = malloc(sizeof(*str3) * 20)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	ctrl[0] = 0;
	test[0] = strcmp(memcpy(str2, str1, strlen(str1) + 1), ft_memcpy(str3, str1, strlen(str1) + 1));
	free(str2);
	free(str3);
	print_test_name("memcpy");
	print_test_results(test, ctrl, 1);
}

static void	test_memdel(void)
{
	int		test[1], ctrl[1];
	void	*ptr;

	if (!(ptr = malloc(1)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	ctrl[0] = 0;
	test[0] = 1;
	ft_memdel(&ptr);
	if (!ptr)
		test[0] = 0;
	free(ptr);
	print_test_name("memdel");
	print_test_results(test, ctrl, 1);
}

static void	test_memmove(void)
{
	int		test[3], ctrl[3], n=6;
	char	str1[]="abcdefghijklmnopqrstuvwxyz", str2[]="abcdefghijklmnopqrstuvwxyz",
			str3[]="abcdefghijklmnopqrstuvwxyz", str4[]="abcdefghijklmnopqrstuvwxyz";

	init(ctrl, 3, 0);
	str1[n - 1] = '\0';
	str2[n - 1] = '\0';
	str3[n - 1] = '\0';
	str4[n - 1] = '\0';
	test[0] = strcmp(memmove(str1 + 1, str1, n), ft_memmove(str2 + 1, str2, n));
	test[1] = strcmp(memmove(str3, str3 + 1, n), ft_memmove(str4, str4 + 1, n));
	test[2] = strcmp(memmove(str1, str1, n), ft_memmove(str2, str2, n));
	print_test_name("memmove");
	print_test_results(test, ctrl, 3);
}

static void	test_memset(void)
{
	int		test[4], ctrl[4];
	char	str1[]="don't kill me\n",
			str2[]="don't kill me\n";

	init(ctrl, 4, 0);
	test[0] = strcmp(memset(str1, '-', 0), ft_memset(str2, '-', 0));
	test[1] = strcmp(memset(str1, '-', 1), ft_memset(str2, '-', 1));
	test[2] = strcmp(memset(str1, '-', 5), ft_memset(str2, '-', 5));
	test[3] = strcmp(memset(str1, 0, 5), ft_memset(str2, 0, 5));
	print_test_name("memset");
	print_test_results(test, ctrl, 4);
}

static void	test_strcat(void)
{
	int		test[1], ctrl[1];
	char	*dst1, *dst2, src[]="test";

	if (!(dst1 = malloc(sizeof(*dst1) * (strlen(src) + 1) * 3)) || !(dst2 = malloc(sizeof(*dst2) * (strlen(src) + 1) * 3)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	ctrl[0] = 0;
	test[0] = strcmp(strcat(dst1, src), ft_strcat(dst2, src));
	free(dst1);
	free(dst2);
	print_test_name("strcat");
	print_test_results(test, ctrl, 1);
}

static void	test_strcmp(void)
{
	int		test[9], ctrl[9];

	ctrl[0] = strcmp("test string", "test string");
	ctrl[1] = strcmp("test string", "test spring");
	ctrl[2] = strcmp("test string", "test string ");
	ctrl[3] = strcmp("test string ", "test string");
	ctrl[4] = strcmp("", "test");
	ctrl[5] = strcmp("test", "");
	ctrl[6] = strcmp("", "");
	ctrl[7] = strcmp("\200\230\100\255", "\200\230\100\255");
	ctrl[8] = strcmp("\200\230\100\255", "\0\230\100\255");
	test[0] = ft_strcmp("test string", "test string");
	test[1] = ft_strcmp("test string", "test spring");
	test[2] = ft_strcmp("test string", "test string ");
	test[3] = ft_strcmp("test string ", "test string");
	test[4] = ft_strcmp("", "test");
	test[5] = ft_strcmp("test", "");
	test[6] = ft_strcmp("", "");
	test[7] = ft_strcmp("\200\230\100\255", "\200\230\100\255");
	test[8] = ft_strcmp("\200\230\100\255", "\0\230\100\255");
	test_sign(test, ctrl, 9);
	print_test_name("strcmp");
	print_test_results(test, ctrl, 9);
}

static void	test_strcpy(void)
{
	int		test[2], ctrl[2];
	char	*dst1, *dst2, src1[]="\001test string\200", src2[]="test";

	init(ctrl, 2, 0);
	if (!(dst1 = malloc(strlen(src1) + 1)) || !(dst2 = malloc(strlen(src1) + 1)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	test[0] = strcmp(strcpy(dst1, src1), ft_strcpy(dst2, src1));
	ft_strcpy(dst1, src2);
	if (dst1[strlen(src2)])
		test[1] = 1;
	else
		test[1] = 0;
	free(dst1);
	free(dst2);
	print_test_name("strcpy");
	print_test_results(test, ctrl, 2);
}

static void	test_strdup(void)
{
	int		test[2], ctrl[2];
	char	*dst, src[]="test string";

	init(ctrl, 2, 0);
	dst = ft_strdup(src);
	test[0] = strcmp(src, dst);
	if (dst[strlen(src)])
		test[1] = 1;
	else
		test[1] = 0;
	free(dst);
	print_test_name("strdup");
	print_test_results(test, ctrl, 2);
}

static void	test_strlcat(void)
{
	size_t	n;
	int		test[4], ctrl[4];
	char	*dst1, *dst2, src[]="test string";

	init(ctrl, 4, 0);
	n = (strlen(src) + 1);
	if (!(dst1 = malloc(sizeof(*dst1) * n)) || !(dst2 = malloc(sizeof(*dst2) * n)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	test[0] = strlcat(dst1, src, n / 2) - ft_strlcat(dst2, src, n / 2);
	strlcat(dst1, src, n);
	ft_strlcat(dst2, src, n);
	test[1] = strcmp(dst1, dst2);
	free(dst1);
	free(dst2);
	n = n * 2 + n / 2;
	if (!(dst1 = malloc(sizeof(*dst1) * n)) || !(dst2 = malloc(sizeof(*dst2) * n)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	strlcat(dst1, src, n);
	ft_strlcat(dst2, src, n);
	test[2] = strcmp(dst1, dst2);
	strlcat(dst1, src, n);
	ft_strlcat(dst2, src, n);
	test[3] = strcmp(dst1, dst2);
	free(dst1);
	free(dst2);
	print_test_name("strlcat");
	print_test_results(test, ctrl, 4);
}

static void	test_strchr(void)
{
	int		test[3], ctrl[3];
	char	str[]="test string test string test string";

	init(ctrl, 3, 0);
	init(test, 3, 1);
	if (strchr(str, ' ') == ft_strchr(str, ' '))
		test[0] = 0;
	if (strchr(str, '\0') == ft_strchr(str, '\0'))
		test[1] = 0;
	if (strchr(str, '@') == ft_strchr(str, '@'))
		test[2] = 0;
	print_test_name("strchr");
	print_test_results(test, ctrl, 3);
}

static void	test_strlen(void)
{
	int		test[2], ctrl[2];

	test[0] = strlen("");
	ctrl[0] = ft_strlen("");
	test[1] = strlen("\001\002\003\004\005\200");
	ctrl[1] = ft_strlen("\001\002\003\004\005\200");
	print_test_name("strlen");
	print_test_results(test, ctrl, 2);
}

static void	test_strncat(void)
{
	int		test[3], ctrl[3];
	char	*dst1, *dst2, src[]="test string";

	init(ctrl, 3, 0);
	if (!(dst1 = malloc(sizeof(*dst1) * 100)) || !(dst2 = malloc(sizeof(*dst2) * 100)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	test[0] = strcmp(strncat(dst1, src, 0), ft_strncat(dst2, src, 0));
	test[1] = strcmp(strncat(dst1, src, 6), ft_strncat(dst2, src, 6));
	test[2] = strcmp(strncat(dst1, src, 50), ft_strncat(dst2, src, 50));
	free(dst1);
	free(dst2);
	print_test_name("strncat");
	print_test_results(test, ctrl, 3);
}

static void	test_strncmp(void)
{
	int		test[13], ctrl[13];

	ctrl[0] = strncmp("test string", "test string", 0);
	ctrl[1] = strncmp("test string", "test string", 30);
	ctrl[2] = strncmp("test string", "test spring", 6);
	ctrl[3] = strncmp("test string", "test spring", 7);
	ctrl[4] = strncmp("test string", "test spring", 8);
	ctrl[5] = strncmp("test string", "test string    ", 12);
	ctrl[6] = strncmp("test string", "test string    ", 30);
	ctrl[7] = strncmp("", "test", 0);
	ctrl[8] = strncmp("", "", 0);
	ctrl[9] = strncmp("", "", 1);
	ctrl[10] = strncmp("", "", 2);
	ctrl[11] = strncmp("\200\230\100\255", "\200\230\100\255", 5);
	ctrl[12] = strncmp("\200\230\100\255", "\200\0\100\255", 5);
	test[0] = ft_strncmp("test string", "test string", 0);
	test[1] = ft_strncmp("test string", "test string", 30);
	test[2] = ft_strncmp("test string", "test spring", 6);
	test[3] = ft_strncmp("test string", "test spring", 7);
	test[4] = ft_strncmp("test string", "test spring", 8);
	test[5] = ft_strncmp("test string", "test string    ", 12);
	test[6] = ft_strncmp("test string", "test string    ", 30);
	test[7] = ft_strncmp("", "test", 0);
	test[8] = ft_strncmp("", "", 0);
	test[9] = ft_strncmp("", "", 1);
	test[10] = ft_strncmp("", "", 2);
	test[11] = ft_strncmp("\200\230\100\255", "\200\230\100\255", 5);
	test[12] = ft_strncmp("\200\230\100\255", "\200\0\100\255", 5);
	test_sign(test, ctrl, 13);
	print_test_name("strncmp");
	print_test_results(test, ctrl, 13);
}

static void	test_strncpy(void)
{
	int		test[1], ctrl[1];
	size_t	n;
	char	*dst1, *dst2, src[]="test string";

	n = strlen(src) + 4;
	if (!(dst1 = malloc(sizeof(*dst1) * n)) || !(dst2 = malloc(sizeof(*dst2) * n)))
	{
		perror("malloc() failed: ");
		exit(EXIT_FAILURE);
	}
	memset(dst1, 'a', sizeof(*dst1) * n);
	memset(dst2, 'a', sizeof(*dst2) * n);
	ctrl[0] = 0;
	test[0] = memcmp(strncpy(dst1, src, n), ft_strncpy(dst2, src, n), sizeof(*dst1) * n);
	print_test_name("strncpy");
	print_test_results(test, ctrl, 1);
}

static void	test_strnstr(void)
{
	int		test[14], ctrl[14];
	char	str[]="test\200string test\200string";

	init(ctrl, 14, 0);
	init(test, 14, 1);
	if (strnstr(str, "test", 6) == ft_strnstr(str, "test", 6))
		test[0] = 0;
	if (strnstr(str, "test", 5) == ft_strnstr(str, "test", 5))
		test[1] = 0;
	if (strnstr(str, "test", 4) == ft_strnstr(str, "test", 4))
		test[2] = 0;
	if (strnstr(str, "test", 3) == ft_strnstr(str, "test", 3))
		test[3] = 0;
	if (strnstr(str, "string", 10) == ft_strnstr(str, "string", 10))
		test[4] = 0;
	if (strnstr(str, "string", 11) == ft_strnstr(str, "string", 11))
		test[5] = 0;
	if (strnstr(str, "string", 12) == ft_strnstr(str, "string", 12))
		test[6] = 0;
	if (strnstr(str, "string", 30) == ft_strnstr(str, "string", 30))
		test[7] = 0;
	if (strnstr(str, "\200", 15) == ft_strnstr(str, "\200", 15))
		test[8] = 0;
	if (strnstr(str, "@", 30) == ft_strnstr(str, "@", 30))
		test[9] = 0;
	if (strnstr(str, str, strlen(str)) == ft_strnstr(str, str, strlen(str)))
		test[10] = 0;
	if (strnstr(str, str, strlen(str) + 1) == ft_strnstr(str, str, strlen(str) + 1))
		test[11] = 0;
	if (strnstr(str, str, strlen(str) - 1) == ft_strnstr(str, str, strlen(str) - 1))
		test[12] = 0;
	if (strnstr(str, "ingr", strlen(str)) == ft_strnstr(str, "ingr", strlen(str)))
		test[13] = 0;
	print_test_name("strnstr");
	print_test_results_summary(test, ctrl, 14);
}

static void	test_strrchr(void)
{
	int		test[3], ctrl[3];
	char	str[]="test string test string test string";

	init(ctrl, 3, 0);
	init(test, 3, 1);
	if (strrchr(str, ' ') == ft_strrchr(str, ' '))
		test[0] = 0;
	if (strrchr(str, '\0') == ft_strrchr(str, '\0'))
		test[1] = 0;
	if (strrchr(str, '@') == ft_strrchr(str, '@'))
		test[2] = 0;
	print_test_name("strrchr");
	print_test_results(test, ctrl, 3);
}

static void	test_strstr(void)
{
	int		test[6], ctrl[6];
	char	str[]="test\200string test\200string";

	init(ctrl, 6, 0);
	init(test, 6, 1);
	if (strstr(str, "test") == ft_strstr(str, "test"))
		test[0] = 0;
	if (strstr(str, "string") == ft_strstr(str, "string"))
		test[1] = 0;
	if (strstr(str, "\200") == ft_strstr(str, "\200"))
		test[2] = 0;
	if (strstr(str, "@") == ft_strstr(str, "@"))
		test[3] = 0;
	if (strstr(str, str) == ft_strstr(str, str))
		test[4] = 0;
	if (strstr(str, "ingr") == ft_strstr(str, "ingr"))
		test[5] = 0;
	print_test_name("strstr");
	print_test_results(test, ctrl, 6);
}

static void	test_tolower(void)
{
	int		i, test[1024], ctrl[1024];

	i = 0;
	while (i < 1024)
	{
		ctrl[i] = tolower(i);
		test[i] = ft_tolower(i);
		++i;
	}
	print_test_name("tolower");
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_toupper(void)
{
	int		i, test[1024], ctrl[1024];

	i = 0;
	while (i < 1024)
	{
		ctrl[i] = toupper(i);
		test[i] = ft_toupper(i);
		++i;
	}
	print_test_name("toupper");
	print_test_results_summary(test, ctrl, 1024);
}

int			main(void)
{
	test_atoi();
	test_bzero();
	test_isalnum();
	test_isalpha();
	test_isascii();
	test_isdigit();
	test_isprint();
	test_memalloc();
	test_memccpy();
	test_memchr();
	test_memcmp();
	test_memcpy();
	test_memdel();
	test_memmove();
	test_memset();
	test_strcat();
	test_strchr();
	test_strcmp();
	test_strcpy();
	test_strdup();
	test_strlcat();
	test_strlen();
	test_strncat();
	test_strncmp();
	test_strncpy();
	test_strnstr();
	test_strrchr();
	test_strstr();
	test_tolower();
	test_toupper();
	printf("If all you see is green, bear in mind this doesn't mean your functions are correct.\nIt means I was not able to figure out what was wrong.\n");
	set(MAGENTA);
	printf("Love and kisses, Zaphod.\n");
	set(UNCOLOR);
	return (0);
}
