/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spushkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 09:48:59 by spushkin          #+#    #+#             */
/*   Updated: 2018/11/20 09:48:59 by spushkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_binary(unsigned char octet)
{
	unsigned char	i;
	char			*res;
	int				counter;

	res = ft_strnew(8);
	counter = 0;
	i = 128;
	while (i)
	{
		if (i & octet)
			res[counter++] = '1';
		else
			res[counter++] = '0';
		i >>= 1;
	}
	return (res);
}
