/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:58:40 by pabonnin          #+#    #+#             */
/*   Updated: 2016/11/21 18:52:57 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nb_of_words(const char *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			words++;
		i++;
	}
	if (str[0] != '\0')
		words++;
	return (words);
}

static	char	*ft_wordlen(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen((char *)str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		word;
	char	**s;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	word = ft_nb_of_words(str, c);
	if (!(s = (char **)malloc(sizeof(s) * (word + 2))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < word && str[i])
	{
		s[j] = ft_wordlen(str, c, &i);
		j++;
	}
	s[j] = NULL;
	return (s);
}
