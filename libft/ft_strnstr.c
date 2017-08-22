/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:45:29 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/17 16:31:39 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0' && len >= (size_t)ft_strlen((char *)little) && len--)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	if (little[0] == '\0')
		return ((char *)big + i);
	return (NULL);
}
