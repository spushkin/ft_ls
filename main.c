/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spushkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:47:21 by spushkin          #+#    #+#             */
/*   Updated: 2018/11/20 09:47:21 by spushkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*init_files_list(char **names_list, int ac, int first)
{
	t_file	*begin;
	int		i;

	begin = NULL;
	(!ac) ? add_new_file("", ".", &begin) :
		ft_sort_tab(names_list, ac, &ft_strcmp);
	i = -1;
	while (++i < ac)
		if (add_new_file("", names_list[i], &begin) == -1 && first)
			ls_error(names_list[i], ERRNO);
	return (begin);
}

/*
** main program http://man7.org/linux/man-pages/man1/ls.1.html
** check parsing.c for function parsing
**
** -l, List in long format.
** -R, Recursively list subdirectories encountered.
** -a, Include directory entries whose names begin with a dot (.).
** -r, Reverse the order of the sort to get reverse lexicographical
** order or the oldest entries first
** -t, Sort by time modified
*/

int		main(int ac, char **av)
{
	int			i;
	int			flags;
	t_file		*file_lst;
	int			no_files;

	if ((i = parsing(ac, av, &flags)) == -1)
		return (1);
	av += i;
	ac -= i;
	file_lst = init_files_list(av, ac, 1);
	no_files = (!file_lst ? 1 : 0);
	display_all(file_lst, flags, (!no_files ? 1 : 2), ac);
	free_list_content(&file_lst);
	return (0);
}
