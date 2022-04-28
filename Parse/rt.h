/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:56 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/28 10:47:01 by dhaliti          ###   ########.fr       */
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
	double z;
	double vector_x;
	double vector_y;
	double vector_z;
	double diam;
	double height;
	double r;
	double b;
	double g;
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
	double r;
	double g;
	double b;
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
}	t_C;

typedef struct s_L
{
	double x;
	double y;
	double z;
	double r;
	double g;
	double b;
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

t_data 	*ft_parse(char *map);
void 	ft_init_data(t_data **data);
char	**ft_split2(char *str, char *charset);
void 	exit_error(char *msg);
int		ft_strcmp(char *s1, char *s2);
int 	ft_ambient(char **elem, t_data *data);
int 	ft_camera(char **elem, t_data *data);
int 	ft_light(char **elem, t_data *data);
int 	ft_sphere(char **elem, t_data *data);
int 	ft_plan(char **elem, t_data *data);
int 	ft_cylinder(char **elem, t_data *data);
void 	free_strs(char **str, char **str2);


#endif
