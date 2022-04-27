/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:50:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/27 12:05:22 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void free_strs(char **str, char **str2)
{
	int i;
	int j;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
	if (str2)
	{
		i = -1;
		while (str2[++i])
			free (str2[i]);
		free(str2);
	}
}

static int ft_ambient(char **elem, t_parse *parse, t_data *data)
{
	double light;
	char	**colors;
	int 	r;
	int		g;
	int		b;

	if (!elem[2] || elem[3])
		exit_error("invalid data for A element");
	light = ft_atof(elem[1])
	if (light < 0 || light > 1)
		exit_error("invalid value for ambient lightining");
	colors = ft_split(elem[2], ',');
	if (!colors[2] || colors[3])
		exit_error("invalid ambient lightning coloration");
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error("invalid ambient lightning coloration");
	data->A->light = light;
	data->A->r = r;
	data->A->g = g;
	data->A->b = b;
	free_strs(colors, NULL);
	return (1);
}

static int ft_camera(char **elem, t_parse *parse, t_data *data)
{
	char	**points;
	char 	**vector;

	if (!elem[3] || elem[4])
		exit_error("invalid data for C element");
	points = ft_split(elem[1] ',');
	if (!points[2] || points[3])
		exit_error("Invalid camera coordinates");
	data->C->x = ft_atof(points[0]);
	data->C->y = ft_atof(points[1]);
	data->C->z = ft_atof(points[2]);
	vector = ft_split(elem[2], ',');
	if (!vector[2] || vector[3])
		exit_error("Invalid camera orientation");
	data->C->x = ft_atof(vector[0]);
	data->C->y = ft_atof(vector[1]);
	data->C->z = ft_atof(vector[2]);
	if (data->C->x < 0.0 || data->C->x > 1.0 || data->C->y < 0.0
		|| data->C->y > 1.0 || data->C->z < 0.0 || data->C->z > 1.0)
		exit_error("Invalid camera orientation");
	data->C->fov = ft_atof(elem[3])
	if (data->C->fov < 0.0 || data->C->fov > 180.0)
		exit_error("Invalid camera field of view");
	free_strs(points, vector);
	return (1);
}

static int ft_light(char **elem, t_parse *parse, t_data *data)
{
	char **points;
	char **colors;

	if (!elem[3] || elem[4])
		exit_error("L element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("L element: invalid coordinates");
	data->L->x = ft_atof(points[0]);
	data->L->y = ft_atof(points[1]);
	data->L->z = ft_atof(points[2]);
	data->L->light = ft_atof(elem[2]);
	if (data->L->light < 0.0 || data->L->light > 1.0)
		exit_error("invalid light brightness");
	colors = ft_split(elem[3] ',');
	if (!colors[2] || colors[3])
		exit_error("L element: invalid colors");
	data->L->r = ft_atof(colors[0]);
	data->L->g = ft_atof(colors[1]);
	data->L->b = ft_atof(colors[2]);
	if (!data->L->r || data->L->r > 255 || !data->L->g || data->L->g > 255
		|| !data->L->b || data->L->b > 255)
		exit_error("L element: invalid color values");
	free_strs(points, colors);
	return (1);
}

static int ft_sphere(char **elem, t_parse *parse, t_data *data)
{
	char **points;
	char **colors;

	if (!elem[3] || elem[4])
		exit_error("Sphere element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("Sphere element: invalid coordinates");
	data->sp->x = ft_atof(points[0]);
	data->sp->y = ft_atof(points[1]);
	data->sp->z = ft_atof(points[2]);
	data->sp->diam = ft_atof(elem[2]);
	colors = ft_split(elem[3] ',');
	if (!colors[2] || colors[3])
		exit_error("Sphere element: invalid colors");
	data-sp->r = ft_atof(colors[0]);
	data->sp->g = ft_atof(colors[1]);
	data->sp->b = ft_atof(colors[2]);
	if (!data->sp->r || data->sp->r > 255 || !data->sp->g || data->sp->g > 255
		|| !data->sp->b || data->sp->b > 255)
		exit_error("Sphere element: invalid color values");
	free_strs(points, colors);
	return (1);
}

static int ft_plan(char **elem, t_parse *parse, t_data *data)
{
	char **points;
	char **vector;
	char **colors;

	if (!elem[3] || elem[4])
		exit_error("Plan element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("Plan element: invalid coordinates");
	data->pl->x = ft_atof(points[0]);
	data->pl->y = ft_atof(points[1]);
	data->pl->z = ft_atof(points[2]);
	vector = ft_split(elem[2], ',');
	if (!vector[2] || vector[3])
		exit_error("Plan element: invalid vector orientation");
	data->pl->vector_x = ft_atof(vector[0]);
	data->pl->vector_y = ft_atof(vector[1]);
	data->pl->vector_z = ft_atof(vector[2]);
	if (!data->pl->vector_x || data->pl->vector_x > 1.0 || !data->pl->vector_y
	|| data->pl->vector_y > 1.0 || !data->pl->vector_z || data->pl->vector_z > 1.0)
		exit_error("Plan element: invalid vector orientation");
	colors = ft_split(elem[3] ',');
	if (!colors[2] || colors[3])
		exit_error("Plan element: invalid colors");
	data-pl->r = ft_atof(colors[0]);
	data->pl->g = ft_atof(colors[1]);
	data->pl->b = ft_atof(colors[2]);
	if (!data->pl->r || data->pl->r > 255 || !data->pl->g || data->pl->g > 255
		|| !data->pl->b || data->pl->b > 255)
		exit_error("Plan element: invalid color values");
	free_strs(points, colors);
	return (1);
}

static int ft_cylinder(char **elem, t_parse *parse, t_data *data)
{
	char **points;
	char **vector;
	char **colors;

	if (!elem[3] || elem[4])
		exit_error("Plan element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("Plan element: invalid coordinates");
	data->pl->x = ft_atof(points[0]);
	data->pl->y = ft_atof(points[1]);
	data->pl->z = ft_atof(points[2]);
	vector = ft_split(elem[2], ',');
	if (!vector[2] || vector[3])
		exit_error("Plan element: invalid vector orientation");
	data->pl->vector_x = ft_atof(vector[0]);
	data->pl->vector_y = ft_atof(vector[1]);
	data->pl->vector_z = ft_atof(vector[2]);
	if (!data->pl->vector_x || data->pl->vector_x > 1.0 || !data->pl->vector_y
	|| data->pl->vector_y > 1.0 || !data->pl->vector_z || data->pl->vector_z > 1.0)
		exit_error("Plan element: invalid vector orientation");
	colors = ft_split(elem[3] ',');
	if (!colors[2] || colors[3])
		exit_error("Plan element: invalid colors");
	data-pl->r = ft_atof(colors[0]);
	data->pl->g = ft_atof(colors[1]);
	data->pl->b = ft_atof(colors[2]);
	if (!data->pl->r || data->pl->r > 255 || !data->pl->g || data->pl->g > 255
		|| !data->pl->b || data->pl->b > 255)
		exit_error("Plan element: invalid color values");
	free_strs(points, colors);
	return (1);
}
