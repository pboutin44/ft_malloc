# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboutin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 20:52:55 by pboutin           #+#    #+#              #
#    Updated: 2017/10/18 20:37:25 by pboutin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 ifeq ($(HOSTTYPE),)
   HOSTTYPE := $(shell uname -m)_$(shell uname -s)
 endif

NAME        =   libft_malloc_$(HOSTTYPE).so

SOURCES     =   src/ft_free2.c \
				src/displayable_ft.c \
				src/ft_malloc.c \
				src/large.c \
				src/find.c \
				src/ft_free.c \
				src/list_ft.c \
				src/realloc.c \
				src/small.c \
				src/tiny.c \
				src/showallocmem_ft.c

OBJECTS =   $(SOURCES:.c=.o)

FLAGS =     -Wall -Wextra -Werror

CC      =   gcc

.SILENT:

$(NAME): $(OBJECTS)
	$(CC)  -shared -o $(NAME) $(OBJECTS)
	ln -s $(NAME) libft_malloc.so
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

all: $(NAME)

%.o: %.c
	#$(CC)  -shared -o $@ $^
	$(CC) -o $@ -c $^
	printf "\e[32m[✔]\e[36m $@ "
	printf "\033[0m\n"

clean:
	rm -Rf $(OBJECTS)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	rm -Rf $(NAME) libft_malloc.so
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

PHONY: re fclean clean all
