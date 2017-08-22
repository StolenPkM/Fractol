/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:55:37 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/21 17:22:24 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		j;

	i = 0;
	j = (size_t)start;
	if (!s)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ((size_t)len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		dest[i] = s[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
