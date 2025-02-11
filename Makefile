dirGet = get_file_next
HEADER_GET = $(dirGet)/get.h

HEADER_GET_BS = file_bonus/$(dirGet)/get_bonus.h

dir_Mandatory = file_mandatory

dir_Bonus = file_bonus

HEADER_BONUS = $(dir_Bonus)/so_long_bonus.h

HEADER = $(dir_Mandatory)/so_long.h

NAME = so_long

NAME_BONUS = so_long_bonus


CC = cc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L /home/mradouan/Desktop/include/mlx -lmlx_Linux -lXext -lX11 -lm
SRC =  $(dir_Mandatory)/loading_map.c $(dir_Mandatory)/mov_in.c $(dir_Mandatory)/drawing_map.c \
	$(dir_Mandatory)/is_map_valid.c $(dir_Mandatory)/check_require.c $(dir_Mandatory)/check_player_width.c $(dir_Mandatory)/position_player.c $(dir_Mandatory)/free_all.c $(dir_Mandatory)/flood_fill.c $(dir_Mandatory)/print_number.c \
	$(dir_Mandatory)/load_allocate.c $(dir_Mandatory)/animation_dire.c $(dir_Mandatory)/so_long.c

SRC_BONUS = $(dir_Bonus)/loading_map_bonus.c $(dir_Bonus)/mov_in_bonus.c $(dir_Bonus)/drawing_map_bonus.c \
	$(dir_Bonus)/is_map_valid_bonus.c $(dir_Bonus)/check_require_bonus.c $(dir_Bonus)/check_player_width_bonus.c $(dir_Bonus)/position_player_bonus.c $(dir_Bonus)/free_all_bonus.c \
	$(dir_Bonus)/flood_fill_bonus.c $(dir_Bonus)/print_number_bonus.c $(dir_Bonus)/didacted_enemy_bonus.c $(dir_Bonus)/load_allocate_bonus.c $(dir_Bonus)/md_itoa_bonus.c \
	$(dir_Bonus)/animation_dire_bonus.c $(dir_Bonus)/so_long_bonus.c $(dir_Bonus)/img_enemy_bonus.c

SRC_GET_NEXT = $(dirGet)/get_next_line.c $(dirGet)/get_next_line_utils.c
SRC_GET_NEXT_BS = $(dir_Bonus)/$(dirGet)/get_next_line_bonus.c $(dir_Bonus)/$(dirGet)/get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = ${SRC_BONUS:.c=.o}

OBJ_GET_BONUS = ${SRC_GET_NEXT_BS:.c=.o}

OBJ_GET = ${SRC_GET_NEXT:.c=.o}


all: $(NAME)

bonus : ${NAME_BONUS}


$(NAME): $(OBJ) $(OBJ_GET)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_GET) $(MLX_FLAGS) -o $(NAME)

${NAME_BONUS} : ${OBJ_BONUS} $(OBJ_GET_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ_GET_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)

$(dirGet)/%.o: $(dirGet)/%.c $(HEADER_GET)
	$(CC) $(CFLAGS) -c $< -o $@

$(dir_Bonus)/$(dirGet)/%.o: $(dir_Bonus)/$(dirGet)/%.c $(HEADER_GET_BS)
	$(CC) $(CFLAGS) -c $< -o $@

$(dir_Bonus)/%.o: $(dir_Bonus)/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) ${OBJ_BONUS}

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(OBJ_GET_BONUS) $(OBJ_GET)

re: fclean all