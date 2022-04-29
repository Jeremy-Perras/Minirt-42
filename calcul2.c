/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:27:16 by jperras           #+#    #+#             */
/*   Updated: 2022/04/29 13:39:37 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int ft_interplan(t_data *data)
{
  double t;
  t_vector vector;
  t_vector N;

  data->pl->vector.x =  -0.1;
  data->pl->vector.y = 0.5;
  data->pl->vector.z = 0.1;
  vector.x = data->C->origin.x - data->pl->origin.x;
  vector.y = data->C->origin.y - data->pl->origin.y;
  vector.z = data->C->origin.z - data->pl->origin.z;
  N = ft_norm(data->pl->vector);
  t = ft_sca(vector, N) / ft_sca(data->C->vector, N);

  if (t>0)
    return(1);

  return(0);
}
