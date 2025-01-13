AR = ar rcs
HEADER = so_long.h
NAME = so_long.a
dirGet = get_file_next
CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = $(dirGet)/get_next_line.c $(dirGet)/get_next_line_utils.c loading_map.c loading_map.c mov_in.c drawing_map.c \
	is_map_valid.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = ${SRC_BONUS:.c=.o}

HEADER = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus : ${OBJ_BONUS}
	${AR} ${NAME} ${OBJ_BONUS}

clean:
	rm -f $(OBJ) ${OBJ_BONUS}

fclean: clean
	rm -f $(NAME)

re: fclean all