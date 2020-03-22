NAME	= matchstick

CC	= gcc

RM	= rm -f

SRCS	= ./game.c \
	  ./my_getnbr.c \
	  ./my_putstr.c \
	  ./my_putchar.c \
	  ./my_atoi.c \
	  ./my_putnbr.c \
	  ./get_next_line.c \
	  ./fonction.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 $(RM) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
