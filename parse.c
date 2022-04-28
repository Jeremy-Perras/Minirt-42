/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/28 12:25:20 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void ft_parse_line(char *line, t_parse *parse, t_data *data)
{
	char **elem;

	elem = ft_split2(line, " \t");
	if (ft_strcmp(elem[0], "A"))
		parse->A += ft_ambient(elem, data);
	else if (ft_strcmp(elem[0], "C"))
		parse->C += ft_camera(elem, data);
	else if (ft_strcmp(elem[0], "L"))
		parse->L += ft_light(elem, data);
	else if (ft_strcmp(elem[0], "pl"))
		parse->pl += ft_plan(elem, data);
	else if (ft_strcmp(elem[0], "sp"))
		parse->sp += ft_sphere(elem, data);
	else if (ft_strcmp(elem[0], "cy"))
		parse->cy += ft_cylinder(elem, data);
	else
		exit_error("Unexpected map element");
	free_strs(elem, NULL);
	if (parse->A > 1 || parse->C > 1 || parse->L > 1)
		exit_error("data error");
}

static int ft_is_empty_line(char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] !=  ' ' && line[i] != '\t' && line[i] != '\n')
			return(0);
	}
	return (1);
}

static void ft_init_parse(t_parse **parse)
{
	*parse          = (t_parse *)malloc(sizeof(t_parse));
	(*parse)->A     = 0;
	(*parse)->C     = 0;
	(*parse)->L     = 0;
	(*parse)->pl    = 0;
	(*parse)->sp    = 0;
	(*parse)->cy    = 0;
}

t_data *ft_parse(char *file)
{
	int		fd;
	t_parse *parse;
	t_data	*data;

	ft_init_parse(&parse);
	ft_init_data(&data);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error("File could not be found");
	char *line = get_next_line(fd);
	if (!line)
		exit_error("File is empty");
	while (line != NULL)
	{
		if (!ft_is_empty_line(line))
			ft_parse_line(line, parse, data);
		free(line);
		line = get_next_line(fd);
	}
	if (!parse->A || !parse->L || !parse->C || !parse->pl
			|| !parse->sp || !parse->cy)
		exit_error("Scene elements are missing");
	free(parse);
	return (data);
}
