/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:38:20 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/14 17:59:22 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
		dst[i++] = '\0';
	return (dst);
}
