# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmastrel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 15:18:08 by mmastrel          #+#    #+#              #
#    Updated: 2017/03/20 01:18:54 by mmastrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CFLAGS	= gcc -Wall -Wextra -Werror

SRC		=	ft_printf.c \
			format_flags.c \
			format_flag_helper.c \
			ft_ilength.c \
			handle_num.c \
			print_c.c \
			print_num.c \
			int_to_a.c \
			print_p.c \
			print_n.c \
			print_percent.c \
			print_padding.c \
			print_s.c \
			ft_itoa_base.c \
			ft_putstrn.c \
			ft_uitoa_base.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strcpy.c \
			ft_strlen.c \
			ft_strnew.c \
			ft_memalloc.c \
			ft_memset.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

OBJDIR	= ./obj/

SRCDIR	= ./src/

INCDIR	= ./includes/

all: obj $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
