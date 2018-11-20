/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spushkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:48:59 by spushkin          #+#    #+#             */
/*   Updated: 2018/11/20 09:48:59 by spushkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *csrc;
	char *cdst;

	cdst = (char*)dst;
	csrc = (char*)src;
	if (csrc < cdst)
	{
		csrc += len - 1;
		cdst += len - 1;
		while (len > 0)
		{
			*cdst-- = *csrc--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*cdst++ = *csrc++;
			len--;
		}
	}
	return (dst);
}
