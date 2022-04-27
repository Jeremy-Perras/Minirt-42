/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:32:58 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/27 16:59:17 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


int main(int ac, char **av)
{
	t_data *data;

	if (ac < 2)
		exit_error("Error: no scene specified");
	if (ac > 2)
		exit_error("Error: too many scenes specified");
	if (!(ft_strrchr(av[1], '.'))
		|| ft_strncmp((ft_strrchr(av[1], '.')), ".rt", 3) != 0)
		exit_error("Error\nInvalid scene description file");
	data = ft_parse(av[1]);
}
