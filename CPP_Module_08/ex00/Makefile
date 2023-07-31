
NAME		= run
SRCS		= $(wildcard ./*.cpp)
#HEADRS		= $(wildcard ./*.hpp)
HEADRS		= $(wildcard ./*.h)
TEMPLATES	= $(wildcard ./*.tpp)
OBJS		= $(patsubst ./%.cpp, ./%.o, $(SRCS))

CXX				= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

Rm	= rm -rf

./%.o : ./%.cpp $(HEADRS) $(TEMPLATES) Makefile
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

valgrind: all
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$(LOGFILE) \
         ./$(NAME)

valgrind_clean: fclean
	$(RM) $(LOGFILE)

.PHONY : re all clean fclean valgrind valgrind_clean
