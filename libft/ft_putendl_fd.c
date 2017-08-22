/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 22:45:38 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/17 01:15:40 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*str;

	if (!s)
		return ;
	str = (char *)s;
	write(fd, str, ft_strlen(str));
	ft_putchar_fd('\n', fd);
}
