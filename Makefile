NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ft_printf'in kendi kaynak dosyaları
SRCS = ft_printf.c \
		handle_char.c \
		handle_str.c \
		handle_ptr.c \
		handle_number.c \
		handle_unsigned.c \
		handle_hexadecimal.c \
		handle_percent.c \
		printed_int_count.c \
		printed_unsigned_count.c \
		print_hexadecimal.c \
		ft_putnbr_base.c \
		ft_num_len_base.c \



OBJS = $(SRCS:.c=.o)

# libft kütüphanesinin yolu
LIBFT = ./libft/libft.a

# Ana hedef: Kütüphaneyi oluşturmak
all: $(NAME)

# Kütüphane dosyası, libft kütüphanesine ve kendi nesne dosyalarımıza bağlıdır
$(NAME): $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT)

# libft kütüphanesini derlemek için kural
$(LIBFT):
	$(MAKE) -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean:
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re