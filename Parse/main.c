/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:32:58 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/27 09:40:44 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


int main(int ac, char **av)
{
	char **map;

	if (ac < 2)
		return (printf("Error: no scene specified\n"));
	if (ac > 2)
		return (printf("Error: too many scenes specified\n"));
	if (!(ft_strrchr(av[1], '.')) || ft_strncmp((ft_strrchr(av[1], '.')), ".rt", 3) != 0)
		return (printf("Error\n Invalid scene description file\n"));
	map = ft_parse(av[1]);
	ft_check_map(map);
}
