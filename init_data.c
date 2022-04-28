/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:49:49 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/27 15:09:56 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


static void ft_init_cylinder(t_cy *cy)
{
	cy->x = 0;
	cy->y = 0;
	cy->z = 0;
	cy->vector_x = 0;
	cy->vector_y = 0;
	cy->vector_z = 0;
	cy->diam = 0;
	cy->height = 0;
	cy->r = 0;
	cy->b = 0;
	cy->c = 0;
}

static void ft_init_plan(t_pl *pl)
{
	pl->x = 0;
	pl->y = 0;
	pl->z = 0;
	pl->vector_x = 0;
	pl->vector_y = 0;
	pl->vector_z = 0;
	pl->r = 0;
	pl->g = 0;
	pl->b = 0;
}

static void ft_init_sphere(t_sp *sp)
{
	sp->x = 0;
	sp->y = 0;
	sp->z = 0;
	sp->diam = 0;
	sp->r = 0;
	sp->g = 0;
	sp->b = 0;
}

static void ft_init_objects(t_sp *sp, t_pl *pl, t_cy *cy)
{
	ft_init_sphere(sp);
	ft_init_plan(pl);
	ft_init_cylinder(cy);
}

void ft_init_data(t_data **data)
{
	t_data *tmp;

	*data = (t_data *)malloc(sizeof(t_data));
	tmp = *data;
	tmp->A = (t_A *)malloc(sizeof(t_A));
	tmp->A->light = 0;
	tmp->A->r = 0;
	tmp->A->g = 0;
	tmp->A->b = 0;
	tmp->C = (t_C *)malloc(sizeof(t_C));
	tmp->C->x = 0;
	tmp->C->y = 0;
	tmp->C->z = 0;
	tmp->C->vector_x = 0;
	tmp->C->vector_y = 0;
	tmp->C->vector_z = 0;
	tmp->C->fov = 0;
	tmp->L = (t_L *)malloc(sizeof(t_L));
	tmp->L->x = 0;
	tmp->L->y = 0;
	tmp->L->z = 0;
	tmp->L->light = 0;
	tmp->sp = (t_sp *)malloc(sizeof(t_sp));
	tmp->pl = (t_pl *)malloc(sizeof(t_pl));
	tmp->cy = (t_cy *)malloc(sizeof(t_cy));
	ft_init_objects(tmp->sp, tmp->pl, tmp->cy);
}
