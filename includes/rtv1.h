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
# include <time.h>
# include "mlx.h"
# include "libft.h"
# include "rtv1_structs.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "keys.h"

# define INFIN INFINITY
# define X_DIM 801
# define Y_DIM 601

# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

# define VEIW_DIST 800

# define SHINE_CONST 100
# define DECAY_CONST 20000
# define MAX_REFLECT 15
# define MONTE_CARLO_MAX_RAYS 100

void	print_intersect(t_coor *intersect);
void	malloc_break(char c);

void	coor_diff(t_coor *result, t_coor coor1, t_coor coor2);
double	dot_product(t_coor coor1, t_coor coor2);
void	cross_product(t_coor *result, t_coor c1, t_coor c2);
void	second_order_solver(double *result, double a, double b, double c);
int	colour_merge(int col1, int col2);
void	colour_percent(t_colour *result, double percent);
void	colour_sum(t_colour *result, t_colour col1, t_colour col2);
int	col_to_int(t_colour col);
void	zero_colour(t_colour *col);
double	vector_size(t_coor vector);
void	get_reflection(t_coor *reflection, t_coor *vector, t_intersect *intersect);
void	get_shine(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights);
double	get_line_point_distance(t_coor *reflect, t_coor *point, t_light *light);
void	get_indirect_col(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights);
void	get_random_vector(t_coor *result, t_intersect *intersect);
double	rand_fct(void);

t_object	*create_objects(char *str);
void	parse_object(char *str, t_object *object);
void	get_sphere_info(char *str, t_object *object);
void	get_plane_info(char *str, t_object *object);
void	get_cylinder_info(char *str, t_object *object);
t_light	*create_lights(char *str);
void	parse_light(char *str, t_light *light);
t_screen	*create_screen(void);

int	get_sphere_intersections(t_intersect *intersect, t_object *object, t_coor *point, t_coor *vector);
int	get_plane_intersections(t_intersect *intersect, t_object *object, t_coor *point, t_coor *vector);
int	get_cylinder_intersections(t_intersect *intersect, t_object *object, t_coor *point, t_coor *vector);

double	get_light_modifier(t_intersect *intersect, t_light *light);
void	get_normal_to_intersect(t_coor *normal, t_intersect *intersect);
void	get_normal_of_sphere(t_coor *normal, t_intersect *intersect);
void	get_normal_of_plane(t_coor *normal, t_intersect *intersect);
void	get_normal_of_cylinder(t_coor *normal, t_intersect *intersect);

void	draw_objects(t_info *info);
void	get_basic_screen_image(t_screen *screen, int *image, t_object *objects, t_light *lights);
t_intersect	*get_first_object_ray_hits(t_coor *point, t_coor *vector, t_object *objects);
void	find_colour_of_intersect(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights);
void	get_reflect_col(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights);
void	get_diffuse_col(t_colour *result, t_intersect *intersect, t_object *objects, t_light *lights);
int	path_to_light(t_coor coor, t_object *objects, t_light *light);
void	apply_pixel_extrapolation(int *image);

#endif
