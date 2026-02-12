# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinheir <rpinheir@student.42lausanne.ch>    +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/04 15:51:54 by rpinheir          #+#    #+#              #
#    Updated: 2026/02/12 10:00:00 by rpinheir         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR		= src
OBJ_DIR		= obj
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

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@printf "$(YELLOW)Objects cleaned$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@printf "$(YELLOW)Executables removed$(RESET)\n"

re: fclean all

norm:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -E "Error" || \
		printf "$(GREEN)Norminette OK$(RESET)\n"

run: all
	./$(NAME) maps/map.ber

.PHONY: all clean fclean re norm run
