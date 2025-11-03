NAME	=	libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

SRC	=	ft_printf.c			\
		ft_putchar.c		\
		ft_putstr.c			\
		ft_putnbr.c			\
		ft_putunsigned.c	\
		ft_hex.c	  		\
		ft_hex_min.c		\

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re