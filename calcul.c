/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:36:41 by jperras           #+#    #+#             */
/*   Updated: 2022/04/29 11:47:23 by jperras          ###   ########.fr       */
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
    tmp = ft_intermulti(data, P, N, i);
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

double ft_intermulti(t_data *data, t_vector *P, t_vector *N,int i)
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
  vector.x = data->C->origin.x - data->sp[i].origin.x ;
  vector.y = data->C->origin.y - data->sp[i].origin.y ;
  vector.z = data->C->origin.z - data->sp[i].origin.z ;
  b = 2.0 * ft_sca(data->C->vector, vector);
  c = ft_norm2(vector) - (data->sp[i].diam / 2) * (data->sp[i].diam / 2);
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
  P->x = data->C->origin.x + t * data->C->vector.x;
  P->y = data->C->origin.y + t * data->C->vector.y;
  P->z = data->C->origin.z + t * data->C->vector.z;
  N->x = P->x-data->sp[i].origin.x;
  N->y = P->y-data->sp[i].origin.y;
  N->z = P->z-data->sp[i].origin.z;
  *N = ft_norm(*N);
  return(t);

}
