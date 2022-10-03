# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 20:41:42 by dmendonc          #+#    #+#              #
#    Updated: 2022/05/16 04:52:34 by dmendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = srcs
OBJECTS_NAME = $(SRC_NAME:.c=.o)
CC = clang
CFLAGS = -I /usr/local/include
RM = rm -f
CYAN = \033[1;36m
YELL = \033[1;33m
SOURCES =	main.c 				  \
		initializing/restarting.c \
		initializing/starting.c	  \
		hooks/zoom.c 			  \
		hooks/keys_cmd.c		  \
		hooks/keys.c  			  \
		hooks/mouse.c			  \
		hooks/resolution.c 		  \
		auxiliar/aux_functions.c  \
		auxiliar/safeties.c 	  \
		image/colouring.c		  \
		image/image_functions.c   \
		fractals/coordinates.c	  \
		fractals/mandelbrot.c 	  \
		fractals/julia.c


OBJECTS = $(SOURCES:.c=.o)
LDLIBS = -O2 -lm -lmlx -framework OpenGL -framework AppKit
all: $(NAME)
	
%.o: %.c
	-@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	@echo "\033[1;33m.\033[m"

echo:
	@echo "$(CYAN)   \n\nLadies and Gentlemen...\n\n\nWelcome to my\n\033[m"
	@echo "$(CYAN) _____   ____     ___     ____   _____   ___   _\033[m"
	@echo "$(CYAN)|  ___| |    \\   /   \   |  __| |_   _| |   | | |\033[m"
	@echo "$(CYAN)| T___  |  R  | |  A  |  | T      T T   |   | | |\033[m"
	@echo "$(CYAN)|  ___| |    /  |  _  |  | |      | |   | O | | |\033[m"
	@echo "$(CYAN)| T     |  A \\  | | | |  | |__    | |   |   | | |__\033[m"
	@echo "$(CYAN)|_|     |_| \\_\\ |_| |_|  |____|   |_|   |___| |____|\033[m"
	@echo "\n\n"
	@echo "$(YELL)COMPILING...\033[m"

$(NAME): echo $(OBJECTS)
	-@$(CC) $(OBJECTS) $(LDLIBS) -o $(NAME)
	-@mkdir -p objects
	-@mv $(OBJECTS) objects 
	@echo "\033[1;32m\nCOMPILATION SUCESSFULL! :D\033[m"
	@echo "\033[1;32m\n\nTo see manual type : ./fractol manual \nENJOY!\033[m"
clean:
	@$(RM) $(OBJECTS)
	@echo "\033[1;41mOBJECTS DELETED\033[m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;41mFRACTOL ERASED\033[m"

re: fclean all

.PHONY: all clean fclean re

