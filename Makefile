# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 18:00:49 by jincpark          #+#    #+#              #
#    Updated: 2023/02/11 21:43:43 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME
NAME		=	cub3d

#CMDS
CC			=	cc
RM			=	rm -f
LIBC		=	ar rcs

#FLAGS
CFLAGS		=	#-Wall -Wextra -Werror
DFLAGS		=	-g3 -fsanitize=address
MLXFLAGS 	= 	-lmlx -L. -framework OpenGL -framework Appkit


#DIRS
LFTDIR		=	libft
SRCDIR		=	srcs
PARSEDIR	=	parse_map
UTILDIR		=	util
INCDIR		=	incs
MLXDIR 		= 	minilibx
RCASTDIR	=	raycast

#FILES
MLXLIB		=	libmlx.dylib
LIBS		=	$(LFTDIR)/libft.a $(MLXLIB)
INCS		=	-I $(LFTDIR) -I $(INCDIR) -I $(MLXDIR)
SRCS		=	$(SRCDIR)/main.c \
				$(SRCDIR)/$(PARSEDIR)/parse.c \
				$(SRCDIR)/$(PARSEDIR)/parse_map.c \
				$(SRCDIR)/$(PARSEDIR)/parse_texture_color.c \
				$(SRCDIR)/$(PARSEDIR)/parse_check.c \
				$(SRCDIR)/$(PARSEDIR)/parse_util.c \
				$(SRCDIR)/$(PARSEDIR)/basic_wall_check.c \
				$(SRCDIR)/$(PARSEDIR)/is_map_fully_closed.c \
				$(SRCDIR)/$(PARSEDIR)/check_spawn_location.c \
				$(SRCDIR)/$(PARSEDIR)/state_start_branch.c \
				$(SRCDIR)/$(PARSEDIR)/state_texture.c \
				$(SRCDIR)/$(PARSEDIR)/state_empty.c \
				$(SRCDIR)/$(PARSEDIR)/state_color.c \
				$(SRCDIR)/$(PARSEDIR)/state_map.c \
				$(SRCDIR)/$(RCASTDIR)/play_start.c \
				$(SRCDIR)/$(RCASTDIR)/raycast.c \
				$(SRCDIR)/$(RCASTDIR)/mlx_util.c \
				$(SRCDIR)/$(RCASTDIR)/key_hook.c \
				$(SRCDIR)/$(UTILDIR)/print_err_and_exit.c

ifdef IF_DEBUG
	CFLAGS += $(DFLAGS)
endif

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

OBJS		=	${SRCS:.c=.o}

$(NAME) : $(OBJS)
	@$(MAKE) -C $(MLXDIR)
	@cp $(MLXDIR)/$(MLXLIB) .
	@$(MAKE) -C $(LFTDIR) libft.a
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean :
	@$(MAKE) -C $(MLXDIR) clean
	@$(RM) $(MLXLIB)
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
