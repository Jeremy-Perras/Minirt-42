/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:56 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/27 10:51:36 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

#include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_cy
{
	double x;
	double y;
	double z
	double vector_x;
	double vector_y;
	double vector_z;
	double diam;
	double height;
	double r;
	double b;
	double c;
}	t_cy;

typedef struct s_pl
{
	double x;
	double y;
	double z;
	double vector_x;
	double vector_y;
	double vector_z;
	double r;
	double g;
	double b;
}	t_pl;

typedef struct s_sp
{
	double x;
	double y;
	double z;
	double diam;
	double r;
	double g;
	double b;
}	t_sp;

typedef struct s_A
{
	double light;
	double red;
	double green;
	double blue;
} t_A;

typedef struct s_C
{
	double x;
	double y;
	double z;
	double vector_x;
	double vector_y;
	double vector_z;
	double fov;
}	t_C

typedef struct s_L
{
	double x;
	double y;
	double z;
	double light;
}	t_L;

typedef struct s_data
{
	t_A *A;
	t_C *C;
	t_L *L;
	t_sp *sp;
	t_pl *pl;
	t_cy *cy;
}	t_data;

typedef struct s_parse
{
	int		A;
	int		C;
	int		L;
	int		sp;
	int		pl;
	int		cy;
} t_parse;

char **ft_parse(char *map);
void ft_init_data(t_data **data);
// void ft_texture(char *line, t_parse *parse);
// void exit_error(char *msg);
// void ft_check_map(char **map);


#endif
