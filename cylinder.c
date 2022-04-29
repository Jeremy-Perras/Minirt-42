/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:30:28 by jperras           #+#    #+#             */
/*   Updated: 2022/04/29 16:28:42 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int ft_cylinder2(t_data *data)
{
  double a;
  double b;
  double c;
  double t;
  double t1;
  double t2;
  double r;

  double delta;

  a = data->C->vector.x * data->C->vector.x + data->C->vector.z * data->C->vector.z;
  b = 2*(data->C->origin.x * (data->C->vector.x- data->cy->origin.x) + data->C->origin.z * (data->C->vector.z -data->cy->origin.z));
  c = (data->C->origin.x - data->cy->origin.x) * (data->C->origin.x - data->cy->origin.x) +
  (data->C->origin.z - data->cy->origin.z) * (data->C->origin.z - data->cy->origin.z) -
  (data->cy->diam * data->cy->diam) / 4;

  delta   = b * b - 4 * a * c;
  t1 = (-b - sqrt(delta))/(2*a);
  t2 = (-b + sqrt(delta))/(2*a);
  if (t2 < 0)
    return (0);
  if (t1 > 0)
    t = t2;
  else
    t = t1;
  r = data->C->origin.y + t * data->C->vector.y;
  if ((data->cy->diam/2 >= data->cy->origin.y) && (data->cy->diam/2 <= data->cy->origin.y + data->cy->height))
    return (1);
  else
    return (0);
}
