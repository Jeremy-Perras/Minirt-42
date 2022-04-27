/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:03:23 by jperras           #+#    #+#             */
/*   Updated: 2022/04/27 15:06:52 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINIRT_H
# define MINIRT_H
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# define Height 1024
# define Width 1024
# define Screen 128
# define FOV ((60 * M_PI) / 180)


typedef struct s_vector
{
 double x;
 double y;
 double z;
 double color;
} t_vector;

typedef struct ray
{
  t_vector  origin;
  t_vector  dir;
} t_ray;

typedef struct sphere
{
  t_vector  origin;
  t_vector  dir;
  double ra;
} t_sphere;

typedef struct lumiere
{
  t_vector  origin;
  double intensite;
} t_lumiere;

typedef struct s_size
{
 int x;
 int y;
} t_size;

typedef struct s_image
{
  void * ref;
  t_size size;
} t_image;

typedef struct s_window
{
  void *ref;
  t_size size;
} t_win;

typedef struct s_data
{
  void *mlx;
  t_win win;
  t_image *image;
  t_vector **matrice;
} t_data;

/*
* windows.c
*/
t_win   ft_windows(void *mlx, int widht, int height, char *title);
void ft_put_pixel(t_data *data);

/*
* vector.c
*/
t_vector ft_add(t_vector a, t_vector b);
t_vector ft_sous(t_vector a, t_vector b);
t_vector ft_multi(double a, t_vector b);
t_vector ft_div(double a, t_vector b);
double ft_sca(t_vector a, t_vector b);
/*
* vector2.c
*/
double ft_norm2(t_vector vector);
t_vector ft_norm(t_vector vector);
/*
* calcul.c
*/
//int ft_inter(t_ray ray, t_sphere sphere);
int ft_inter(t_ray ray, t_sphere sphere, t_vector *P, t_vector *N);
/*
* utils.c
*/
int	create_trgb(int t, int r, int g, int b);
void	ft_puthexa(int b, int *m, char *c);

#endif
