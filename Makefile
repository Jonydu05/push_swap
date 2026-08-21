MAKEFLAGS := -silent

LIBFT   := libft
LIB     := $(LIBFT)/libft.a
PRINTF_DIR := ft_dprintf
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

LDFLAGS := -L$(LIBFT) -lft -L$(PRINTF_DIR) -lftprintf

NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Werror -Wextra -g

INCLUDE := -Iinclude -I$(LIBFT) -I$(PRINTF_DIR)
SRC     := src
UTILS   := $(SRC)/utils
OPS     := $(SRC)/operations
ALGO	:= $(SRC)/algorithms
PARSER	:= $(SRC)/parser

SRCS    := $(SRC)/main.c \
           $(SRC)/list_node.c \
           $(UTILS)/list_utils.c \
           $(UTILS)/algorithm_utils.c \
		   $(UTILS)/config_utils.c \
		   $(UTILS)/bench_utils.c \
           $(OPS)/swap_stack.c \
           $(OPS)/push_stack.c \
           $(OPS)/rotate_stack.c \
           $(OPS)/reverse_rotate_stack.c \
		   $(ALGO)/selection_sort.c \
		   $(ALGO)/radix_sort.c \
		   $(ALGO)/chunk_based.c \
		   $(PARSER)/flags.c \
		   $(PARSER)/inputs.c

OBJS    := $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIBFT)
	
$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(LIB) $(PRINTF_LIB) $(OBJS)
	printf "Program ready\n"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	printf "Clean activated\n"
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	printf "Fclean activated\n"
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all
	$(MAKE) -C $(LIBFT) re
	$(MAKE) -C $(PRINTF_DIR) re

.PHONY: all fclean clean re
