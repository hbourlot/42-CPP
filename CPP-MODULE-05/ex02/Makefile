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
INCLUDE         = inc/
HEADERS         = $(shell find $(INCLUDE) -name "*.hpp")
SRC_DIR         = src/
BONUS_DIR       = bonus/
OBJ_DIR         = obj/

# -- Variables
COMPILED_FILES  = 0
LEN             = 0
CPP_FUNC	    = AForm Bureaucrat ShrubberyCreationForm RobotomyRequestForm RobotomyRequestForm PresidentialPardonForm main
SRC_FILES       = $(addprefix $(SRC_DIR), $(CPP_FUNC:=.cpp))

OBJS_SRC        = $(addprefix $(OBJ_DIR), $(SRC_FILES:%.cpp=%.o))
LIB             = libForm.a
CXX             = c++
CXXFLAGS        = -std=c++98
NAME            = Bureaucrat
TOTAL_FILES     = $(shell echo $$(($(words $(OBJS_SRC)))))
VALGRIND        = valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes
# MSG             = "[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1]... $(RESET)"
MSG 			= "$(CYAN) => ($(COMPILED_FILES)/$(TOTAL_FILES) $(PERCENT)%%) 🔧 Compiling [$1]...$(RESET)"

# -- Cleaning functions
define clean_func
	@if [ -d "$(OBJ_DIR)" ]; then \
		$(PRINT_CMD) "$(ORANGE) Removing '$(WHITE_BOLD)$(OBJ_DIR)$(ORANGE)'... $(RESET)"; \
		rm -rf $(OBJ_DIR); \
		rm -f main.o; \
		$(PRINT_CMD) "$(GREEN) Removed successfully!$(RESET)\n"; \
	fi
endef

define fclean_func
	@if [ -f "$(LIB)" ]; then \
		$(PRINT_CMD) "$(ORANGE) Removing library '$(WHITE_BOLD)$(LIB)$(ORANGE)'... $(RESET)"; \
		rm -f $(LIB); \
		$(PRINT_CMD) "$(GREEN) Removed successfully!$(RESET)\n"; \
	fi
	@if [ -f "$(NAME)" ]; then \
		$(PRINT_CMD) "$(ORANGE) Removing executable '$(WHITE_BOLD)$(NAME)$(ORANGE)'... $(RESET)"; \
		rm -f $(NAME); \
		$(PRINT_CMD) "$(GREEN) Removed successfully!$(RESET)\n"; \
	fi
endef

define check_completion
	@if [ $(COMPILED_FILES) -eq $(TOTAL_FILES) ]; then \
		$(PRINT_CMD) "$(GREEN)Compilation complete!$(RESET) ✅\n"; \
	fi
endef

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
	@$(call fclean_func)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus

# Shortcuts
r:
	@make -s
	@./$(NAME)

v:
	@make -s
	@$(VALGRIND) ./$(NAME)

fc: fclean

c: clean