/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:40:24 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/14 17:05:07 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	if (str == NULL || f == NULL)
		return (NULL);
	dest = ft_strdup(str);
	if (!dest)
		return (NULL);
	while (dest[i])
	{
		dest[i] = f(dest[i]);
		i++;
	}
	return (dest);
}
