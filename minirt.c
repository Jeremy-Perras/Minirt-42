/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:04:07 by jperras           #+#    #+#             */
/*   Updated: 2022/04/27 15:06:47 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"
void ft_init(t_data *data)
{
  data->matrice = malloc(sizeof(t_vector *) * Height);
  data->matrice = malloc(sizeof(t_vector) * Width);
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
