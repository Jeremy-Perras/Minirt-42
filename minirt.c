/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:04:07 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 12:06:28 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int main(int ac, char **av)
{
  t_data  *data;

  if (ac < 2)
		exit_error("Error: no scene specified");
	if (ac > 2)
		exit_error("Error: too many scenes specified");
	if (!(ft_strrchr(av[1], '.'))
		|| ft_strncmp((ft_strrchr(av[1], '.')), ".rt", 3) != 0)
		exit_error("Error\nInvalid scene description file");
  data = ft_parse(av[1]);
  data->mlx = mlx_init();
  data->win = ft_windows(data->mlx,Width , Height, "test");
  ft_put_pixel(data);
  mlx_loop(data->mlx);
}
