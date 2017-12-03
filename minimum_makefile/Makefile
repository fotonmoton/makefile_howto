# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 21:33:45 by gtertysh          #+#    #+#              #
#    Updated: 2017/12/03 21:38:02 by gtertysh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =          program_name

SRC_DIR =       ./src/
OBJ_DIR =       ./obj/
INC_DIR =       ./inc/
LIB_DIR =       ./lib/

SRC =           main.c hello.c

OBJ =           $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	cc -c $< -o $@ -I $(INC_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

vpath %.c $(SRC_DIR)
