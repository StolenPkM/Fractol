/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 23:58:17 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/17 16:23:30 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (s != NULL)
	{
		while (*s)
			s++;
		if ((char)c == '\0')
			return ((char *)s);
		s--;
		while (*s != (char)c && *s)
			s--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
