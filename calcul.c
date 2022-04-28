/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:36:41 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 10:21:31 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int ft_inter(t_ray ray, t_sphere sphere, t_vector *P, t_vector *N)
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
  vector.x = ray.origin.x - sphere.origin.x ;
  vector.y = ray.origin.y - sphere.origin.y ;
  vector.z = ray.origin.z - sphere.origin.z ;
  b = 2.0 * ft_sca(ray.dir, vector);
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
  P->x = ray.origin.x +t * ray.dir.x;
  P->y = ray.origin.y +t * ray.dir.y;
  P->z = ray.origin.z +t * ray.dir.z;
  N->x = P->x-sphere.origin.x;
  N->y = P->y-sphere.origin.y;
  N->z = P->z-sphere.origin.z;
  *N = ft_norm(*N);
  return(1);

}

int ft_intermin(t_ray ray, t_vector *P, t_vector *N, t_data * data)
{
  int i;
  double min = 2000000;
  double tmp = 0;
  int flag = 0;

  i = 0;
  while (i < 1)
  {
    tmp = ft_intermulti(ray,data->scene.sphere[i], P, N);
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

double ft_intermulti(t_ray ray, t_sphere sphere, t_vector *P, t_vector *N)
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
  vector.x = ray.origin.x - sphere.origin.x ;
  vector.y = ray.origin.y - sphere.origin.y ;
  vector.z = ray.origin.z - sphere.origin.z ;
  b = 2.0 * ft_sca(ray.dir, vector);
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
  P->x = ray.origin.x +t * ray.dir.x;
  P->y = ray.origin.y +t * ray.dir.y;
  P->z = ray.origin.z +t * ray.dir.z;
  N->x = P->x-sphere.origin.x;
  N->y = P->y-sphere.origin.y;
  N->z = P->z-sphere.origin.z;
  *N = ft_norm(*N);
  return(t);

}
