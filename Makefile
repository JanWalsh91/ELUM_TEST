# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 09:49:09 by jwalsh            #+#    #+#              #
#    Updated: 2017/08/12 14:31:30 by jwalsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lceb

SRC_PATH = src/
INC_PATH = inc/

SRC = 		main \
			is_input_valid \
			init_data \
			is_rpn_valid \
			calc_rpn \
			increment_expression \
			error_exit \
			convert_from_rpn \
			init_linked_list \
			build_binary_tree \
			parse_binary_tree 

HELPER = 	do_op \
			ft_itoa \
			ft_strjoin \
			ft_strjoinfree \
			debug

OBJ_DIR = obj

EXT = .c

SRC_SRC = $(addsuffix $(EXT), $(SRC))
SRC_HELPER = $(addsuffix $(EXT), $(HELPER))

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC_SRC:.c=.o))
OBJ_HELPER = $(addprefix $(OBJ_DIR)/, $(SRC_HELPER:.c=.o))

CC	= gcc
FLG = -Werror -Wextra -Wall

C_GREEN = \033[32m
C_NONE = \033[0m

ECHO = echo

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_MISC) $(OBJ_HELPER)
	@$(CC) $(FLG) $(OBJ_SRC) $(OBJ_HELPER) -o $(NAME)
	@$(ECHO) "$(C_GREEN)lceb compilation done.$(C_NONE)"

$(OBJ_DIR)/%.o : ./src/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -I./inc -c -o $@ $<

$(OBJ_DIR)/%.o : ./src/helper_functions/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -I./inc -c -o $@ $<

clean:
	@/bin/rm -Rf $(OBJ_DIR)
	@$(ECHO) "$(C_GREEN)lceb clean done.$(C_NONE)"

fclean: clean
	@/bin/rm -f $(NAME)
	@$(ECHO) "$(C_GREEN)lceb fclean done.$(C_NONE)"

re: fclean all

PHONY : re all clean fclean
	@$(ECHO) "$(C_GREEN)lceb .PHONY done.$(C_NONE)"

.PHONY: all clean fclean re
