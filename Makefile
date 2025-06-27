NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror


SRC = ft_printf.c \
      handle_char.c \
      handle_str.c \
      handle_ptr.c \
      handle_number.c \
      handle_unsigned.c \
      handle_hexadecimal.c \
      handle_percent.c \
      print_unsigned_number.c \
	print_hexadecimal.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re