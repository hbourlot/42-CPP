# -- Colors and formatting
RED				= \033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC 				= g++
SRCS 			= Animal Dog Cat WrongCat WrongAnimal
SRC_FILES		= $(addprefix src/, $(SRCS:=.cpp))
OBJS 			= $(SRC_FILES:%.cpp=%.o)
CPPFLAGS 		= -std=c++98 #-Wall -Wextra -Werror #-Wshadow -Wno-shadow
COMPILED_FILES	= 0

TOTAL_FILES		= $(shell echo $$(($(words $(OBJS))  + 1)))
OS				= $(shell uname)

MSG_MAC			= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling [$<] ... $(RESET)"
MSG_LINUX		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling [$<]... $(RESET)"


NAME 			= Animal

.PHONY:			all clean fclean re bonus

all:			$(NAME)
				@echo "$(GREEN)Executable '$(RED)$(NAME)$(GREEN)' created successfully!$(RESET) ✅"

$(NAME):		$(OBJS) main.o
				@$(CC) $(CPPFLAGS) $^ -o $@

%.o: 		%.cpp
			$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
			@printf $(MSG_MAC)
else
			@echo -n $(MSG_LINUX)
endif
			@$(CC) $(CPPFLAGS) -c $< -I./inc -o $@

clean:
				@rm -rf $(OBJS) main.o

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

r: 				re all
				./$(NAME)
				@make -s fclean

v:				re all
				valgrind ./$(NAME)
				@make -s fclean