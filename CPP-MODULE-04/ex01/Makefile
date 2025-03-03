# -- Colors and formatting
RED				= \033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC 				= g++
SRCS 			= Animal Dog Cat WrongCat WrongAnimal Brain
SRC_FILES		= $(addprefix src/, $(SRCS:=.cpp))
OBJ_DIR			= obj/
OBJS 			= $(addprefix $(OBJ_DIR), $(SRCS:=.o))
# OBJS 			= $(patsubst src/%.cpp, obj/%.o, $(SRC_FILES))
CPPFLAGS 		= -std=c++98 -Wall -Wextra -Werror #-Wshadow -Wno-shadow
COMPILED_FILES	= 0

TOTAL_FILES		= $(shell echo $$(($(words $(OBJS))  + 1)))
OS				= $(shell uname)

MSG_MAC			= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$<] ... $(RESET)"
MSG_LINUX		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling [$<]... $(RESET)"

ifeq ($(OS), Darwin)
	PRINT_CMD = printf
	MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$1] ... $(RESET)"
else
	PRINT_CMD = echo -n
	MSG = "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling [$1]... $(RESET)"
endif

# Function to print the compilation message
define print_compile_msg
	$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(PRINT_CMD) $(MSG)
endef

NAME 			= Animal

.PHONY:			all clean fclean re bonus

all:			$(NAME)
				@echo "$(GREEN)Executable '$(RED)$(NAME)$(GREEN)' created successfully!$(RESET) ✅"

$(NAME):		$(OBJS) main.o
				@$(CC) $(CPPFLAGS) $^ -o $@

obj/%.o: 		src/%.cpp inc/%.hpp
				@mkdir -p $(dir $@)
				$(call print_compile_msg, $<)
				@$(CC) $(CPPFLAGS) -c $< -Iinc -o $@

main.o:			main.cpp  ./inc/
				$(call print_compile_msg, $<)
				@$(CC) $(CPPFLAGS) -c $< -Iinc -o $@


clean:
				@rm -rf $(OBJ_DIR) main.o

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

r: 				re all
				./$(NAME)
				@make -s fclean

v:				re all
				valgrind ./$(NAME)
				@make -s fclean