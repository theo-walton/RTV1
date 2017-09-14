
NAME = rt

SRC = \
	$(addprefix src/, \
\
	coor_diff.c \
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
	coor_diff.o \
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

re: fclean all
