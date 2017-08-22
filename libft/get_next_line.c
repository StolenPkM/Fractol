/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 19:04:24 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/09 11:40:22 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (!str[i])
		return (i);
	else
		return (i + 1);
}

char	*ft_strdup_c(char *src, char *dest, char c)
{
	int	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen_c(src, c) + 1));
	if (!dest)
		return (0);
	while (src[i] != c && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		read_one_line(int const fd, char **b_tmp)
{
	int				byte_r;
	char			buff[BUFF_SIZE + 1];

	byte_r = 1;
	while (byte_r > 0 && !ft_strstr(*b_tmp, "\n"))
	{
		byte_r = read(fd, &buff, BUFF_SIZE);
		if (byte_r == -1)
			return (byte_r);
		buff[byte_r] = '\0';
		*b_tmp = ft_strjoin(*b_tmp, buff);
		ft_memset(buff, '\0', byte_r);
	}
	return (byte_r);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t			b_read;
	static char		*b_tmp;
	char			*ftmp;

	if (!b_tmp)
	{
		b_tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		if (!b_tmp)
			return (0);
	}
	if (!line)
		return (-1);
	if ((b_read = read_one_line(fd, &b_tmp)) == -1)
		return (-1);
	line[0] = ft_strdup_c(b_tmp, line[0], '\n');
	ftmp = b_tmp;
	b_tmp = ft_strdup(b_tmp + ft_strlen_c(b_tmp, '\n'));
	free(ftmp);
	return (**line || b_read > 0 ? 1 : 0);
}
