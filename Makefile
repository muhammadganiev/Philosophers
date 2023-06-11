# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:13:32 by muganiev          #+#    #+#              #
#    Updated: 2023/06/11 19:05:36 by muganiev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

INCLUDE	= include/

SRC		= src/philo.c src/utils.c src/init.c src/philo_actions.c

OBJ		= $(SRC:%.c=%.o)

HEAD	= philo.h

CC		= gcc

FLAGS	= -Wall -Wextra -Werror -g -pthread #-fsanitize=thread

#COLORS
#------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
GRN		=	\033[32m
GRN_B	=	\033[1;32m
WHT		=	\x1B[37m
PUPURE	=	\033[1;35m
MAG		=	\x1B[35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#--------------------------------------------------------------------

.PHONY:		all	clean	fclean	re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GRN)\n\t $(NAME) is complited \n $(END)"

%.o: %.c $(INCLUDE)$(HEAD)
		$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)

clean:		
	@rm -rf $(OBJ)
	@echo "$(BLUE)\n\tCleaning $(NAME) succeed \n$(END)"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(BLUE)\tDeleting $(NAME) succeed\n$(END)"

re:			fclean all
	@echo "$(BLUE)\tRemake done\n$(END)"