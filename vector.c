/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:16:35 by jperras           #+#    #+#             */
/*   Updated: 2022/04/27 11:58:50 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector ft_add(t_vector a, t_vector b)
{
  t_vector vector;

  vector.x = a.x + b.x;
  vector.y = a.y + b.y;
  vector.z = a.z + b.z;

  return(vector);
}

t_vector ft_sous(t_vector a, t_vector b)
{
  t_vector vector;

  vector.x = a.x - b.x;
  vector.y = a.y - b.y;
  vector.z = a.z - b.z;

  return(vector);
}

t_vector ft_multi(double a, t_vector b)
{
  t_vector vector;

  vector.x = a * b.x;
  vector.y = a * b.y;
  vector.z = a * b.z;

  return(vector);
}

t_vector ft_div(double a, t_vector b)
{
  t_vector vector;

  vector.x = b.x / a;
  vector.y = b.y / a;
  vector.z = b.z / a;

  return(vector);
}

double ft_sca(t_vector a, t_vector b)
{
  return(a.x * b.x + a.y * b.y + a.z * b.z);
}
