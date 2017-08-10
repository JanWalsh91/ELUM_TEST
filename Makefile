# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/10 09:49:09 by jwalsh            #+#    #+#              #
#    Updated: 2017/08/10 16:13:14 by jwalsh           ###   ########.fr        #
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
			do_op \
			increment_expression \
			error_exit \
			debug

OBJ_DIR = obj

EXT = .c

SRC_SRC = $(addsuffix $(EXT), $(SRC))

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC_SRC:.c=.o))

CC	= gcc
FLG = -Werror -Wextra -Wall

C_GREEN = \033[32m
C_NONE = \033[0m

ECHO = echo

all: $(NAME)

$(NAME): $(OBJ_SRC) $(OBJ_MISC)
	@$(CC) $(FLG) -g $(OBJ_SRC) -o $(NAME)
	@$(ECHO) "$(C_GREEN)lceb compilation done.$(C_NONE)"

$(OBJ_DIR)/%.o : ./src/%.c
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) $(FLG) -g -I./inc -c -o $@ $<

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
