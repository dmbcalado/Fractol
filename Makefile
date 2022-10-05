# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendonc <dmendonc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 20:41:42 by dmendonc          #+#    #+#              #
#    Updated: 2022/10/05 20:07:55 by dmendonc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = srcs
OBJECTS_NAME = $(SRC_NAME:.c=.o)
CC = gcc
CFLAGS = -I /usr/local/include
RM = rm -f
SOURCES = $(wildcard srcs/*/*.c) $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
LDLIBS = -g -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm #-fsanitize=address
BLUE = \033[34m
YELL = \033[33m
WHITE = \033[0m
GREEN = \033[32m
all: $(NAME)
	
%.o: %.c
	@$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@


echo:
	@echo -e "$(BLUE)\nLadies and Gentlemen, welcome to my:"
	@echo ""
	@echo -e "$(YELL):::::::::: :::::::::      :::      :::::::: :::::::::::           ::::::::  :::"
	@echo -e ":+:        :+:    :+:   :+: :+:   :+:    :+:    :+:              :+:    :+: :+:       "
	@echo -e "+:+        +:+    +:+  +:+   +:+  +:+           +:+              +:+    +:+ +:+       "
	@echo -e ":#::+::#   +#++:++#:  +#++:++#++: +#+           +#+    :++#++:   +#+    +:+ +#+       "
	@echo -e "+#+        +#+    +#+ +#+     +#+ +#+           +#+              +#+    +#+ +#+       "
	@echo -e "#+#        #+#    #+# #+#     #+# #+#    #+#    #+#              #+#    #+# #+#       "
	@echo -e "###        ###    ### ###     ###  ########     ###               ########  ##########\n\n"
	@echo -e "$(WHITE)"

$(NAME): echo $(OBJECTS)
	-@$(CC) $(OBJECTS) $(LDLIBS) -o $(NAME)
	-@mkdir -p objects
	-@mv $(OBJECTS) objects
	@echo -e "$(GREEN)To see manual type : ./fractol manual$(WHITE)\n"
clean:
	@$(RM) $(OBJECTS)
	@echo -e "$(GREEN)OBJECTS DELETED$(WHITE)"

fclean:
	@rm -f $(NAME)
	@echo -e "\n$(GREEN)FRACTOL ERASED$(WHITE)"

re: fclean all

.PHONY: all clean fclean re

