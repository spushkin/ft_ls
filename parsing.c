/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spushkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:47:21 by spushkin          #+#    #+#             */
/*   Updated: 2018/11/20 09:47:21 by spushkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** function to detect flag
*/

int			parsing(int ac, char **av, int *flags)
{
	int	i;

	*flags = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if (av[i][1] == '-' && av[i][2])
			return (i + 1);
		if (!parse_options(av[i], flags))
			return (-1);
	}
	return (i);
}

/*
** returns position of a character in a string
*/

static int	ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

/*
** here we light the nth bit according to the parsed flag
** e.g. if we have -Ra then we will have flags equal to 0b101
** the user decides which options he wants:
**
** l - for details
** R - to recursively display subfolders content
** a - for hidden files and folders
** r - to order by creation date
** t - to order by timestamp
**
** d - to display only current directory
** -1 \n to display only in 1 column, is is the default option
** -G for colors
**
** nb : *flags &= (*s == 'l') ? ~128 : ~2; is to set to 0 l if 1 was found
** and reversely .
** nb2 : *flags |= LS_ONE; is set by default with ls | cat -e
*/

int			parse_options(char *s, int *flags)
{
	int		n;

	while (*(++s))
	{
		if ((n = ft_strchr_index("alRrtdG1Ss", *s)) == -1)
			ls_error(s, USAGE);
		*flags |= (1 << n);
		if ((*s == 'l') || (*s == '1'))
			*flags &= (*s == 'l') ? ~LS_ONE : ~LS_L;
	}
	return (1);
}

/*
** function to handle errors
**
** 0 : display usage for invalid flag
** -1 : errno
** -2 : mall_err
**
** strerror() - system error messages, accepts an error number
** argument errnum and returns a pointer to the corresponding
** message string
*/

int			ls_error(char *s, int error)
{
	if (error == USAGE)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*s, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage: ft_ls [-alRrtdG1Ss] [file ...]", 2);
	}
	else if (error == ERRNO || error == MALL_ERR)
		ft_putstr_fd("ft_ls: ", 2);
	if (error == ERRNO)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else if (error == ERRNO)
		ft_putendl_fd(strerror(errno), 2);
	if (error == USAGE || error == MALL_ERR)
		exit(EXIT_FAILURE);
	return (0);
}
