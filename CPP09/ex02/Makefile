# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 11:40:02 by bchabot           #+#    #+#              #
#    Updated: 2023/08/17 18:11:39 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS =	main.cpp \
		PmergeMe.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean :
	rm -f $(OBJS)

run: $(NAME)
	./$(NAME) `shuf -i 1-100000 -n 100 | tr "\n" " "`

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean run
