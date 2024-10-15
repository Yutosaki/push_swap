NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

SRCS = src/main/main.c \
	   src/instractions/push.c\
	   src/instractions/reverse.c\
	   src/instractions/rotate.c\
	   src/instractions/swap.c\
	   src/utils/sort.c\
	   src/utils/stack.c\
	   src/utils/validate.c\
	   src/error/errorcase.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re