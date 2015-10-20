# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbahus <jbahus@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/24 15:41:40 by jbahus            #+#    #+#              #
#    Updated: 2015/10/20 17:20:46 by jbahus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = main.c do_stuff.c ft_cd.c write_user.c get_in_env.c ft_new_env.c
SRC += ft_del_env.c ft_cd_check.c ft_ex_bin.c
HDR = ft_minishell.h
LIB = -lft -L libft
OBJ = $(SRC:%.c=obj/%.o)
GCC = gcc -Wall -Wextra -Werror

all: lib_ft obj $(NAME)

lib_ft:
	@cd libft ; $(MAKE) -f Makefile

obj:
	@mkdir -p obj/

$(NAME): $(OBJ)
	@$(GCC) $(OBJ) -o $(NAME) $(LIB)

obj/%.o: %.c $(HDR)
	@$(GCC) -c $< -o $@

clean:
	@rm -rf obj/

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted."
	@make -C libft/ fclean

re: fclean all

norme:
	@norminette $(SRC) $(HDR)

.PHONY: all lib_ft clean fclean re norme