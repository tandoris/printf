# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clboutry <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 04:12:06 by clboutry          #+#    #+#              #
#    Updated: 2019/08/27 21:53:48 by clboutry         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = printf

SRCS = ft_printf.c\
	   ft_itoa_base_printf.c\
	   ft_nbr_len_base.c\
	   ft_padding.c\
	   ft_print_decimal.c\
	   ft_parsing.c\
	   ft_print_char.c\
	   ft_print_string.c\
	   ft_print_pointer.c\
	   ft_uitoa_base_printf.c\
	   ft_unsigned_nbr_len_base.c\
	   ft_print_percent.c\

FLAGS = -Wall -Wextra -Werror

LIBFT = libftprintf/libftprintf.a

LIBPRINTF = ft_printf.h

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libftprintf/
	@$(CC) $(FLAGS) $(LIBFT) $(OBJS) -o $(NAME) 

clean:
	@rm -rf $(OBJS)
	@make clean -C libftprintf/

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libftprintf/

re: fclean all
