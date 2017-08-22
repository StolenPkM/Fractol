/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:45:53 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/21 13:58:18 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t size)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (size == 0)
		return (1);
	while (i < size && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if ((s1[i] == '\0' && s2[i] == '\0') || (i == size))
		return (1);
	else
		return (0);
}
