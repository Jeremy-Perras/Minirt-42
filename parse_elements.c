/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:50:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/28 11:42:45 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int ft_ambient(char **elem, t_data *data)
{
	double light;
	char	**colors;
	int 	r;
	int		g;
	int		b;

	if (!elem[2] || elem[3])
		exit_error("a Element: invalid data");
	light = ft_atof(elem[1]);
	if (light < 0.0 || light > 1.0)
		exit_error("a Element: invalid ambient lightining value");
	colors = ft_split(elem[2], ',');
	if (!colors[2] || colors[3])
		exit_error("a Element: invalid ambient lightning coloration");
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_error("a Element: invalid ambient lightning coloration");
	data->A->light = light;
	data->A->r = r;
	data->A->g = g;
	data->A->b = b;
	free_strs(colors, NULL);
	return (1);
}

int ft_camera(char **elem, t_data *data)
{
	char	**points;
	char 	**vector;

	if (!elem[3] || elem[4])
		exit_error("c Element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("c Element: Invalid camera coordinates");
	data->C->origin.x = ft_atof(points[0]);
	data->C->origin.y = ft_atof(points[1]);
	data->C->origin.z = ft_atof(points[2]);
	vector = ft_split(elem[2], ',');
	if (!vector[2] || vector[3])
		exit_error("c Element: Invalid camera orientation");
	data->C->vector.x = ft_atof(vector[0]);
	data->C->vector.y = ft_atof(vector[1]);
	data->C->vector.z = ft_atof(vector[2]);
	if (data->C->vector.x < 0.0 || data->C->vector.x > 1.0 || data->C->vector.y < 0.0
		|| data->C->vector.y > 1.0 || data->C->vector.z < 0.0 || data->C->vector.z > 1.0)
		exit_error("c Element: Invalid camera orientation");
	data->C->fov = ft_atof(elem[3]);
	if (data->C->fov < 0.0 || data->C->fov > 180.0)
		exit_error("c Element: Invalid camera field of view");
	free_strs(points, vector);
	return (1);
}

int ft_light(char **elem, t_data *data)
{
	char **points;
	char **colors;

	if (!elem[3] || elem[4])
		exit_error("L element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("L element: invalid coordinates");
	data->L->origin.x = ft_atof(points[0]);
	data->L->origin.y = ft_atof(points[1]);
	data->L->origin.z = ft_atof(points[2]);
	data->L->light = ft_atof(elem[2]);
	if (data->L->light < 0.0 || data->L->light > 1.0)
		exit_error("invalid light brightness");
	colors = ft_split(elem[3], ',');
	if (!colors[2] || colors[3])
		exit_error("L element: invalid colors");
	data->L->r = ft_atof(colors[0]);
	data->L->g = ft_atof(colors[1]);
	data->L->b = ft_atof(colors[2]);
	if (data->L->r < 0 || data->L->r > 255 || data->L->g < 0 || data->L->g > 255
		|| data->L->b < 0 || data->L->b > 255)
		exit_error("L element: invalid color values");
	free_strs(points, colors);
	return (1);
}

int ft_sphere(char **elem, t_data *data)
{
	char **points;
	char **colors;

	if (!elem[3] || elem[4])
		exit_error("Sphere element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("Sphere element: invalid coordinates");
	data->sp->origin.x = ft_atof(points[0]);
	data->sp->origin.y = ft_atof(points[1]);
	data->sp->origin.z = ft_atof(points[2]);
	data->sp->diam = ft_atof(elem[2]);
	colors = ft_split(elem[3], ',');
	if (!colors[2] || colors[3])
		exit_error("Sphere element: invalid colors");
	data->sp->r = ft_atof(colors[0]);
	data->sp->g = ft_atof(colors[1]);
	data->sp->b = ft_atof(colors[2]);
	if (data->sp->r < 0 || data->sp->r > 255 || data->sp->g < 0 || data->sp->g > 255
		|| data->sp->b < 0 || data->sp->b > 255)
		exit_error("Sphere element: invalid color values");
	free_strs(points, colors);
	return (1);
}

int ft_plan(char **elem, t_data *data)
{
	char **points;
	char **vector;
	char **colors;

	if (!elem[3] || elem[4])
		exit_error("Plan element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("Plan element: invalid coordinates");
	data->pl->origin.x = ft_atof(points[0]);
	data->pl->origin.y = ft_atof(points[1]);
	data->pl->origin.z = ft_atof(points[2]);
	vector = ft_split(elem[2], ',');
	if (!vector[2] || vector[3])
		exit_error("Plan element: insufficient vector orientation");
	data->pl->vector.x = ft_atof(vector[0]);
	data->pl->vector.y = ft_atof(vector[1]);
	data->pl->vector.z = ft_atof(vector[2]);
	if (data->pl->vector.x < 0.0 || data->pl->vector.x > 1.0 || data->pl->vector.y < 0.0
	|| data->pl->vector.y > 1.0 || data->pl->vector.z < 0.0 || data->pl->vector.z > 1.0)
		exit_error("Plan element: invalid vector orientation");
	colors = ft_split(elem[3], ',');
	if (!colors[2] || colors[3])
		exit_error("Plan element: invalid colors");
	data->pl->r = ft_atof(colors[0]);
	data->pl->g = ft_atof(colors[1]);
	data->pl->b = ft_atof(colors[2]);
	if (data->pl->r < 0 || data->pl->r > 255 || data->pl->g < 0 || data->pl->g > 255
		|| data->pl->b <0 || data->pl->b > 255)
		exit_error("Plan element: invalid color values");
	free_strs(points, colors);
	return (1);
}

int ft_cylinder(char **elem, t_data *data)
{
	char **points;
	char **vector;
	char **colors;

	if (!elem[5] || elem[6])
		exit_error("Cylinder element: invalid data");
	points = ft_split(elem[1], ',');
	if (!points[2] || points[3])
		exit_error("Cylinder element: invalid coordinates");
	data->cy->origin.x = ft_atof(points[0]);
	data->cy->origin.y = ft_atof(points[1]);
	data->cy->origin.z = ft_atof(points[2]);
	vector = ft_split(elem[2], ',');
	if (!vector[2] || vector[3])
		exit_error("Cylinder element: insufficient vector orientation");
	data->pl->vector.x = ft_atof(vector[0]);
	data->pl->vector.y = ft_atof(vector[1]);
	data->pl->vector.z = ft_atof(vector[2]);
	if (data->pl->vector.x < 0 || data->pl->vector.x > 1.0 || data->pl->vector.y < 0
	|| data->pl->vector.y > 1.0 || data->pl->vector.z < 0 || data->pl->vector.z > 1.0)
		exit_error("Cylinder element: invalid vector orientation");
	data->cy->diam = ft_atof(elem[3]);
	data->cy->height = ft_atof(elem[4]);
	colors = ft_split(elem[5], ',');
	if (!colors[2] || colors[3])
		exit_error("Plan element: invalid colors");
	data->cy->r = ft_atof(colors[0]);
	data->cy->g = ft_atof(colors[1]);
	data->cy->b = ft_atof(colors[2]);
	if (data->cy->r < 0 || data->cy->r > 255 || data->cy->g < 0 || data->cy->g > 255
		|| data->cy->b < 0 || data->cy->b > 255)
		exit_error("Cylinder element: invalid color values");
	free_strs(points, colors);
	return (1);
}
