NAME = lem-in

CC = gcc
#CFLAGS = -Wall -Wextra -Werror

SRC =	./src/paths1.c ./src/paths2.c ./src/paths3.c ./src/paths4.c \
		./src/find_other_paths.c \
		./src/paths_print.c ./src/fun_print1.c ./src/fun_print2.c \
		./src/fun_init1.c ./src/fun_init2.c ./src/fun_del.c \
		./src/fun_vertex.c ./src/fun_hash.c \
		./src/read_map1.c ./src/read_map2.c ./src/read_map3.c  ./src/read_map4.c \
		./src/bfs.c ./src/work_with_bfs.c ./src/fun_linked_list.c \
		./src/delete_farm1.c ./src/delete_farm2.c ./src/delete_farm3.c\
		./src/fun_edges.c
OBJECTS = $(patsubst %.c, %.o, $(SRC))
HEADER = lem_in.h

SRC_VIS =	./visual/visual1.c ./visual/visual2.c
OBJECTS_VIS = $(patsubst %.c, %.o, $(SRC_VIS))
HEADER_VIS = visual/visual.h

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

$(OBJECTS_VIS): %.o: %.c $(HEADER_VIS) $(LIBFT)
		@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADER_VIS) 
		@echo vis files: $(GREEN) $< $(WHITE)

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_PATH)

vis:	$(OBJECTS) $(OBJECTS_VIS)
		@$(CC) -o $(NAME) $(CFLAGS) visual/lem_in_vis.c visual/visual1.o visual/visual2.o $(OBJECTS) -I visual/visual.h my_libft/libft.a
		@echo lem-in with  $(GREEN) visualization:$(WHITE) created!

clean:
		@/bin/rm -f $(OBJECTS)
		@/bin/rm -f $(OBJECTS_VIS)
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo $(WHITE_B) lem-in files deleted!$(WHITE)


fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
