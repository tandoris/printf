# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clboutry <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 04:12:06 by clboutry          #+#    #+#              #
#    Updated: 2019/08/20 04:24:37 by clboutry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = printf

SRCS = ft_printf.c\
	   ft_itoa_base_printf.c\
	   ft_nbr_len_base.c\
	   ft_padding_left_right.c\
	   ft_print_decimal.c\
	   ft_parsing.c\

FLAGS = -Wall -Wextra -Werror

LIBFT = ../libft/libft.a

LIBPRINTF = ft_printf.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	#make -C libft/
	$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJS)
	#make clean -C libft/

fclean: clean
	rm -rf $(NAME)
	#make fclean -C libft/

re: fclean all
