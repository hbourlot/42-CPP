# -- Colors and formatting
RED				=\033[1;31m
YELLOW 			= \033[1;33m
ORANGE 			= \033[1;38;5;214m
GREEN 			= \033[1;32m
CYAN 			= \033[1;36m
RESET 			= \033[0m

CXX 			= c++
SRCS 			= main.cpp
OBJS 			= $(SRCS:%.cpp=%.o)
CXXFLAGS 		= -Wall -Wextra -Werror -std=c++98 -pedantic
COMPILED_FILES	= 0

TOTAL_FILES		= $(words $(OBJS))
OS				= $(shell uname)

MSG_MAC			= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))%% ] $(ORANGE)Compiling... $<... $(RESET)"
MSG_LINUX		= "\r%100s\r[ $(COMPILED_FILES)/$(TOTAL_FILES) $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))% ] $(ORANGE)Compiling $<... $(RESET)"

NAME 			= sedIsForLosers

.PHONY:			all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CXX) $(CXXFLAGS) $^ -o $@

%.o: 		%.cpp
			$(eval COMPILED_FILES = $(shell echo $$(($(COMPILED_FILES) + 1))))
ifeq ($(OS), Darwin)
			@printf $(MSG_MAC)
else
			@echo -n $(MSG_LINUX)
endif
			@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
				@rm -rf $(OBJS)

fclean:			clean
				@rm -rf $(NAME)

re:				fclean all

r: 				re all
				./$(NAME) zezinho
