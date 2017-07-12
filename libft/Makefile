# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 13:37:48 by bfrochot          #+#    #+#              #
#    Updated: 2017/01/06 16:52:16 by bfrochot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PRINTF = ./ft_printf/
PATHTOMAKEFILE = ./ft_printf/
FILE =  ft_atoi \
		ft_bzero \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_itoa_base \
		ft_memalloc \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memccpy \
		ft_memdel \
		ft_memmove \
		ft_memset \
		ft_putchar \
		ft_putchar_fd \
		ft_putendl \
		ft_putendl_fd \
		ft_putnbr \
		ft_putnbr_fd \
		ft_putstr \
		ft_putstr_fd \
		ft_strcat \
		ft_strchr \
		ft_strclr \
		ft_strcmp \
		ft_strcpy \
		ft_strdel \
		ft_strdup \
		ft_striter \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlen \
		ft_strmap \
		ft_strmapi \
		ft_strncat \
		ft_strncmp \
		ft_strncpy \
		ft_strnew \
		ft_strnequ \
		ft_strnstr \
		ft_strequ \
		ft_strrchr \
		ft_strsplit \
		ft_strstr \
		ft_strsub \
		ft_strtrim \
		ft_tolower \
		ft_toupper \
		ft_lstnew \
		ft_lstdelone \
		ft_lstdel \
		ft_lstadd \
		ft_lstiter \
		ft_lstmap \
		ft_is_prime \
		ft_recursive_factorial \
		ft_recursive_power \
		ft_printmemory \
		ft_sqrt \
		get_next_line \
		$(PRINTF)printf \
		$(PRINTF)addprint \
		$(PRINTF)conv \
		$(PRINTF)diese \
		$(PRINTF)ft_atoi_base \
		$(PRINTF)ft_isokay \
		$(PRINTF)ft_opts \
		$(PRINTF)opts1 \
		$(PRINTF)opts2 \
		$(PRINTF)part1 \
		$(PRINTF)part2 \
		$(PRINTF)part3 \
		$(PRINTF)pfunct
OBJ  := $(addsuffix .o, $(FILE))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "----------------------------------------"
	@echo "|       Debut de la compilation        |"
	@echo "|              Ecole 42                |"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "|                libft                 |"
	@echo "|                 FIN                  |"
	@echo "----------------------------------------"

$(OBJ): %.o: %.c
	@gcc -c -Wall -Wextra -Werror -I ./includes/ $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C $(PATHTOMAKEFILE) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(PATHTOMAKEFILE) fclean

re: fclean all

.PHONY : all clean fclean re
