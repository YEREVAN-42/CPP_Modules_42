# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 18:25:11 by khovakim          #+#    #+#              #
#    Updated: 2023/07/01 19:39:59 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= HI_THIS_IS_BRAIN
SRCS		= $(wildcard *.cpp)
OBJS		= $(patsubst %.cpp, %.o, $(SRCS))
HEADRS		= $(wildcard *.hpp)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

RM			= rm -rf

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

.PHONY: re all clean fclean