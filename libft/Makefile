# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalton <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/09 23:33:17 by twalton           #+#    #+#              #
#    Updated: 2017/07/16 17:14:58 by twalton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(wildcard *.c)

all: $(NAME)

$(NAME): 
	@gcc -Wall -Wextra -Werror -I includes -c $(SRC)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -rf $(wildcard *.o)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
