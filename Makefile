NAME	:=	push_swap
CC		:=	cc
CFLAGS	:=	-Wall -Werror -Wextra -g

INCLUDE	:=	include
SRC		:=	src
SRCS	:=	$(SRC)/main.c \
			$(SRC)/teste/teste.c # Apenas para teste de include

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all, fclean, clean, re
