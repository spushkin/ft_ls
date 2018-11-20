/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spushkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:48:59 by spushkin          #+#    #+#             */
/*   Updated: 2018/11/20 09:48:59 by spushkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	nlen;
	size_t	len_needle;
	size_t	i;

	nlen = ft_min(ft_strlen(haystack) + 1, n);
	len_needle = ft_strlen(needle);
	i = 0;
	if (!(unsigned char)needle[0])
		return (char *)(haystack);
	while (i < nlen && len_needle <= (n - i))
	{
		if (ft_strncmp((haystack + i), needle, len_needle) == 0)
			return (char *)(haystack + i);
		i++;
	}
	return (NULL);
}
