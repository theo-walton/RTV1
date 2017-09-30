
NAME = rt

SRC = \
	$(addprefix src/, \
\
	create_objects.c \
	create_lights.c \
	parse_light.c \
	parse_object.c \
	get_sphere_info.c \
	get_plane_info.c \
	coor_diff.c \
	rand_fct.c \
	get_indirect_col.c \
	get_random_vector.c \
	zero_colour.c \
	col_to_int.c \
	second_order_solver.c \
	get_cylinder_intersections.c \
	get_normal_of_cylinder.c \
	cross_product.c \
	get_line_point_distance.c \
	get_shine.c \
	malloc_break.c \
	get_plane_intersections.c \
	get_normal_of_plane.c \
	get_reflection.c \
	get_reflect_col.c \
	get_diffuse_col.c \
	colour_sum.c \
	colour_percent.c \
	vector_size.c \
	get_light_modifier.c \
	get_normal_of_sphere.c \
	get_normal_to_intersect.c \
	create_screen.c \
	dot_product.c \
	draw_objects.c \
	find_colour_of_intersect.c \
	get_basic_screen_image.c \
	get_first_object_ray_hits.c \
	get_sphere_intersections.c \
	main.c \
	apply_pixel_extrapolation.c \
	colour_merge.c \
	path_to_light.c \
	print_intersect.c \
	) \
\
	$(addprefix libft/, \
\
	ft_strlen.c \
	ft_atoi.c \
	ft_strncmp.c \
	ft_strstr.c \
	ft_strchr.c \
	ft_dirty_read.c \
	ft_memmove.c \
	ft_memset.c \
	) \
\

OBJ =  \
	$(addprefix obj/, \
\
	ft_strlen.o \
	ft_atoi.o \
	ft_strncmp.o \
	ft_strstr.o \
	ft_strchr.o \
	ft_dirty_read.o \
	create_objects.o \
	create_lights.o \
	parse_light.o \
	parse_object.o \
	get_sphere_info.o \
	get_plane_info.o \
	ft_memmove.o \
	ft_memset.o \
	rand_fct.o \
	get_indirect_col.o \
	get_random_vector.o \
	col_to_int.o \
	zero_colour.o \
	second_order_solver.o \
	get_cylinder_intersections.o \
	get_normal_of_cylinder.o \
	get_line_point_distance.o \
	get_shine.o \
	cross_product.o \
	malloc_break.o \
	get_reflection.o \
	get_reflect_col.o \
	get_diffuse_col.o \
	colour_sum.o \
	get_plane_intersections.o \
	get_normal_of_plane.o \
	colour_percent.o \
	vector_size.o \
	get_light_modifier.o \
	get_normal_of_sphere.o \
	get_normal_to_intersect.o \
	coor_diff.o \
	apply_pixel_extrapolation.o \
	colour_merge.o \
	create_screen.o \
	dot_product.o \
	draw_objects.o \
	find_colour_of_intersect.o \
	get_basic_screen_image.o \
	get_first_object_ray_hits.o \
	get_sphere_intersections.o \
	main.o \
	path_to_light.o \
	print_intersect.o \
	) \
\

FLAGS = # -Wall -Wextra -Werror

INC = -I ./minilibx -I ./includes -I ./libft/includes

PATH = minilibx -lmlx -framework OpenGL -framework AppKit

MLBX = minilibx/libmlx.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) $(INC)
	/bin/mv *.o obj
	gcc $(FLAGS) -L $(PATH) $(OBJ) $(MLBX) -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

test: $(NAME)
	./rt

re: fclean all
