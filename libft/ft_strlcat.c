/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:36:50 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/21 17:41:51 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*destcpy;
	const char	*srccpy;
	size_t		i;
	size_t		len;

	i = size;
	destcpy = dest;
	srccpy = src;
	while (i-- && *destcpy)
		destcpy++;
	len = destcpy - dest;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen((char*)srccpy));
	while (*srccpy)
	{
		if (i != 1)
		{
			*destcpy++ = *srccpy;
			--i;
		}
		srccpy++;
	}
	*destcpy = '\0';
	return (len + (srccpy - src));
}
