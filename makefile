# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oqatim <oqatim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 19:44:38 by oussama           #+#    #+#              #
#    Updated: 2023/02/28 18:19:22 by oqatim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

NAME_BONUS = cub3d_bonus

HEADER = cub3d.h

HEADER_BONUS = ./bonus/cub3d_bonus.h

CC = gcc

FLAGS = -Wall -Wextra -Werror  -g 

SRC = cub3d_utilis/cub3d_utilis.c cub3d_utilis/cub3d_utilis2.c cub3d_utilis/cub3d_utilis3.c \
		parsing/init.c parsing/parse_color.c parsing/parse_color2.c parsing/parse_color3.c parsing/parse_txt.c parsing/check_utiles2.c \
		cub3d.c parsing/check_map.c parsing/check_utiles.c parsing/ft_parsing.c parsing/ft_free.c\
		parsing/parse_txt2.c rendring/rendring_utilis.c rendring/ft_mouvement.c rendring/compare_distance.c rendring/draw_texture.c \
		rendring/horz_intercept.c rendring/rendering_3d.c rendring/utiles_raycasting.c rendring/vert_intercept.c \

SRC_BONUS = ./bonus/cub3d_utilis/cub3d_utilis.c ./bonus/cub3d_utilis/cub3d_utilis2.c ./bonus/cub3d_utilis/cub3d_utilis3.c \
		./bonus/parsing/init.c ./bonus/parsing/parse_color.c ./bonus/parsing/parse_color2.c ./bonus/parsing/parse_color3.c ./bonus/parsing/parse_txt.c ./bonus/parsing/check_utiles2.c \
		./bonus/cub3d_bonus.c ./bonus/parsing/check_map.c ./bonus/parsing/check_utiles.c ./bonus/parsing/ft_parsing.c ./bonus/parsing/ft_free.c\
		./bonus/parsing/parse_txt2.c ./bonus/rendring/rendring_utilis.c ./bonus/rendring/ft_mouvement.c ./bonus/rendring/compare_distance.c ./bonus/rendring/draw_texture.c \
		./bonus/rendring/horz_intercept.c ./bonus/rendring/rendering_3d.c ./bonus/rendring/utiles_raycasting.c ./bonus/rendring/vert_intercept.c \

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -c -o $@ $<

	
OBJ = $(SRC:%.c=%.o)
OBJB = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(OBJB) $(HEADER_BONUS)
	$(CC) $(FLAGS) $(OBJB) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJB)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)

re: fclean all
