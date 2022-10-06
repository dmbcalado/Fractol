NAME = ftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra -Fsanitize=address
RM = rm -f
LIB1 = ar -rcs
LIB2 = ranlib

INCLUDE =	ft_printf.h

SOURCES =	ft_itoa.c			\
			ft_utoa.c			\
			func_cspd.c			\
			func_iuxX.c			\
			convert_to_hex.c	\
			convert_adress.c	\
			ft_printf.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
					$(LIB1) $(NAME) $(OBJECTS)
					$(LIB2) $(NAME) 
					mkdir -p objects
					mv $(OBJECTS) objects 
.c.o:
		$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJECTS)

fclean: clean
		$(RM) $(NAME)
		
re: fclean $(NAME)

.PHONY:		all clean fclean re