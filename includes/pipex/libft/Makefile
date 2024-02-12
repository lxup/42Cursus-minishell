# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by emehdaou          #+#    #+#              #
#    Updated: 2024/01/23 12:36:35 by emehdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2023/11/15 17:10:34 by emehdaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS 		=	ft_atoi.c \
ft_tolower.c \
ft_toupper.c \
ft_itoa.c \
ft_isalpha.c \
ft_isascii.c \
ft_isalnum.c \
ft_isdigit.c \
ft_isprint.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_strmapi.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_bzero.c \
ft_memcpy.c \
ft_memset.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_calloc.c \
ft_printf.c \
ft_printf_utils.c \
get_next_line.c \
get_next_line_utils.c \

BONUS		=	ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

INCLUDES	=	-I ./

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3
			
.c.o:
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o ${<:.c=.o}

bonus	: $(OBJS) $(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			@rm -f $(OBJS)
			@rm -f $(OBJS_BONUS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)

.PHONY : re clean fclean all 