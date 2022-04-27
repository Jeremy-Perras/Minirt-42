/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:36:16 by jperras           #+#    #+#             */
/*   Updated: 2022/04/27 17:07:57 by jperras          ###   ########.fr       */
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
	t_ray ray;
	t_sphere sphere;
	int k;
	t_lumiere lumiere;
	t_vector P;
	t_vector N;
	double inte;
	t_vector vector;
	int m;
	//int n;
	//char c[2];
	int color;

	lumiere.origin.x = 15 ;
	lumiere.origin.y = 60 ;
	lumiere.origin.z = -40;
	lumiere.intensite = 255;
	sphere.origin.x = 0;
	sphere.origin.y = 0;
	sphere.origin.z = -55;
	sphere.ra = 20;
	ray.origin.x = 0;
	ray.origin.y = 0;
	ray.origin.z = 0;
	i = 0;
	j = 0;
	while (i < Height)
	{
		while(j < Width)
		{
			color = create_trgb(0,0,0,0);
			ray.dir.x = j - Width / 2;
			ray.dir.y = i - Height / 2;
			ray.dir.z = -(Width / 2) / tan(FOV/2);
			ray.dir = ft_norm(ray.dir);
			k = ft_inter(ray, sphere, &P, &N);
			inte = 0;
			if(k)
			{
				vector.x = lumiere.origin.x - P.x;
				vector.y = lumiere.origin.y - P.y;
				vector.z = lumiere.origin.z - P.z;
				vector = ft_norm(vector);
				inte = lumiere.intensite * (ft_sca(vector, N) / ft_norm2(vector));
				if (inte > 255)
					inte = 255;
				if(inte < 0)
					inte = 0;
				m = 0;
				//c[0] = '0';
				//c[1] = '0';
				//n = 0;
				//ft_puthexa(inte, &m, c);
				//n += ft_atoi(&c[0]);
				//n += ft_atoi(&c[1]);
				if(inte != 0)
					color = create_trgb(inte, 0, 255, 0);
				// printf("%f ",inte);
			}
			mlx_pixel_put(data->mlx, data->win.ref, Width- j -1 , Height - i -1, color);
			mlx_pixel_put(data->mlx, data->win.ref, 15, 60, 0x00FFFFFF);
			j++;
		}
		j = 0;
		i++;
	}
}
