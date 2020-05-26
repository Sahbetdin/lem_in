NAME = lem-in

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	./src/paths1.c ./src/paths2.c ./src/paths3.c ./src/find_other_paths.c \
		./src/paths_print.c ./src/fun_print1.c ./src/fun_print2.c \
		./src/fun_init1.c ./src/fun_init2.c ./src/fun_del.c \
		./src/fun_vertex.c ./src/fun_hash.c \
		./src/read_map1.c ./src/read_map2.c ./src/read_map3.c  ./src/read_map4.c \
		./src/bfs.c ./src/work_with_bfs.c ./src/fun_linked_list.c \
		./src/delete_farm1.c ./src/delete_farm2.c\
		./src/fun_edges.c 

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

$(NAME): $(LIBFT) $(OBJECTS) ./src/lem_in.c
		@$(CC) -o $(NAME) ./src/lem_in.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) lem-in $(WHITE)created.

$(OBJECTS): %.o: %.c $(HEADER)
		@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADER) 
		@echo lem-in files: $(GREEN) $< $(WHITE)

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_PATH)

clean:
		@/bin/rm -f $(OBJECTS)
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo $(WHITE_B) lem-in files deleted!$(WHITE)

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
