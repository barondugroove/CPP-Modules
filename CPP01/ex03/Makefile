# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchabot <bchabot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 16:20:40 by rlaforge          #+#    #+#              #
#    Updated: 2023/05/05 15:17:30 by bchabot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = violence

SRCS =	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re clean fclean
