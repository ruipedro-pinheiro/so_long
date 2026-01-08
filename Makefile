# **************************************************************************** #
#                                                                              #
#    so_long                                                                   #
#                                                                              #
#    By: rpinheir <rpinheir@student.42lausanne.ch>                             #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus

# ═══════════════════════════════════════════════════════════════════════════════
#  COMPILER & FLAGS
# ═══════════════════════════════════════════════════════════════════════════════

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_DIR		= minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# ═══════════════════════════════════════════════════════════════════════════════
#  DIRECTORIES
# ═══════════════════════════════════════════════════════════════════════════════

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes
LIBFT_DIR	= libft

# ═══════════════════════════════════════════════════════════════════════════════
#  SOURCE FILES (update as you code!)
# ═══════════════════════════════════════════════════════════════════════════════

# Add your source files here
SRCS		= $(SRC_DIR)/main.c \

SRCS_BONUS	= $(SRC_DIR)/main_bonus.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ═══════════════════════════════════════════════════════════════════════════════
#  LIBRARIES
# ═══════════════════════════════════════════════════════════════════════════════

LIBFT		= $(LIBFT_DIR)/libft.a

# ═══════════════════════════════════════════════════════════════════════════════
#  COLORS - Stardew Valley Palette
# ═══════════════════════════════════════════════════════════════════════════════

