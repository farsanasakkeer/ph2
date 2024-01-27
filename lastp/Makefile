# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 17:25:39 by fvaliyak          #+#    #+#              #
#    Updated: 2024/01/26 17:30:32 by fvaliyak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Philo

INC		= philo.h

SRC		= 	phil.c \
			init.c \
			free.c \
			process.c \
			actions.c \
			failure.c \
			utils.c \

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread -g

OBJS	= $(SRC:.c=.o)

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS) $(INC)



clean:
	@echo "\n$(YE)Cleaning all object files...$(RC)\n"
	@rm -rf $(OBJS)
	@echo "$(RE)objects removed!$(RC)\n"

fclean: clean
	@echo "\n$(YE)Cleaning executable files...$(RC)\n"
	@rm -rf $(NAME)
	@echo "$(RE)executable removed!$(RC)\n"

re: fclean all

.silent: all

.PHONY: all clean fclean re