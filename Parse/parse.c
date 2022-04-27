/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:33:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/27 11:05:50 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static void ft_check_line(char *line, t_parse *parse)
// {
// 	char caracters[] = "01NSEW \t";
// 	char player[] = "NSEW";
// 	int i = 0;
//
// 	while (line[++i])
// 	{
// 		if (ft_strchr(player, line[i]))
// 			parse->player++;
// 		if (!ft_strchr(caracters, line[i]) || parse->player > 1)
// 			exit_error("Error: Unexpected catacter");
// 	}
// }
//
// static void ft_lab(char *line, t_parse *parse)
// {
// 	static int x = 0;
// 	parse->count = 1;
// 	line[ft_strlen(line) - 1] = '\0';
//  	ft_check_line(line, parse);
// 	parse->map[x] = ft_strdup(line);
// 	x++;
// 	parse->map[x] = NULL;
// }

static void ft_parse_line(char *line, t_parse *parse, t_data *data);
{
	char **elem;

	elem = ft_split2(line);
	if (ft_strcmp(elem[0], "A")
		parse->A += ft_ambient(elem[0], parse, data);
	else if (ft_strncmp(line, "C")
		parse->C += ft_camera(elem[0], parse, data);
	else if (ft_strncmp(line, "L")
		parse->L += ft_light(elem[0], parse, data);
	else if (ft_strncmp(line, "pl")
		parse->pl += ft_plan(elem[0], parse, data);
	else if (ft_strncmp(line, "sp")
		parse->sp += ft_sphere(elem[0], parse, data);
	else if (ft_strncmp(line, "cy")
		parse->cy += ft_cylinder(elem[0], parse, data);
	else
		exit_error("Unexpected map element");

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

char **ft_parse(char *map)
{
	int		fd;
	t_parse *parse;
	t_data	*data;

	ft_init_parse(&parse);
	ft_init_data(&data);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("File could not be found");
	char *line = get_next_line(fd);
	if (!line)
		exit_error("File is empty");
	while (line != NULL)
	{
		if (!ft_is_empty_line(line))
			ft_parse_line(line, parse);
		free(line);
		line = get_next_line(fd);
	}
	if (!parse->A || !parse->L || !parse->C || !parse->pl
			|| !parse->sp || !parse->cy)
		exit_error("Scene elements are missing");
	return (data);
}
