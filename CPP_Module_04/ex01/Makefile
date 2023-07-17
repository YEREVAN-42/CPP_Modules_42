# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 18:09:53 by khovakim          #+#    #+#              #
#    Updated: 2023/07/17 18:20:38 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Polymorphism
SRCS	= $(wildcard ./*.cpp)
HEADRS	= $(wildcard ./*.hpp)
OBJS	= $(patsubst ./%.cpp, ./%.o, $(SRCS))

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

Rm	= rm -rf

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

LOGFILE	 = valgrind-out.txt

valgrind:
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$(LOGFILE) \
         ./$(NAME)

valgrind_clean:
	$(RM) $(LOGFILE)

.PHONY : re all clean fclean valgrind valgrind_clean
