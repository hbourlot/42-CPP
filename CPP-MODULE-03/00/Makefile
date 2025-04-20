# -- Colors and formatting
RED				= \033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m


# -- Compiler settings
CXX				= c++
CXXFLAGS		= -std=c++98 -Wall -Wextra -Werror #-Wshadow -Wno-shadow
NAME			= Interface

# -- Files and directories
INCLUDE_DIR 	= inc/
SRC_DIR 		= src/
OBJ_DIR 		= obj/
HEADERS			= inc/ClapTrap.hpp

# -- Variables
TOTAL_FILES		= $(shell echo $$(($(words $(OBJS_SRC)) + 1)))
COMPILED_FILES	= 0
OS				= $(shell uname)
VALGRIND		= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes


C_FUNCTIONS		= ClapTrap
SRC_FILES 		= $(addprefix $(SRC_DIR), $(C_FUNCTIONS:=.cpp))
OBJS_SRC 		= $(addprefix $(OBJ_DIR), $(SRC_FILES:%.cpp=%.o))


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

# Function to clean
define clean_func
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(OBJ_DIR)' directory and main.o...$(RESET) "; \
		rm -rf $(OBJ_DIR); \
		rm -rf main.o; \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef

# Function to full clean
define fclean_func
	@if [ -f "$(LIB)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(YELLOW)$(LIB)$(ORANGE)' library...$(RESET) "; \
		rm -f $(LIB); \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
	@if [ -f "$(NAME)" ]; then \
		$(PRINT_CMD) "$(ORANGE)Removing '$(RED)$(NAME)$(ORANGE)' executable...$(RESET) "; \
		rm -f $(NAME); \
		$(PRINT_CMD) "$(GREEN)Removed successfully!$(RESET) ✅\n"; \
	fi
endef


all:				$(NAME)


$(NAME): 			$(OBJS_SRC) $(OBJ_DIR)main.o
					@$(CXX) $(CXXFLAGS) $^ -o $@
					@echo "$(GREEN)Executable '$(RED)$(NAME)$(GREEN)' created successfully!$(RESET) ✅"

$(OBJS_SRC):		$(SRC_FILES) $(HEADERS)
					@mkdir -p $(dir $@)
					$(call print_compile_msg, $<)
					@$(CXX) $(CXXFLAGS) -c $< -I./$(INCLUDE_DIR) -o $@

$(OBJ_DIR)main.o:	main.cpp $(HEADERS)
					$(call print_compile_msg, $<)
					@$(CXX) $(CXXFLAGS) -c main.cpp -I./$(INCLUDE_DIR) -o $@

clean:
					$(call clean_func)

fclean: 			clean
					@$(call fclean_func)

re: 				fclean all

bonus:				all

r:
	./$(NAME)
	
v:
	@make -s
	@$(VALGRIND) ./$(NAME)

.PHONY: 			all clean fclean re bonus
