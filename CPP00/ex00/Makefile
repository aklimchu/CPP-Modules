# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <aklimchu@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 09:06:17 by aklimchu          #+#    #+#              #
#    Updated: 2025/01/08 09:32:40 by aklimchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Program name
NAME		= megaphone

# Compiler
C++ 		= c++
CFLAGS		= -Wall -Werror -Wextra -std=c++20
RM			= rm -f
RMDIR		= rm -rf

# Source / OBJ files / Includes
SRC 		=	megaphone.cpp
OBJ 		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR		= obj
INCLUDE		= -I "./"


# Rules
all:	$(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(C++) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME):	$(OBJ_DIR) $(OBJ)
	@$(C++) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo "$(GREEN)SUCCESS, MEGAPHONE IS READY $(DEF_COLOR)"

clean:
	@echo "$(RED)Deleting object files... $(DEF_COLOR)"
	@$(RMDIR) $(OBJ_DIR) 

fclean:		clean
	@echo "$(GREEN)Deleting megaphone... $(DEF_COLOR)"
	@$(RMDIR) $(NAME)
	@echo "$(GREEN)CLEAR $(DEF_COLOR)"

re: 		fclean all

.PHONY: 	all clean fclean re
