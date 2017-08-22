/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:00:39 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/14 23:51:05 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)malloc(sizeof(size_t) * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	if ((unsigned char *)mem)
		return ((unsigned char *)mem);
	else
		return (NULL);
}
