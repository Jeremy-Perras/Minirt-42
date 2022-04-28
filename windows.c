/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:36:16 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 12:12:26 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ft_close(void)
{
	exit(0);
}

t_win	ft_windows(void *mlx, int widht, int height, char *title)
{
	t_win	windows;

	windows.ref = mlx_new_window(mlx, widht, height, title);
	windows.size.x = widht;
	windows.size.y = height;
	mlx_hook(windows.ref, 17, 0, ft_close, 0);
	return (windows);
}

void ft_put_pixel(t_data *data)
{
	int	i;
	int	j;
	int k;
	t_vector P;
	t_vector N;
	double inte;
	t_vector vector;
	int color;


	i = 0;
	j = 0;
	while (i < Height)
	{
		while(j < Width)
		{
			color = create_trgb(0,0,0,0);
			data->C->vector.x = j - Width / 2;
			data->C->vector.y = i - Height / 2;
			data->C->vector.z = -(Width / 2) / tan(data->C->fov/2);
			k = ft_intermin(deta->C->vector, &P, &N, data);
			inte = 0;
			if(k)
			{
				vector.x = data->L->origin.x - P.x;
				vector.y = data->L->origin.y - P.y;
				vector.z = data->L->origin.z - P.z;
				vector = ft_norm(vector);
				inte = lumiere.intensite * (ft_sca(vector, N) / ft_norm2(vector));
				if (inte > 255)
					inte = 255;
				if(inte < 0)
					inte = 0;
				if(inte != 0)
					color = create_trgb(inte, 0, 255, 0);
			}
			mlx_pixel_put(data->mlx, data->win.ref, Width- j -1 , Height - i -1, color);
			mlx_pixel_put(data->mlx, data->win.ref, 15, 60, 0x00FFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
}
