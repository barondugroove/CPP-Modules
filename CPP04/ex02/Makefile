# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 11:40:02 by bchabot           #+#    #+#              #
#    Updated: 2023/05/25 17:39:24 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

SRCS =	main.cpp \
		AAnimal.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brains.cpp

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

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
