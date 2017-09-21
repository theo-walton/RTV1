/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 20:46:04 by twalton           #+#    #+#             */
/*   Updated: 2017/09/02 20:46:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_STRUCTS_H
# define RTV1_STRUCTS_H


typedef struct s_colour
{
	int red;
	int green;
	int blue;
}	t_colour;

typedef struct s_coor
{
	double x;
	double y;
	double z;
}	t_coor;

typedef struct s_plane
{
	t_coor normal;
	t_coor point;
}	t_plane;

typedef struct s_line
{
	t_coor point;
	t_coor vector;
}	t_line;

typedef struct s_sphere
{
	t_coor center;
	double radius;
}	t_sphere;

typedef struct s_cylinder
{
	t_coor point;
	t_coor vector;
	double radius;
}	t_cylinder;

typedef struct s_cone
{
	t_coor center;
	t_coor vector;
	double angle;
}	t_cone;

typedef struct s_object
{
	int type;
	void *type_info;
	double red;
	double green;
	double blue;
	double shine;
}	t_object;

typedef struct s_intersect
{
	t_coor intersect;
	t_coor vector;
	t_object *object;
}	t_intersect;

typedef struct	s_light
{
	double x;
	double y;
	double z;
	double red;
	double green;
	double blue;
}	t_light;

typedef struct	s_screen
{
	t_coor *coorarr;
	t_coor *vectors;
}	t_screen;

typedef struct	s_info
{
	t_object *objects;
	t_light *lights;
	t_screen *screen;
	void *mlx;
	void *win;
}	t_info;

typedef struct	s_image
{
	void		*ptr;
	int			*im;
	int			bpp;
	int			line_sz;
	int			end;
}				t_image;

#endif
