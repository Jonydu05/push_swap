NAME	:=	push_swap
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g

INCLUDE	:=	include
SRC		:=	src
UTILS	:=	$(SRC)/utils
OPS		:=	$(SRC)/operations

SRCS	:=	$(SRC)/main.c \
			$(SRC)/list_node.c \
			$(UTILS)/list_utils.c \
			$(OPS)/pa.c \
			$(OPS)/pb.c
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all, fclean, clean, re
