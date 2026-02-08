# **************************************************************************** #
#                                                                              #
#    so_long                                                                   #
#                                                                              #
#    By: rpinheir <rpinheir@student.42lausanne.ch>                             #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR		= src
SRC_BONUS	= src_bonus
OBJ_DIR		= obj
OBJ_BONUS	= obj_bonus
INC_DIR		= include
LIBFT_DIR	= libft

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/init.c \
			  $(SRC_DIR)/map_parse.c \
			  $(SRC_DIR)/map_validate.c \
			  $(SRC_DIR)/map_pathfind.c \
			  $(SRC_DIR)/sprites.c \
			  $(SRC_DIR)/render.c \
			  $(SRC_DIR)/player.c \
			  $(SRC_DIR)/game.c \
			  $(SRC_DIR)/cleanup.c \
			  $(SRC_DIR)/error.c \
			  $(SRC_DIR)/utils.c

SRCS_BONUS	= $(SRC_BONUS)/main_bonus.c \
			  $(SRC_BONUS)/init_bonus.c \
			  $(SRC_BONUS)/map_parse_bonus.c \
			  $(SRC_BONUS)/map_validate_bonus.c \
			  $(SRC_BONUS)/map_pathfind_bonus.c \
			  $(SRC_BONUS)/sprites_bonus.c \
			  $(SRC_BONUS)/render_bonus.c \
			  $(SRC_BONUS)/player_bonus.c \
			  $(SRC_BONUS)/game_bonus.c \
			  $(SRC_BONUS)/cleanup_bonus.c \
			  $(SRC_BONUS)/error_bonus.c \
			  $(SRC_BONUS)/utils_bonus.c \
			  $(SRC_BONUS)/enemy_bonus.c \
			  $(SRC_BONUS)/animation_bonus.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:$(SRC_BONUS)/%.c=$(OBJ_BONUS)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
CYAN		= \033[0;36m
RESET		= \033[0m

all: $(MLX) $(LIBFT) $(NAME)
	@printf "$(GREEN)so_long ready!$(RESET)\n"

$(NAME): $(OBJS)
	@printf "$(CYAN)Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(MLX):
	@printf "$(YELLOW)Building MiniLibX...$(RESET)\n"
	@$(MAKE) -C $(MLX_DIR) --silent 2>/dev/null

$(LIBFT):
	@printf "$(YELLOW)Building libft...$(RESET)\n"
	@$(MAKE) -C $(LIBFT_DIR) --silent

bonus: $(MLX) $(LIBFT) $(NAME_BONUS)
	@printf "$(GREEN)so_long_bonus ready!$(RESET)\n"

$(NAME_BONUS): $(OBJS_BONUS)
	@printf "$(CYAN)Linking $(NAME_BONUS)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJ_BONUS)/%.o: $(SRC_BONUS)/%.c
	@mkdir -p $(OBJ_BONUS)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@printf "$(YELLOW)Objects cleaned$(RESET)\n"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@printf "$(YELLOW)Executables removed$(RESET)\n"

re: fclean all

norm:
	@norminette $(SRC_DIR) $(SRC_BONUS) $(INC_DIR) | grep -E "Error" || \
		printf "$(GREEN)Norminette OK$(RESET)\n"

run: all
	./$(NAME) maps/map.ber

.PHONY: all clean fclean re bonus norm run
