# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aammisse <aammisse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:38:14 by aammisse          #+#    #+#              #
#    Updated: 2025/01/22 15:57:03 by aammisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRCS = mandatory/index.c mandatory/main.c mandatory/parsing.c mandatory/sortsmall.c mandatory/sortbig.c \
		mandatory/maxcontrol.c mandatory/functions/ft_split.c mandatory/functions/functionlist.c \
		mandatory/functions/functionlist2.c mandatory/functions/instructions1.c mandatory/functions/instructions2.c \
		mandatory/functions/libftfunctions.c mandatory/functions/actions.c

BSRCS = bonus/checker.c bonus/parsing_bonus.c bonus/functions/actions.c bonus/functions/ft_split.c \
		bonus/functions/functionlist.c bonus/functions/functionlist2.c bonus/functions/instructions1.c \
		bonus/functions/instructions2.c bonus/functions/libftfunctions.c bonus/GNL/get_next_line.c \
		bonus/GNL/get_next_line_utils.c bonus/helperfunc.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(CHECKER): $(BOBJS)
	$(CC) $(CFLAGS) -g $(BOBJS) -o $@

%.o: %.c mandatory/pushswap.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean all

rebonus: fclean bonus