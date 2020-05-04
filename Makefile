NAME = lem-in

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = fun_hash.c fun_stack1.c fun_vertex.c read_map.c queue1.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = lem_in.h

LIBFT_PATH = my_libft
LIBFT = $(LIBFT_PATH)/libft.a

RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE_B = "\033[1m"
WHITE = "\033[0m"

.PHONY: all clean fclean re FAKE

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) lem-in3.c
		@$(CC) -o $(NAME) lem-in3.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) lem-in $(WHITE)created.

$(OBJECTS): %.o: %.c $(HEADER)
		@$(CC) -o $@ -c $< -I$(HEADER) 
		@echo lem-in files: $(GREEN) $< $(WHITE)

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_PATH)

clean:
		@/bin/rm -f *.o
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo $(WHITE_B) lem-in files deleted!$(WHITE)

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
