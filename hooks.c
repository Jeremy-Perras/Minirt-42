/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:10:04 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/29 16:40:09 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	keypress(int code, t_data *data)
{
	if (code == 126)
		data->C->origin.y++;
	if (code == 123)
		data->C->origin.x--;
	if (code == 125)
		data->C->origin.y--;
	if (code == 124)
		data->C->origin.x++;
	if (code == 69)
		data->C->origin.z--;
	if (code == 78)
		data->C->origin.z++;
	if (code == 53)
		ft_close();
	ft_put_background(data);
	ft_put_pixel(data);
	return (0);
}

void ft_hooks(t_data *data)
{
	mlx_hook(data->win.ref, 2, 1L << 0, keypress, data);
	// mlx_hook(data->win.ref, 9, 1L << 21, init_map, data);
	mlx_loop(data->mlx);
}
