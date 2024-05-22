# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: resilva <resilva@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 18:59:11 by resilva           #+#    #+#              #
#    Updated: 2024/05/16 18:51:25 by resilva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
MAGENTA	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

NAME	=	pipex

SRC		=	$(wildcard src/*.c)
OBJS	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -g

CC		=	gcc
MAKE 	=	make -C
RM		=	rm -f
INCLUDE	=	-I ./include
LIBFT_P	=	libft
LIBFT 	=	-L $(LIBFT_P) -lft

.c.o:
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(MAGENTA)Compiling:$(RESET) $(GREEN)libft/*$(RESET)"
			$(MAKE) $(LIBFT_P)
			
			@echo "$(CYAN)🔗 Linking...$(RESET)"
			$(CC) $(OBJS) $(LIBFT) -o $(NAME)

			@echo "$(GREEN)🎉 Compilation is done! 🎉$(RESET)"

clean:
			@$(RM) $(OBJS)
			$(MAKE) $(LIBFT_P) clean
			@echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(OBJS)$(RESET)"

fclean:		clean
			$(MAKE) $(LIBFT_P) fclean
			@$(RM) $(NAME)
			@echo "$(RED)🗑️  Deleted: $(RESET) $(GREEN)$(NAME)$(RESET)"

re:			fclean all

.PHONY: all clean fclean re