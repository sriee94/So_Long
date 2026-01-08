# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sariee <sariee@student.42belgium.be>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/31 16:45:09 by sariee            #+#    #+#              #
#    Updated: 2026/01/05 17:33:52 by sariee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# String manipulation
SRC_STRING	=	String/ft_strlen.c String/ft_strdup.c String/ft_strjoin.c \
				String/ft_substr.c String/ft_strchr.c String/ft_strrchr.c \
				String/ft_strlcpy.c String/ft_strlcat.c String/ft_strncmp.c \
				String/ft_strnstr.c String/ft_strtrim.c String/ft_split.c \
				String/ft_strmapi.c String/ft_striteri.c String/ft_strcmp.c 

# Memory manipulation
SRC_MEMORY	=	Memory/ft_memset.c Memory/ft_bzero.c Memory/ft_memcpy.c \
				Memory/ft_memmove.c Memory/ft_memchr.c Memory/ft_memcmp.c \
				Memory/ft_calloc.c Memory/ft_free_split.c

# Conversions
SRC_CONVERT	=	Convert/ft_atoi.c Convert/ft_itoa.c Convert/ft_toupper.c \
				Convert/ft_tolower.c

# Character checks
SRC_CHECK	=	Check/ft_isalpha.c Check/ft_isdigit.c Check/ft_isalnum.c \
				Check/ft_isascii.c Check/ft_isprint.c

# Output functions
SRC_OUTPUT	=	Output/ft_putchar_fd.c Output/ft_putstr_fd.c \
				Output/ft_putendl_fd.c Output/ft_putnbr_fd.c

# Linked lists
SRC_LIST	=	List/ft_lstnew.c List/ft_lstadd_front.c List/ft_lstadd_back.c \
				List/ft_lstsize.c List/ft_lstlast.c List/ft_lstdelone.c \
				List/ft_lstclear.c List/ft_lstiter.c List/ft_lstmap.c

# Get Next Line
SRC_GNL		=	Gnl/get_next_line.c

# ft_printf
SRC_PRINTF	=	Printf/ft_printf.c Printf/ft_printf_utils.c \
				Printf/ft_printf_numbers.c Printf/ft_printf_hex.c \
				Printf/ft_printf_pointer.c

# All sources
SRC			=	$(SRC_STRING) $(SRC_MEMORY) $(SRC_CONVERT) $(SRC_CHECK) \
				$(SRC_OUTPUT) $(SRC_LIST) $(SRC_GNL) $(SRC_PRINTF)

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

NAME		= libsriee.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rc
RM			= rm -f
MKDIR		= mkdir -p

# Directories
SRC_DIR		= Src
OBJ_DIR		= Objs
INCL_DIR	= Include

# Includes
Includes	= -I$(INCL_DIR)

# Objects
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

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

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "  $(BOLD_CYAN)✓$(RESET) $(BOLD_CYAN)Libsriee is ready to use$(RESET)"

# Compile sources from subdirectories
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(Includes) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)• Cleaned object files$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)• Full cleanup complete$(RESET)"

re: fclean all

.PHONY: all clean fclean re
