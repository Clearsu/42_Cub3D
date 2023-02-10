# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 18:00:49 by jincpark          #+#    #+#              #
#    Updated: 2023/02/10 20:32:34 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME
NAME		=	cub3d

#CMDS
CC			=	cc
RM			=	rm -rf
LIBC		=	ar rcs

#FLAGS
CFLAGS		=	#-Wall -Wextra -Werror
DFLAGS		=	-g3 -fsanitize=address

#DIRS
LFTDIR		=	libft
SRCDIR		=	srcs
INCDIR		=	incs

#FILES
LIBS		=	$(LFTDIR)/libft.a
INCS		=	-I $(LFTDIR) -I $(INCDIR)
SRCS		=	$(SRCDIR)/main.c \
				$(SRCDIR)/parse_data.c \
				$(SRCDIR)/parse_map.c \
				$(SRCDIR)/parse_texture_color.c \
				$(SRCDIR)/parse_check.c \
				$(SRCDIR)/parse_util.c \
				$(SRCDIR)/basic_wall_check.c \
				$(SRCDIR)/is_map_fully_closed.c \
				$(SRCDIR)/check_spawn_location.c \
				$(SRCDIR)/state_start_branch.c \
				$(SRCDIR)/state_texture.c \
				$(SRCDIR)/state_empty.c \
				$(SRCDIR)/state_color.c \
				$(SRCDIR)/state_map.c \
				$(SRCDIR)/print_err_and_exit.c

ifdef IF_DEBUG
	CFLAGS += $(DFLAGS)
endif

all :
	@$(MAKE) -j6 $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

OBJS		=	${SRCS:.c=.o}

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LFTDIR) libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean :
	@$(MAKE) -C $(LFTDIR) fclean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

rebug	:
	$(MAKE) fclean
	$(MAKE) IF_DEBUG=1 all

.PHONY : all clean fclean re
