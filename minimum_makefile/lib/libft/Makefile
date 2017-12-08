# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtertysh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:42:56 by gtertysh          #+#    #+#              #
#    Updated: 2017/11/05 19:14:29 by gtertysh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_memset.c		    \
	  ft_bzero.c		    \
	  ft_memcpy.c		    \
	  ft_memccpy.c		    \
	  ft_memmove.c		    \
	  ft_memchr.c		    \
	  ft_memcmp.c		    \
	  ft_strlen.c		    \
	  ft_strdup.c		    \
	  ft_strcpy.c		    \
	  ft_strncpy.c		    \
	  ft_strcat.c		    \
	  ft_strncat.c		    \
	  ft_strlcat.c		    \
	  ft_strchr.c		    \
	  ft_strrchr.c		    \
	  ft_strstr.c		    \
	  ft_strnstr.c		    \
	  ft_strcmp.c		    \
	  ft_strcmp_lex.c       \
	  ft_strncmp.c		    \
	  ft_atoi.c			    \
	  ft_isalpha.c		    \
	  ft_isdigit.c		    \
	  ft_isalnum.c		    \
	  ft_isascii.c		    \
	  ft_isprint.c		    \
	  ft_toupper.c		    \
	  ft_tolower.c		    \
						    \
	  ft_memalloc.c		    \
	  ft_memdel.c		    \
	  ft_strnew.c		    \
	  ft_strdel.c		    \
	  ft_strclr.c		    \
	  ft_striter.c		    \
	  ft_striteri.c		    \
	  ft_strmap.c		    \
	  ft_strmap.c		    \
	  ft_strmapi.c		    \
	  ft_strequ.c		    \
	  ft_strnequ.c		    \
	  ft_strsub.c		    \
	  ft_strjoin.c		    \
	  ft_strtrim.c		    \
	  ft_strsplit.c		    \
	  ft_itoa.c			    \
	  ft_putchar.c		    \
	  ft_putstr.c		    \
	  ft_putendl.c		    \
	  ft_putnbr.c		    \
	  ft_putchar_fd.c	    \
	  ft_putstr_fd.c	    \
	  ft_putendl_fd.c	    \
	  ft_putnbr_fd.c	    \
						    \
	  ft_lstnew.c		    \
	  ft_lstdelone.c	    \
	  ft_lstdel.c		    \
	  ft_lstadd.c		    \
	  ft_lstiter.c		    \
	  ft_lstmap.c		    \
	  ft_lststrsplit.c	    \
	  ft_lstfind.c		    \
	  ft_lst_at.c		    \
	  ft_lstadd_back.c	    \
	  ft_lst_len.c          \
	  ft_lst_merge_sort.c   \
	  ft_lst_rev.c			\
						    \
	  ft_realloc.c		    \
	  ft_read_file.c        \
	  get_next_line.c       \
	  ft_num_len.c			\
	  ft_str_tab_len.c		\
	  ft_str_tab_free.c

OBJ = $(SRC:.c=.o)
INC = -I ./includes/
CC = gcc
FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ./includes/libft.h
	$(CC) $(FLAGS) $(INC) -c $< -o $@  

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: clean all
