/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 00:42:02 by twalton           #+#    #+#             */
/*   Updated: 2017/09/11 00:42:02 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "rtv1_structs.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "keys.h"

# define INFIN 999999999
# define X_DIM 801
# define Y_DIM 601
# define SPHERE 1
# define VEIW_DIST 800

void	print_intersect(t_coor *intersect);

void	coor_diff(t_coor *result, t_coor coor1, t_coor coor2);
double	dot_product(t_coor coor1, t_coor coor2);

t_light	*lights_init(void);
t_object	*objects_init(void);
t_screen	*create_screen(void);

int	get_sphere_intersections(t_intersect *intersect, t_object *object, t_coor *point, t_coor *vector);

void	draw_objects(t_info *info);
void	get_basic_screen_image(t_screen *screen, int *image, t_object *objects, t_light *lights);
t_intersect	*get_first_object_ray_hits(t_coor *point, t_coor *vector, t_object *objects);
int	find_colour_of_intersect(t_intersect *intersect, t_object *objects, t_light *lights);
int	path_to_light(t_coor coor, t_object *objects, t_light *light);

#endif
