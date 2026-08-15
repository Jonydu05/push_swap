MAKEFLAGS := -silent

LIBFT   := libft
LIB     := $(LIBFT)/libft.a
LDFLAGS := -L$(LIBFT) -lft

NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Werror -Wextra -g

INCLUDE := -Iinclude -I$(LIBFT)
SRC     := src
UTILS   := $(SRC)/utils
OPS     := $(SRC)/operations

SRCS    := $(SRC)/main.c \
           $(SRC)/list_node.c \
           $(UTILS)/list_utils.c \
           $(OPS)/swap_stack.c \
           $(OPS)/push_stack.c \
           $(OPS)/rotate_stack.c \
           $(OPS)/reverse_rotate_stack.c

OBJS    := $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIBFT)

$(NAME): $(LIB) $(OBJS)
	printf "Program ready\n"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	printf "Clean activated\n"
	$(MAKE) -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	printf "Fclean activated\n"
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
	$(MAKE) -C $(LIBFT) re

.PHONY: all, fclean, clean, re
