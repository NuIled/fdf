# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoutifra <aoutifra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 15:10:49 by aoutifra          #+#    #+#              #
#    Updated: 2023/04/20 15:33:28 by aoutifra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -O3  -g -fsanitize=address 

SRC = utils.c parser.c ft_atoi.c  ft_strlen.c   ft_split.c    get_next_line.c  fdf.c   ft_strdup.c   ft_strlcpy.c  get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -framework OpenGL -framework AppKit -lmlx -o $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm $(name)

re :fclean all

.PHONY : clean all re fclean