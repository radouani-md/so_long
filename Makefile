HEADER_BNUS = so_long_bonus.h
HEADER = so_long.h
NAME = so_long
NAME_BONUS = so_long_bonus
dirGet = get_file_next
CC = cc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L /home/mradouan/Desktop/include/mlx -lmlx_Linux -lXext -lX11 -lm
SRC = $(dirGet)/get_next_line.c $(dirGet)/get_next_line_utils.c loading_map.c mov_in.c drawing_map.c \
	is_map_valid.c check_require.c check_player_width.c position_player.c free_all.c flood_fill.c print_number.c \
	load_allocate.c animation_dire.c so_long.c

SRC_BONUS = $(dirGet)/get_next_line_bonus.c $(dirGet)/get_next_line_utils_bonus.c loading_map_bonus.c mov_in_bonus.c drawing_map_bonus.c \
	is_map_valid_bonus.c check_require_bonus.c check_player_width_bonus.c position_player_bonus.c free_all_bonus.c flood_fill_bonus.c print_number_bonus.c \
	load_allocate_bonus.c md_itoa_bonus.c animation_dire_bonus.c so_long_bonus.c img_enemy_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

bonus : ${NAME_BONUS}

${NAME_BONUS} : ${OBJ_BONUS}
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) ${OBJ_BONUS}

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all