# -- Colors and formatting
RED				=\033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CC 				= g++
CPPFLAGS 		= -Wall -Wextra -Werror
OS 				= $(shell uname)
COMPILED_FILES 	= 0
SRCS 			= 
OBJS 			= $(SRCS:%.cpp=%.o)

MSG_MAC			= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling... $<... $(RESET)"
MSG_LINUX		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling $<... $(RESET)"

NAME			= 

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJS)

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
