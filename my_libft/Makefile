NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f
LDFLAGS = -L.
LDLIBS = -lft
HDDIRS = -I.
SRC = ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memmove.c \
	   ./ft_memchr.c ./ft_memcmp.c ./ft_strlen.c ./ft_strdup.c ./ft_strcpy.c \
	   ./ft_strncpy.c ./ft_strcat.c ./ft_strncat.c ./ft_strlcat.c ./ft_strchr.c \
	   ./ft_strrchr.c ./ft_strstr.c ./ft_strnstr.c ./ft_strcmp.c ./ft_strncmp.c \
	   ./ft_atoi.c ./ft_atol.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c \
	   ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c \
	   ./ft_memalloc.c ./ft_memdel.c ./ft_strnew.c ./ft_strdel.c ./ft_strclr.c \
	   ./ft_striter.c ./ft_striteri.c ./ft_strmap.c ft_strmapi.c \
	   ./ft_strequ.c ./ft_strnequ.c  ./ft_strsub.c ./ft_strjoin.c ./ft_strtrim.c \
	   ./ft_strsplit.c	./ft_itoa.c ./ft_putchar.c  ./ft_putstr.c ./ft_putendl.c \
	   ./ft_putnbr.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c \
	   ./ft_first_decimal.c ./ft_strndup.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c \
	   ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_trim.c ./ft_lstnew_gnl.c \
	   ./get_next_line.c \
		arithm.c check_inf_nan1.c check_inf_nan2.c \
		functions1.c functions3.c functions4.c \
		print_double.c process_sp1.c process_sp2.c process_sp3.c process_sp4.c process_sp5.c \
		put_d1.c put_d2.c put_d3.c put_d4.c put_d5.c\
		put_double0.c put_double1.c put_double2.c put_ee1.c put_ee2.c put_ee3.c \
		put_f1.c put_f2.c put_f3.c put_long_dbl1.c put_long_dbl2.c put_long_dbl3.c \
		put_long_e.c put_o_u_x1.c put_o_u_x2.c put_p.c \
		put_strings1.c put_strings2.c two.c

OBJ = $(subst .c,.o,$(SRC))

HEAD = libft.h

GREEN_B = "\033[1;32m"
GREEN = "\033[0;32m"
WHITE_B = "\033[1m"
WHITE = "\033[0m"

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)
	@echo $(WHITE_B) Libft created. $(WHITE)
		
%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c $< -o $@ -I.$(HEAD) 
	@echo Libft: $(GREEN) $< $(WHITE)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@echo $(WHITE_B) Libft deleted! $(WHITE)

re: fclean all
