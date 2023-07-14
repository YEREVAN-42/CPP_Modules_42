# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 14:47:19 by khovakim          #+#    #+#              #
#    Updated: 2023/07/14 13:48:10 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= DiamondTrap
SRCS	= $(wildcard ./*.cpp)
HEADRS	= $(wildcard ./*.hpp)
OBJS	= $(patsubst ./%.cpp, ./%.o, $(SRCS))

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

RM	= rm -rf

./%.o : ./%.cpp Makefile $(HEADRS)
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
