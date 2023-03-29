SRC = ft_atoi.c     ft_strlen.c   ft_split.c    get_next_line.c  fdf.c   ft_strdup.c   ft_strlcpy.c  get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

NAME = fdf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx -O3 -c $< -o $@
clean :
	rm -f $(OBJ) $(NAME)