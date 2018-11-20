/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spushkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:47:21 by spushkin          #+#    #+#             */
/*   Updated: 2018/11/20 09:47:21 by spushkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** function to get file type
**
** S_IFMT - Type of file.
** S_ISREG(m) - Test for a regular file.
** S_ISDIR(m) - Test for a directory.
** S_ISLNK(m) - Test for a symbolic link.
** S_ISBLK(m) - Test for a block special file.
** S_ISCHR(m) - Test for a character special file.
** S_ISSOCK(m) - Test for a socket.
** S_ISFIFO(m) - Test for a pipe or FIFO special file.
*/

static char		get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

/*
** function to get number of links
**
** listxattr() - retrieves a list of names of extended attributes
** associated with the given path in the file system.
** ACL - Access Control Lists
*/

static char		get_file_acl(char path[PATH_MAX])
{
	acl_t	tmp;
	char	buf[101];

	if (listxattr(path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

/*
** get CHMOD information (print permissions)
**
** Macro constants are defined in sys/stat.h.
** https://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html
** "S" - is for STAT
** "I" - for INODE
** "R" - for READ
** "USR" - for USER.
** "GRP" - GROUP
** S_IROTH - Read permission for users other than the file owner.
**
** S_ISUID - Privilege to set the user ID (UID) for execution.
** S_ISGID - Privilege to set group ID (GID) for execution.
** S_ISVTX - Indicates shared text. Keep loaded as an executable file
** in storage.
*/

static void		display_chmod(char chmod[12], int mode, char path[PATH_MAX])
{
	chmod[0] = get_file_type(mode);
	chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[10] = get_file_acl(path);
	chmod[11] = '\0';
	if (S_ISUID & mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
	ft_putstr(chmod);
}

/*
** display time
** s + 4 to trim day
** %.12s in order to remove seconds and year.
**
** time() - time command execution.
** ctime() - adjusts the time value for the current time zone.
*/

static void		display_time(t_file *file)
{
	time_t	today;
	char	*s;

	time(&today);
	s = ctime(&(file->time)) + 4;
	ft_printf(" %.12s ", s);
}

/*
** function used for -l option
** name is not display is file type is a link
**
** readlink() - only the target of the symbolic link is printed.
*/

int				display_list_items(t_file *file, int size[7], int flags)
{
	char	str[12];
	char	buf[NAME_MAX + 1];

	(flags & LS_S) ? ft_printf("%*hu ", size[0], file->st_blocks) : 0;
	display_chmod(str, file->mode, file->full_path);
	ft_printf(" %*hu", size[1], file->st_nlink);
	ft_printf(" %-*s", size[2], getpwuid(file->st_uid)->pw_name);
	ft_printf("  %-*s", size[3], getgrgid(file->st_gid)->gr_name);
	if (str[0] != 'c' && str[0] != 'b')
		ft_printf("  %*lld", size[4], file->size);
	else
	{
		ft_printf(" %*d", size[5], major(file->st_rdev));
		ft_printf(", %*d", size[6], minor(file->st_rdev));
	}
	display_time(file);
	if (str[0] != 'l')
		display_name(file, flags, 0);
	else
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(file->full_path, buf, NAME_MAX);
		ft_printf("%s -> %s", file->name, buf);
	}
	return (1);
}
