# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 13:24:26 by khovakim          #+#    #+#              #
#    Updated: 2023/07/05 16:33:36 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= harlFilter
SRCS	= $(wildcard ./*.cpp)
HEADRS	= $(wildcard ./*.hpp)
OBJS	= $(patsubst ./%.cpp, ./%.o, $(SRCS))

CXX			= c++
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
