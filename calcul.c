/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:36:41 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 12:08:07 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int ft_intermin(t_vector *P, t_vector *N, t_data * data)
{
  int i;
  double min = 2000000;
  double tmp = 0;
  int flag = 0;

  i = 0;
  while (i < 1)
  {
    tmp = ft_intermulti(data->C.vector, data->sp[i], P, N);
    if (tmp != 0 && tmp < min && tmp > 0)
    {
      min = tmp;
      *P = *P;
      *N = *N;
      flag = 1;
    }
    i++;
  }
  if(flag == 1)
    return(1);
  return(0);
}

double ft_intermulti(t_data *data, t_sp sphere, t_vector *P, t_vector *N)
{
  double a;
  double b;
  double c;
  double delta;
  double t1;
  double t2;
  t_vector vector;
  double t;

  a = 1;
  vector.x = data->C->origin.x - data->sp->origin.x ;
  vector.y = data->C->origin.y - data->sp->origin.y ;
  vector.z = data->C->origin.z - data->sp->origin.z ;
  b = 2.0 * ft_sca(data->C.vector, vector);
  c = ft_norm2(vector) - sphere.ra * sphere.ra;

  delta = b * b - 4 * a * c;
  if (delta < 0)
    return(0);
  t1 = (-b - sqrt(delta)) / (2 * a);
  t2 = (-b + sqrt(delta)) / (2 * a);
  if (t2 < 0)
    return(0);
  if(t1 > 0)
    t = t1;
  else
    t = t2;
  P->x = delta->C->origin.x + t * detla->C->vector.x;
  P->y = delta->C->originy + t * delta->vector.y;
  P->z = delta->C->origin.z + t * delta->vector.z;
  N->x = P->x-sp.origin.x;
  N->y = P->y-sp.origin.y;
  N->z = P->z-sp.origin.z;
  *N = ft_norm(*N);
  return(t);

}
