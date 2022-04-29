/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:10:04 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/29 16:26:56 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void ft_hooks(t_data *data)
{
	mlx_hook(param->mlx_win, 2, 1L << 0, keypress, data);
	mlx_hook(param->mlx_win, 9, 1L << 21, init_map, data);
	mlx_loop(param->mlx);
}

int	keypress(int code, t_data *data)
{
	if (code == 126)
		data->C->origin.y++;
	if (code == 123)
		data->C->origin.x--;
	if (code == 125)
		data->C->origin.y--;
	if (code == 124)
		data->C->origin.x++;
	if (code == 53)
		ft_close(0);
	ft_put_background(data);
	ft_put_pixel(data);
	return (0);
}
