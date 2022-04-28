/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:48:33 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 12:25:21 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double ft_norm2(t_vector a)
{
  return(a.x * a.x + a.y * a.y + a.z * a.z);
}

t_vector ft_norm(t_vector vector)
{
  double norm;

  norm = sqrt(ft_norm2(vector));
  vector.x = vector.x/norm;
  vector.y = vector.y/norm;
  vector.z = vector.z/norm;
  return(vector);
}