# Reset
R			= \033[0m

# Regular
BLACK		= \033[0;30m
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m

# Bold
BBLACK		= \033[1;30m
BRED		= \033[1;31m
BGREEN		= \033[1;32m
BYELLOW		= \033[1;33m
BBLUE		= \033[1;34m
BPURPLE		= \033[1;35m
BCYAN		= \033[1;36m
BWHITE		= \033[1;37m

# Background
BG_GREEN	= \033[42m
BG_YELLOW	= \033[43m
BG_BLUE		= \033[44m
BG_PURPLE	= \033[45m
BG_CYAN		= \033[46m

# Styles
BOLD		= \033[1m
DIM			= \033[2m
ITALIC		= \033[3m
UNDERLINE	= \033[4m

# ═══════════════════════════════════════════════════════════════════════════════
#  PROGRESS BAR
# ═══════════════════════════════════════════════════════════════════════════════

TOTAL_FILES	= $(words $(SRCS))
CURR		= 0

define progress
	$(eval CURR=$(shell echo $$(($(CURR)+1))))
	$(eval PCT=$(shell echo $$(($(CURR)*100/$(TOTAL_FILES)))))
	$(eval DONE=$(shell echo $$(($(PCT)/5))))
	$(eval LEFT=$(shell echo $$((20-$(DONE)))))
	@printf "\r$(BCYAN)  ["
	@printf "$(BGREEN)"
	@for i in $$(seq 1 $(DONE) 2>/dev/null); do printf "█"; done
	@printf "$(BBLACK)"
	@for i in $$(seq 1 $(LEFT) 2>/dev/null); do printf "░"; done
	@printf "$(BCYAN)] $(BWHITE)%3d%%  $(DIM)$(WHITE)%s$(R)                    " $(PCT) $(notdir $<)
endef

# ═══════════════════════════════════════════════════════════════════════════════
#  DECORATIONS
# ═══════════════════════════════════════════════════════════════════════════════

define header
	@printf "\n"
	@printf "$(BYELLOW)  ╔═══════════════════════════════════════════════════════════╗\n"
	@printf "$(BYELLOW)  ║$(R)                                                           $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BGREEN)     ███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BGREEN)     ██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║ $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BGREEN)     ███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║ $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BGREEN)     ╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║ $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BGREEN)     ███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║ $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BGREEN)     ╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(R)                                                           $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(CYAN)              ★  42 Lausanne - rpinheir  ★               $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(PURPLE)                 Stardew Valley Edition                   $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ╚═══════════════════════════════════════════════════════════╝$(R)\n"
	@printf "\n"
endef

define success
	@printf "\n\n"
	@printf "$(BGREEN)  ╔═══════════════════════════════════════════╗\n"
	@printf "$(BGREEN)  ║                                           ║\n"
	@printf "$(BGREEN)  ║   $(BWHITE)✨  Build successful!  ✨$(BGREEN)              ║\n"
	@printf "$(BGREEN)  ║                                           ║\n"
	@printf "$(BGREEN)  ║   $(WHITE)Run: $(BCYAN)./so_long maps/level.ber$(BGREEN)        ║\n"
	@printf "$(BGREEN)  ║                                           ║\n"
	@printf "$(BGREEN)  ╚═══════════════════════════════════════════╝$(R)\n"
	@printf "\n"
endef

define success_bonus
	@printf "\n\n"
	@printf "$(BPURPLE)  ╔═══════════════════════════════════════════╗\n"
	@printf "$(BPURPLE)  ║                                           ║\n"
	@printf "$(BPURPLE)  ║   $(BWHITE)🎮  BONUS Build successful!  🎮$(BPURPLE)        ║\n"
	@printf "$(BPURPLE)  ║                                           ║\n"
	@printf "$(BPURPLE)  ║   $(WHITE)• Enemy patrols$(BPURPLE)                        ║\n"
	@printf "$(BPURPLE)  ║   $(WHITE)• Sprite animations$(BPURPLE)                    ║\n"
	@printf "$(BPURPLE)  ║   $(WHITE)• On-screen counter$(BPURPLE)                    ║\n"
	@printf "$(BPURPLE)  ║                                           ║\n"
	@printf "$(BPURPLE)  ╚═══════════════════════════════════════════╝$(R)\n"
	@printf "\n"
endef

# ═══════════════════════════════════════════════════════════════════════════════
#  RULES
# ═══════════════════════════════════════════════════════════════════════════════

all: header $(MLX) $(LIBFT) $(NAME)
	$(call success)

$(NAME): $(OBJS)
	@printf "\n$(BCYAN)  ► $(WHITE)Linking $(BYELLOW)$(NAME)$(WHITE)...$(R)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(call progress)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(MLX):
	@printf "$(BCYAN)  ► $(WHITE)Building $(BYELLOW)MiniLibX$(WHITE)...$(R)\n"
	@$(MAKE) -C $(MLX_DIR) --silent 2>/dev/null
	@printf "$(BGREEN)  ✓ $(WHITE)MiniLibX ready$(R)\n\n"

$(LIBFT):
	@printf "$(BCYAN)  ► $(WHITE)Building $(BYELLOW)libft$(WHITE)...$(R)\n"
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@printf "$(BGREEN)  ✓ $(WHITE)libft ready$(R)\n\n"

# ═══════════════════════════════════════════════════════════════════════════════
#  BONUS
# ═══════════════════════════════════════════════════════════════════════════════

bonus: header $(MLX) $(LIBFT) $(NAME_BONUS)
	$(call success_bonus)

$(NAME_BONUS): $(OBJS_BONUS)
	@printf "\n$(BPURPLE)  ► $(WHITE)Linking $(BYELLOW)$(NAME_BONUS)$(WHITE)...$(R)\n"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

# ═══════════════════════════════════════════════════════════════════════════════
#  CLEANING
# ═══════════════════════════════════════════════════════════════════════════════

clean:
	@printf "$(BYELLOW)  ► $(WHITE)Cleaning objects...$(R)\n"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --silent
	@printf "$(BGREEN)  ✓ $(WHITE)Objects removed$(R)\n"

fclean: clean
	@printf "$(BYELLOW)  ► $(WHITE)Removing executables...$(R)\n"
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean --silent
	@printf "$(BGREEN)  ✓ $(WHITE)Full clean complete$(R)\n"

re: fclean all

# ═══════════════════════════════════════════════════════════════════════════════
#  UTILITIES
# ═══════════════════════════════════════════════════════════════════════════════

norm:
	@printf "\n$(BCYAN)  ► $(WHITE)Running $(BYELLOW)norminette$(WHITE)...$(R)\n\n"
	@norminette $(SRC_DIR) $(INC_DIR) | grep -E "(Error|Warning)" && \
		printf "\n$(BRED)  ✗ $(WHITE)Norm errors found$(R)\n" || \
		printf "$(BGREEN)  ✓ $(WHITE)Norminette OK$(R)\n"

run: all
	@printf "$(BCYAN)  ► $(WHITE)Launching $(BYELLOW)so_long$(WHITE)...$(R)\n\n"
	@./$(NAME) maps/level.ber

leaks: all
	@printf "$(BCYAN)  ► $(WHITE)Checking leaks with $(BYELLOW)valgrind$(WHITE)...$(R)\n\n"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) maps/level.ber

help:
	@printf "\n"
	@printf "$(BYELLOW)  ╔═══════════════════════════════════════════╗\n"
	@printf "$(BYELLOW)  ║$(BWHITE)            AVAILABLE COMMANDS            $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ╠═══════════════════════════════════════════╣\n"
	@printf "$(BYELLOW)  ║$(R)                                           $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BCYAN)   make        $(WHITE)- Build the project        $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BCYAN)   make bonus  $(WHITE)- Build with bonuses       $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BCYAN)   make clean  $(WHITE)- Remove objects           $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BCYAN)   make fclean $(WHITE)- Full clean               $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BCYAN)   make re     $(WHITE)- Rebuild all              $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(R)                                           $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BPURPLE)   make norm   $(WHITE)- Run norminette          $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BPURPLE)   make run    $(WHITE)- Build & run             $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BPURPLE)   make leaks  $(WHITE)- Check memory leaks      $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(BPURPLE)   make help   $(WHITE)- Show this help          $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ║$(R)                                           $(BYELLOW)║\n"
	@printf "$(BYELLOW)  ╚═══════════════════════════════════════════╝$(R)\n"
	@printf "\n"

.PHONY: all clean fclean re bonus norm run leaks help header

# ═══════════════════════════════════════════════════════════════════════════════
#  "And thanks for all the fish!"
# ═══════════════════════════════════════════════════════════════════════════════
