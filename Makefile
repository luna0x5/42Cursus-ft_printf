# -*- MakeFile -*-

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
ARCH = ar -rc
SOURCES = ft_printf.c \
		ft_putchar.c \
		ft_puthexa.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \
		ft_putuns.c 

OBJECTS = $(SOURCES:.c=.o)

all:$(NAME)

$(NAME) : $(OBJECTS)
	$(ARCH) $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c -o $@ $<

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.phony : clean