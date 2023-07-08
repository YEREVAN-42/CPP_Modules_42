# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 20:49:05 by khovakim          #+#    #+#              #
#    Updated: 2023/07/08 16:19:18 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= BSP
SRCS		= $(wildcard ./*.cpp)
HEADRS	= $(wildcard ./*.hpp)
OBJS		= $(patsubst ./%.cpp, ./%.o, $(SRCS))

CXX				= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

RM	= rm -rf

./%.o : ./%.cpp $(HEADRS) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re all clean fclean
