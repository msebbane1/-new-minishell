# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbally <lbally@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by marvin            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2022/09/19 17:44:22 by lbally           ###   ########.fr        #
=======
#    Updated: 2022/09/19 15:27:14 by vl-hotel         ###   ########.fr        #
>>>>>>> dcf2f8051de5c3989ff3757fb82f3d997f88d938
#                                                                              #
# **************************************************************************** #

GREEN = "\033[1;32m"
RED = "\033[1;31m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

NAME = minishell

FRONTNAME = MINISHELL

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

LIB		=	libft.a

LIBINC =	-L/Users?$(USER)/.brew/Cellar/readline/8.1.2/lib/

READ	=	-lreadline ./include/libreadline.a -lcurses -o 

SRCS = srcs/minishell.c \
		$(addprefix srcs/lexer/, lexer.c lexer_utils.c here_doc.c quotes.c redirection.c cmd_and_arg.c) \
		$(addprefix srcs/builtins/, env.c path_dir.c unset.c export.c exp.c exit.c echo.c pwd.c cd.c) \
		$(addprefix srcs/, print_init.c signal.c exec.c check_path.c) \
		$(addprefix srcs/utils/, utils1.c utils2.c utils3.c utils4.c utils5.c) \
		$(addprefix srcs/remp/, remplace.c cmdi.c flagi.c argi.c dollar.c argtoflag.c) \
		$(addprefix srcs/free_proc/, free_proc.c) \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: ${NAME}

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)
	
${NAME}: ${OBJS}
		@make -C libft
		@make bonus -C libft
		@mv libft/$(LIB) .
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(LIB)$(GREEN)" has been created\n"$(RESET)
		@$(CC) $(OBJS) $(CFLAGS) $(LIB) -o $(READ) $(NAME)
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(FRONTNAME)$(GREEN)" has been created\n"$(RESET)

clean :
		@${RM} ${OBJS} $(LIB)
		@make clean -C libft
		@printf $(RED)"\r\033[K➜ ["$(FRONTNAME)"] "$(WHITE)"clean"$(RED)" has been done\n"$(RESET)
		@printf $(RED)"\r\033[K➜ [LIB] library folder has been "$(WHITE)"removed"$(RED)"\n"$(RESET)

fclean: clean
		@printf $(GREEN)"\r\033[K🗑️  Deleted: "$(WHITE)$(FRONTNAME)$(RED)" has been deleted\n"$(RESET)
		@${RM} ${NAME}
		
re: fclean all

.PHONY: all clean fclean re
