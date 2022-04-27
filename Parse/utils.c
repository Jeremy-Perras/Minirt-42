/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:37:41 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/27 16:39:04 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void exit_error(char *msg)
{
	int i;

	i = -1;
	while (msg[++i])
		printf("\033[0;33m%c", ft_toupper(msg[i]));
	printf("\n");
	exit(1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if ((s1[i] - s2[i]) != 0)
		return (0);
	return (1);
}

void free_strs(char **str, char **str2)
{
	int i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
	if (str2)
	{
		i = -1;
		while (str2[++i])
			free (str2[i]);
		free(str2);
	}
}
