# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khovakim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 16:20:16 by khovakim          #+#    #+#              #
#    Updated: 2023/06/29 18:57:41 by khovakim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
SRCS	=	$(wildcard *.cpp)
OBJS	=	$(patsubst %.cpp, %.o, $(SRCS))

CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM	=	rm -rf

%.o : %.cpp Makefile
	$(CC) $(CPPFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re all clean fclean

