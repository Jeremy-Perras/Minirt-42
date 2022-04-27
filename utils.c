/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:55:39 by jperras           #+#    #+#             */
/*   Updated: 2022/04/27 15:02:59 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int	create_trgb(int t, int r, int g, int b)
{
  return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_puthexa(int b, int *m, char *c)
{
	if (b >= 16)
	{
		ft_puthexa(b / 16, m, c);
		ft_puthexa(b % 16, m, c);
	}
	else
	{
		if (b <= 9)
    {
			c[*m] = b + '0';
        *m = *m + 1;
    }
		else
    {
			c[*m] = b + '7';
      *m = *m + 1;
    }
	}
}
