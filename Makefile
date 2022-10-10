# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by marvin            #+#    #+#              #
#    Updated: 2022/10/10 15:35:20 by msebbane         ###   ########.fr        #
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

READLINE_PATH = vendor/readline/

READ	=	libft.a -L$(READLINE_PATH)/lib -lreadline

SRCS = srcs/minishell.c \
		$(addprefix srcs/lexer/, lexer.c lexer_utils.c here_doc.c quotes.c redirection.c cmd_and_arg.c) \
		$(addprefix srcs/builtins/, env.c env2.c unset.c export.c export2.c export3.c exp.c exp2.c exp3.c exit.c echo.c cd.c pwd.c) \
		$(addprefix srcs/, print_init.c signal.c check_path.c) \
		$(addprefix srcs/utils/, utils1.c utils2.c) \
		$(addprefix srcs/free_proc/, free_proc.c) \
		$(addprefix srcs/rempval/, rempv.c repquotes.c remputils.c) \
		$(addprefix srcs/execution/, exec.c brain.c utilexec.c) \

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: readline ${NAME}

$(READLINE_PATH):
	sh ./include/install_readline.sh

readline: $(READLINE_PATH)

.c.o: $(SRCS)
	@printf $(GREEN)"\r\033[KCreating object files 👉 "$(YELLOW)"<$<> "$(RESET)
	@$(CC) $(CFLAGS) -I$(READLINE_PATH)/include $(HEADER) -c $< -o $(<:.c=.o)
	
${NAME}: ${OBJS}
		@make -C libft
		@make bonus -C libft
		@mv libft/$(LIB) .
		@printf $(GREEN)"\r\033[K✅ SUCCESS: "$(WHITE)$(LIB)$(GREEN)" has been created\n"$(RESET)
		@$(CC) $(OBJS) $(CFLAGS) $(READ) $(LIB) -o $(NAME)
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

.PHONY: all clean fclean re readline
