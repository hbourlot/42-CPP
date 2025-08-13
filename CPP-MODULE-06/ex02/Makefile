# -- Colors and formatting
RED             = \033[1;31m
YELLOW          = \033[1;33m
ORANGE          = \033[1;38;5;214m
GREEN           = \033[1;32m
CYAN            = \033[1;36m
RESET           = \033[0m
WHITE_BOLD 		= \033[1;97m
UP              = "\033[A"
CUT				= "\033[K"
PRINT_CMD       = printf

# -- Files and directories
INCLUDE 		= inc/
HEADERS 		= $(shell find $(INCLUDE) -name "*.hpp")
SRC_DIR 		= src/
OBJ_DIR 		= obj/

# -- Variables
COMPILED_FILES 	= 0
CPP_FUNC 		= Base A B C main
SRC_FILES 		= $(addprefix $(SRC_DIR), $(CPP_FUNC:=.cpp))
TOTAL_FILES 	= $(words $(SRC_FILES))
OBJS_SRC        = $(addprefix $(OBJ_DIR), $(SRC_FILES:%.cpp=%.o))
LIB 			= libBase
CXX 			= c++
CXXFLAGS 		= -std=c++98
NAME 			= Base
VALGRIND 		= valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes


# -- Targets
all: $(NAME)

$(NAME): $(LIB) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(LIB) -o $(NAME)
	@echo "$(GREEN) Executable '$(RED)$(NAME)$(GREEN)' created successfully!$(RESET) ✅"

$(LIB): $(OBJS_SRC)
	@ar rcs $@ $(OBJS_SRC)
	@echo "$(CYAN) library '$(YELLOW)$(LIB)$(CYAN)' created successfully!$(RESET)"

$(OBJ_DIR)%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
	$(eval PERCENT = $(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	@echo "$(CYAN) => ($(COMPILED_FILES)/$(TOTAL_FILES) $(PERCENT)%) Compiling [$<]...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -I./$(INCLUDE) -o $@
	@printf ${UP}${CUT}

clean:
	$(call clean_func)

fclean: clean
	$(call fclean_func)

re: fclean all

.PHONY: all clean fclean re bonus

# -- Shortcuts

r:
	@make -s
	@./$(NAME)

v:
	@make -s
	@$(VALGRIND) ./$(NAME)

fc:	fclean

c : clean


# -- Cleaning functions
define clean_func
	@if [ -d "$(OBJ_DIR)" ]; then \
	$(PRINT_CMD) "$(ORANGE) Removing '$(WHITE_BOLD)$(OBJ_DIR)$(ORANGE)'... $(RESET)"; \
	rm -rf $(OBJ_DIR); \
	$(PRINT_CMD) "$(GREEN) Removed successfully!$(RESET)\n"; \
	fi
endef

define fclean_func
	@if [ -f "$(LIB)" ]; then \
	$(PRINT_CMD) "$(ORANGE) Removing '$(WHITE_BOLD)$(LIB)$(ORANGE)'... $(RESET)"; \
	rm -rf $(LIB); \
	$(PRINT_CMD) "$(GREEN) Removed successfully!$(RESET)\n"; \
	fi
	@if [ -f "$(NAME)" ]; then \
	$(PRINT_CMD) "$(ORANGE) Removing '$(WHITE_BOLD)$(NAME)$(ORANGE)'... $(RESET)"; \
	rm -rf $(NAME); \
	$(PRINT_CMD) "$(GREEN) Removed successfully!$(RESET)\n"; \
	fi
endef