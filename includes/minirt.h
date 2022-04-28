/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:03:23 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 10:54:53 by dhaliti          ###   ########.fr       */
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
# define FOV ((60 * M_PI) / 180)


typedef struct s_vector
{
 double x;
 double y;
 double z;
 double color;
} t_vector;

typedef struct s_ray
{
  t_vector  origin;
  t_vector  dir;
} t_ray;

typedef struct s_sphere
{
  t_vector  origin;
  t_vector  dir;
  double    ra;
} t_sphere;

typedef struct s_lumiere
{
  t_vector  origin;
  double    intensite;
} t_lumiere;

typedef struct scene
{
  t_sphere *sphere;
} t_scene;


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
  t_scene scene;
} t_data;

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

/*
parse.c
*/
t_data 	*ft_parse(char *map);

/*
init_data.c
*/
void 	ft_init_data(t_data **data);

/*
ft_split2.c
*/
char	**ft_split2(char *str, char *charset);

/*
utils_parse.c
*/
void 	exit_error(char *msg);
int		ft_strcmp(char *s1, char *s2);
void 	free_strs(char **str, char **str2);

/*
parse_elements.c
*/
int 	ft_ambient(char **elem, t_data *data);
int 	ft_camera(char **elem, t_data *data);
int 	ft_light(char **elem, t_data *data);
int 	ft_sphere(char **elem, t_data *data);
int 	ft_plan(char **elem, t_data *data);
int 	ft_cylinder(char **elem, t_data *data);

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
int ft_inter(t_ray ray, t_sphere sphere, t_vector *P, t_vector *N);
double ft_intermulti(t_ray ray, t_sphere sphere, t_vector *P, t_vector *N);
int ft_intermin(t_ray ray, t_vector *P, t_vector *N, t_data * data);
/*
* utils.c
*/
int	create_trgb(int t, int r, int g, int b);
void	ft_puthexa(int b, int *m, char *c);

#endif
