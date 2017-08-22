/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:00:05 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/14 17:04:44 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	if (str == NULL || f == NULL)
		return (NULL);
	dest = ft_strdup(str);
	if (!dest)
		return (NULL);
	while (dest[i] != '\0' && dest)
	{
		dest[i] = f(i, dest[i]);
		i++;
	}
	return (dest);
}
