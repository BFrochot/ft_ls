# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/06 15:19:55 by bfrochot          #+#    #+#              #
#    Updated: 2017/01/21 18:28:02 by bfrochot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

PATHTOMAKEFILE = ./libft/

FILE =	main \
		ls_flag \
		ls_core \
		ft_sort \
		transfo \
		transfo2 \
		list_free \
		cpd \
		print_l \
		sort_part2 \
		core_p2 \
		elemcreate \
		error

OBJ  := $(addsuffix .o, $(FILE))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "----------------------------------------"
	@echo "|       Debut de la compilation        |"
	@echo "|              Ecole 42                |"
	@echo "|               ft_ls                  |"
	@echo "|           sub compilation :          |"
	@echo "|               libft                  |"
	@make -C $(PATHTOMAKEFILE)
	@gcc -Wall -Wextra -Werror -Os -L./libft/ -lft -o $(NAME) -Wextra $(OBJ)
	@echo "|                 FIN                  |"
	@echo "----------------------------------------"
	@echo "               ________"
	@echo "          _,.-Y  |  |  Y-._"
	@echo "      .-~\"   ||  |  |  |   \"-."
	@echo "      I\" \"\"==\"|\" !\"\"! \"|\"[]\"\"|     _____"
	@echo "      L__  [] |..------|:   _[----I\" .-{\"-."
	@echo "     I___|  ..| l______|l_ [__L]_[I_/r(=}=-P"
	@echo "    [L______L_[________]______j~  '-=c_]/=-^"
	@echo "     \_I_j.--.\==I|I==_/.--L_]"
	@echo "       [_((==)[\`-----\"](==)j"
	@echo "          I--I\"~~\"\"\"~~\"I--I"
	@echo "          |[]|         |[]|"
	@echo "          l__j         l__j"
	@echo "          |!!|         |!!|"
	@echo "          |..|         |..|"
	@echo "          ([])         ([])"
	@echo "          ]--[         ]--["
	@echo "          [_L]         [_L]"
	@echo "         /|..|\       /|..|\\"
	@echo "        \`=}--{='     \`=}--{=i'"
	@echo "       .-^--r-^-.   .-^--r-^-."
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

$(OBJ): %.o: %.c
	@gcc -c -Wall -Wextra -Werror -Os -g $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C $(PATHTOMAKEFILE) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(PATHTOMAKEFILE) fclean

re: fclean all

.PHONY : all clean fclean re
