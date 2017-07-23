#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpotapov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/07 17:20:31 by mpotapov          #+#    #+#              #
#    Updated: 2017/07/22 15:50:32 by mpotapov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

BONUS = visu-hex

OBJ = main.o get_next_line.o algoritm.o run_ants.o print_ants.o bfs.o bfs2.o links_and_matrix.o rooms_and_commands.o go_for_one_step.o check_rooms_and_cords.o

BONUS_OBJ = bonus.o bonus2.o get_next_line.o

FLAGS = -Wall -Wextra -Werror

all: $(OBJ) $(BONUS_OBJ) $(NAME)

$(NAME):
	@make -C ./libft
	@gcc $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@gcc $(FLAGS) $(BONUS_OBJ) libft/libft.a -o $(BONUS)
	@echo "\n\033[22;32mCompiled\033[0m\n"
%.o: %.c
	@gcc -o $@ -c $< -I . -I ./libft
clean:
	@make clean -C ./libft
	@rm -rf $(OBJ)
	@rm -rf $(BONUS_OBJ)
	@echo "\n\033[22;32mObjects deleted\033[0m\n"
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@make fclean -C ./libft
	@echo "\n\033[22;32mExecutable deleted\033[0m\n"
re: fclean all