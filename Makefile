# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sariee <sariee@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 11:27:27 by sariee            #+#    #+#              #
#    Updated: 2026/01/02 16:50:10 by sariee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# Events
SRC_EVENTS		=	Events/events.c

# Initialization
SRC_INIT		=	Init/init_game.c

# Main
SRC_MAIN		=	Main/main.c

# Parsing
SRC_PARSING		=	Parsing/parsing_map.c Parsing/validate_map.c

# Pathfinding
SRC_PATHFINDING	=	Pathfinding/pathfinding.c

# Rendering
SRC_RENDER		=	Render/render.c

# Utils
SRC_UTILS		=	Utils/utils.c Utils/utils-maps.c

# All sources
SRC				=	$(SRC_EVENTS) $(SRC_INIT) $(SRC_MAIN) $(SRC_PARSING) \
					$(SRC_PATHFINDING) $(SRC_RENDER) $(SRC_UTILS)

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME			= so_long
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
MKDIR			= mkdir -p

# Directories
LIBSRIEE_DIR	= Libsriee
MLX_DIR			= minilibx-linux
SRC_DIR			= Src
OBJ_DIR			= Objs
INCL_DIR		= Include

# Libraries
LIBSRIEE		= $(LIBSRIEE_DIR)/libsriee.a
MLX				= $(MLX_DIR)/libmlx.a

# MLX Flags
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Includes
Includes		= -I$(LIBSRIEE_DIR)/Include -I$(INCL_DIR) -I$(MLX_DIR)

# Objects
OBJS			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Colors
BOLD_CYAN		= \033[1;36m
CYAN			= \033[0;36m
YELLOW			= \033[0;33m
RED				= \033[0;31m
RESET			= \033[0m

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBSRIEE) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBSRIEE) $(MLX_FLAGS) -o $(NAME)
	@echo "  $(BOLD_CYAN)✓$(RESET) $(BOLD_CYAN)So_long is ready to use.$(RESET)"

$(LIBSRIEE):
	@echo "$(CYAN)• Building libsriee...$(RESET)"
	@make -C $(LIBSRIEE_DIR)

$(MLX):
	@echo "$(CYAN)Compilation de la minilibx...$(RESET)"
	@make -C $(MLX_DIR)

# Compile sources from subdirectories
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(Includes) -c $< -o $@

clean:
	@make clean -C $(LIBSRIEE_DIR)
	@make clean -C $(MLX_DIR)
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)• Cleaned object files.$(RESET)"

fclean: clean
	@make fclean -C $(LIBSRIEE_DIR)
	@$(RM) $(NAME)
	@echo "$(RED)• Full cleanup complete.$(RESET)"

re: fclean all

.PHONY: all clean fclean re