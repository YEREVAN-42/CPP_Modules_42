########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
LDFLAGS  =

# Makefile settings - Can be customized
NAME   = RPN
SRCDIR = src
OBJDIR = obj
DEPDIR = dependecy

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)

# UNIX-based OS variables & settings
RM     = rm -rf
DELOBJ = $(OBJ)

########################################################################
####################### Targets beginning here #########################
########################################################################

.PHONY: all
all: $(NAME)

# Builds the app
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Creates the dependecy rules
$(DEPDIR)/%.d: $(SRCDIR)/%.cpp
	@mkdir -p ./$(DEPDIR)
	$(CPP) $(CFLAGS) $< -MM -MT $(@:$(DEPDIR)/%.d=$(OBJDIR)/%.o) >$@

# Includes all .h & .hpp files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp Makefile
	@mkdir -p ./$(OBJDIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

################### Cleaning rules for Unix-based OS ###################

# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(DEP) $(DEPDIR) $(OBJDIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

########################################################################
######################## Building with valgrind ########################
########################################################################

LOGFILE	 = valgrind-out.txt

.PHONY: valgrind
valgrind: all
	valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$(LOGFILE) \
         ./$(NAME)

######################## Cleaning with valgrind ########################

.PHONY: valgrind_clean
valgrind_clean: fclean
	$(RM) $(LOGFILE)
