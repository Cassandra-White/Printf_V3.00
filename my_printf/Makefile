NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I. -c

SRC =	ft_printf.c\
		utiles/ft_putchar.c\
		utiles/ft_flags.c\
		utiles/ft_nb_len.c\
		utiles/ft_strchr.c\
		utiles/check_args.c\
		utiles/write_char.c\
		utiles/write_str.c\
		utiles/ft_strlen.c\
		utiles/ft_putstr.c\
		utiles/ft_putnbr.c\
		utiles/write_nbr.c\
		utiles/write_unsigned.c\
		utiles/ft_hex_len.c\
		utiles/ft_print_hex.c\
		utiles/write_hex.c\
		utiles/ft_ptr_len.c\
		utiles/write_ptr.c\
		utiles/ft_print_ptr.c\
		# src/ft_printf_utils.c\
	
		
		# src/ft_putnbr.c\
	
		# src/ft_putnbr_abs.c\
		# src/ft_put_flag_hex.c\
		# src/ft_puthex.c\
		# src/ft_put_flag_mem.c\
		# src/ft_putmem.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(OBJB)
	ar rc $(NAME) $(OBJB)

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
