/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:36:16 by jperras           #+#    #+#             */
/*   Updated: 2022/04/29 13:49:30 by jperras          ###   ########.fr       */
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

void ft_put_background(t_data *data)
{
	int	i;
	int	j;
	int color;

	i = 0;
	j = 0;
	while (i < Height)
	{
		while(j < Width)
		{
			color = create_trgb(255 * data->A->light, data->A->r, data->A->g, data->A->b);
			mlx_pixel_put(data->mlx, data->win.ref, i , j, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void ft_put_pixel(t_data *data)
{
	int	i;
	int	j;
	int k;
	int	l;
	t_vector P;
	t_vector N;
	double inte;
	t_vector vector;
	int color;
	int lum;
	// t_ray ray;


	i = 0;
	j = 0;
	lum = 255;
	while (i < Height)
	{
		while(j < Width)
		{
			color = create_trgb(0,0,0,0);
			data->C->vector.x = j - Width / 2;
			data->C->vector.y = i - Height / 2;
			data->C->vector.z = -(Width / (2 * tan(((data->C->fov * M_PI) / 180)/2)));
			data->C->vector = ft_norm(data->C->vector);
			l = ft_intermin(&P, &N, data);
			k = ft_interplan(data);
			inte = 0;
			if( k)
			{
				vector.x = data->L->origin.x - P.x;
				vector.y = data->L->origin.y - P.y;
				vector.z = data->L->origin.z - P.z;
				vector = ft_norm(vector);
				inte = lum * (ft_sca(vector, N) / ft_norm2(vector));
				if (inte > 255)
					inte = 255;
				if(inte < 0)
					inte = 0;
				if(inte != 0)
					color = create_trgb(inte, data->sp->r, data->sp->g, data->sp->b);
				mlx_pixel_put(data->mlx, data->win.ref,  j, i, color);
			}
			 //lx_pixel_put(data->mlx, data->win.ref,  j, i, color);
			j++;
		}
		j = 0;
		i++;
	}
}
