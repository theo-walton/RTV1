
NAME = rt

SRC = \
	$(addprefix src/, \
\
	coor_diff.c \
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
	lights_init.c \
	main.c \
	objects_init.c \
	apply_pixel_extrapolation.c \
	colour_merge.c \
	path_to_light.c \
	print_intersect.c \
	) \
\
	$(addprefix libft/, \
\
	ft_memmove.c \
	) \
\

OBJ =  \
	$(addprefix obj/, \
\
	ft_memmove.o \
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
	lights_init.o \
	main.o \
	objects_init.o \
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
