# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 16:20:40 by rlaforge          #+#    #+#              #
#    Updated: 2023/04/21 16:29:10 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone

SRCS =	megaphone.cpp

CC = @c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)
	@echo "\e[1A\e[2K\e[1A\e[2K"

%.o : %.c
	@echo "\e[1A\e[2K\e[1mCompiling $<\033[0m"
	$(CC) $(CFLAGS) -cpp $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "\e[1A\e[2K\e[1A\e[2K\e[1A\e[2K\e[1A\e[2K\e[1;32m📦 $(NAME) compiled!\033[0m"

clean :
	@rm -f $(OBJS)
	@echo "\033[91m🧹 Binary files cleaned!\033[0m"

fclean : clean
	@rm -rf $(NAME)
	@echo "\e[1A\e[2K\e[91m🧹 Binary files and executable cleaned!\033[0m"

re : fclean all

.PHONY : all re clean fclean
