# -- Colors and formatting
RED				=\033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CXX 			= c++
SRCS 			= HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
OBJS 			= $(SRCS:%.cpp=%.o)
CXXFLAGS 		= -Wall -Wextra -Werror -std=c++98
COMPILED_FILES	= 0

TOTAL_FILES		= $(words $(OBJS))
OS				= $(shell uname)

NAME 			= weapons


ifeq ($(OS), Darwin)
	PRINT_CMD = printf
	MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1]... $(RESET)"
else
	PRINT_CMD = echo -n
	MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling [$1]... $(RESET)"
endif

# Function to print the compilation message
define print_compile_msg
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(PRINT_CMD) $(MSG)
endef

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CXX) $(CXXFLAGS) $^ -o $@
				@echo "$(GREEN)Executable '$(RED)$(NAME)$(GREEN)' created sucXXessfully!$(RESET) ✅"

%.o: 		%.cpp
			$(call print_compile_msg, $<)
			@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
				@rm -rf $(OBJS)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

r: 				all
				./$(NAME)

v: 				all
				valgrind ./$(NAME)

.PHONY:			all clean fclean re bonus
