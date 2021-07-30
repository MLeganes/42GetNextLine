# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/26 13:25:49 by x250              #+#    #+#              #
#    Updated: 2021/07/29 14:00:48 by amorcill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftgetnextline.a

FLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c  get_next_line_utils.c

$(NAME):
	gcc $(FLAGS) -c $(SRCS)
	ar  $(NAME) *.o

all: $(NAME)

clean:
	rm -f *.o
	rm -f *.out

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

	