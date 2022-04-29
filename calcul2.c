/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:27:16 by jperras           #+#    #+#             */
/*   Updated: 2022/04/29 09:47:23 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

double ft_plan2(t_data *data)
{
  double d;
  d = -(data->pl->vector.x) *(data->pl->origin.x)-(data->pl->vector.y) * (data->pl->origin.y)-
  (data->pl->vector.z) * (data->pl->origin.z);
  return(d);
}
int ft_interplan(t_data *data)
{
  double result;

result = (data->pl->vector.x) * data->C->vector.x +
(data->pl->vector.y) * (data->C->vector.y) + (data->pl->vector.z) * (data->C->vector.z) + ft_plan2(data);
printf("%f\n",result);
if (!result)
  return(1);
return(0);


}
