/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:04:07 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 09:52:15 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
void ft_init(t_data *data)
{
  data->matrice = malloc(sizeof(t_vector *) * Height);
  data->matrice = malloc(sizeof(t_vector) * Width);
  data->scene.sphere = malloc(sizeof(t_sphere) * 4);
  data->scene.sphere[0].origin.x = 0;
  data->scene.sphere[0].origin.y = 0;
  data->scene.sphere[0].origin.z = -55;
  data->scene.sphere[0].ra = 20;
  data->scene.sphere[1].origin.x = 0;
	data->scene.sphere[1].origin.y = -2000 -50;
	data->scene.sphere[1].origin.z = 0;
	data->scene.sphere[1].ra = 2000;
  data->scene.sphere[2].origin.x = 0;
	data->scene.sphere[2].origin.y = 2000 + 100;
	data->scene.sphere[2].origin.z = 0;
	data->scene.sphere[2].ra = 2000;
  data->scene.sphere[3].origin.x =  - 2000;
	data->scene.sphere[3].origin.y = 1024 / 2;
	data->scene.sphere[3].origin.z = 0;
	data->scene.sphere[3].ra = 2000;
}

int main(void)
{
  t_data  data;

  data.mlx = mlx_init();
  data.win = ft_windows(data.mlx,Width , Height, "test");
  ft_init(&data);
  ft_put_pixel(&data);
  mlx_loop(data.mlx);
}
