/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:03:23 by jperras           #+#    #+#             */
/*   Updated: 2022/04/28 14:51:02 by jperras          ###   ########.fr       */
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
} t_vector;


typedef struct s_size
{
 int x;
 int y;
} t_size;

typedef struct s_window
{
  void *ref;
  t_size size;
} t_win;

typedef struct s_cy
{
	t_vector vector;
	t_vector origin;
	double diam;
	double height;
	double r;
	double b;
	double g;
}	t_cy;


typedef struct s_pl
{
	double r;
	double g;
	double b;
	t_vector origin;
	t_vector vector;
}	t_pl;

typedef struct s_sp
{
	t_vector origin;
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
	t_vector origin;
	double fov;
  t_vector vector;
}	t_C;

typedef struct s_L
{
	t_vector origin;
	double r;
	double g;
	double b;
	double light;
}	t_L;



typedef struct s_parse
{
	int		A;
	int		C;
	int		L;
	int		sp;
	int		pl;
	int		cy;
} t_parse;

typedef struct s_data
{
  	void *mlx;
  	t_win win;
	t_A *A;
	t_C *C;
	t_L *L;
	t_sp *sp;
	t_pl *pl;
	t_cy *cy;
}	t_data;

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
void ft_put_background(t_data *data);
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
int ft_intermin(t_vector *P, t_vector *N, t_data * data);
double ft_intermulti(t_data *data, t_vector *P, t_vector *N, int i);
/*
* utils.c
*/
int	create_trgb(int t, int r, int g, int b);
void	ft_puthexa(int b, int *m, char *c);

#endif
