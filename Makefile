# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gbouwen <marvin@codam.nl>                    +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/07 16:19:39 by gbouwen       #+#    #+#                  #
#    Updated: 2020/07/08 18:12:36 by gbouwen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SOURCE_S =	_ft_strlen.s \
			_ft_strcmp.s \
   		    _ft_strcpy.s \
			_ft_write.s \
			_ft_read.s \
			_ft_strdup.s \

SOURCE_O = $(SOURCE_S:.s=.o)

NORMAL = \033[38;5;255m
GREEN = \033[38;5;2m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

all: $(NAME)

%.o: %.s
	@echo "$(GREEN)Creating object files:$(NORMAL)"
	nasm -f macho64 $<

$(NAME): $(SOURCE_O)
	@echo "$(BLUE)Adding to library...$(NORMAL)"
	ar rc $(NAME) $(SOURCE_O)
	@echo "$(GREEN)Successfully aded to library!$(NORMAL)"

clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	/bin/rm -f $(SOURCE_O)
	@echo "$(GREEN)Successfully removed all object files!$(NORMAL)"

fclean:	clean
	@echo "$(RED)Removing libasm.a...$(NORMAL)"
	/bin/rm -f $(NAME)
	@echo "$(GREEN)Successfully removed libasm.a!$(NORMAL)"
	/bin/rm -f test

test:
	@gcc -Wall -Wextra -Werror main.c $(NAME) -o test
	@./test

re: fclean all

.PHONY: all clean fclean re
