RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRC = push_swap.c \
		pushes.c \
		reverse_rotates.c \
		rotates.c \
		swaps.c \
		utils.c \
		less_movements.c \
		errors.c \

OBJ = $(SRC:%.c=%.o)

DIR_PRINTF = ft_printf
PRINTF = $(DIR_PRINTF)/libftprintf.a

INCLUDE = push_swap.h
NAME = push_swap
all: $(NAME)

printf: $(PRINTF)

$(PRINTF):
	make -C $(DIR_PRINTF)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) $(PRINTF) $(OBJ) -o $(NAME)

%.o: %.c $(PRINTF)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(DIR_PRINTF)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(DIR_PRINTF)

re: fclean all

.PHONY: all printf clean fclean re
