# -- Colors and formatting
RED				=\033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC 				= g++
SRCS 			= Account.cpp tests.cpp
OBJS 			= $(SRCS:%.cpp=%.o)
CPPFLAGS 		= -Wall -Wextra -Werror -std=c++98
COMPILED_FILES	= 0

TOTAL_FILES		= $(words $(OBJS))
OS				= $(shell uname)

MSG_MAC			= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling... $<... $(RESET)"
MSG_LINUX		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling $<... $(RESET)"

NAME 			= missing

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CPPFLAGS) $^ -o $@

%.o: 		%.cpp
			$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
			@printf $(MSG_MAC)
else
			@echo -n $(MSG_LINUX)
endif
			@$(CC) $(CPPFLAGS) -c $< -o $@


clean:
				@rm -rf $(OBJS)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

r: 				all
				./missing
