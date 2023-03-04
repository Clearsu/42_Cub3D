# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 18:00:49 by jincpark          #+#    #+#              #
#    Updated: 2023/03/04 16:59:27 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME
NAME		=	cub3d

#CMDS
CC			=	cc
RM			=	rm -f
LIBC		=	ar rcs

#FLAGS
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-g3 -fsanitize=address
MLXFLAGS 	= 	-lmlx -L. -framework OpenGL -framework Appkit


#DIRS
LFTDIR		=	libft
MAN_DIR		=	mandatory
BNS_DIR		=	bonus
SRCDIR		=	srcs
PARSEDIR	=	parse_map
UTILDIR		=	util
INCDIR		=	incs
MLXDIR 		= 	minilibx
RCASTDIR	=	raycast
EVENTDIR	=	event

#FILES
MLXLIB		=	libmlx.dylib
LIBS		=	$(LFTDIR)/libft.a $(MLXLIB)
INCS		=	-I $(LFTDIR) -I $(MLXDIR)

MAN_INCS	=	-I $(MAN_DIR)/$(INCDIR)
MAN_SRCS	=	$(MAN_DIR)/$(SRCDIR)/main.c \
				$(MAN_DIR)/$(SRCDIR)/play_start.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/parse.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_map.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_texture_color.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_check.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_util.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/basic_wall_check.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/is_map_fully_closed.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/check_spawn_location.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/state_start_branch.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/state_texture.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/state_empty.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/state_color.c \
				$(MAN_DIR)/$(SRCDIR)/$(PARSEDIR)/state_map.c \
				$(MAN_DIR)/$(SRCDIR)/$(RCASTDIR)/get_texture_info.c \
				$(MAN_DIR)/$(SRCDIR)/$(RCASTDIR)/raycast.c \
				$(MAN_DIR)/$(SRCDIR)/$(RCASTDIR)/draw_line.c \
				$(MAN_DIR)/$(SRCDIR)/$(RCASTDIR)/get_delta_side_dist.c \
				$(MAN_DIR)/$(SRCDIR)/$(RCASTDIR)/mlx_util.c \
				$(MAN_DIR)/$(SRCDIR)/$(EVENTDIR)/key_hook.c \
				$(MAN_DIR)/$(SRCDIR)/$(EVENTDIR)/move.c \
				$(MAN_DIR)/$(SRCDIR)/$(EVENTDIR)/rotate.c \
				$(MAN_DIR)/$(SRCDIR)/$(UTILDIR)/print_err_and_exit.c

BNS_INCS	=	-I $(BNS_DIR)/$(INCDIR)
BNS_SRCS	=	$(BNS_DIR)/$(SRCDIR)/main_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/play_start_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/minimap_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/crosshair_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/get_png_info_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_map_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_texture_color_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_check_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/parse_util_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/basic_wall_check_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/is_map_fully_closed_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/check_spawn_location_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/state_start_branch_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/state_texture_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/state_empty_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/state_color_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(PARSEDIR)/state_map_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(RCASTDIR)/raycast_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(RCASTDIR)/draw_line_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(RCASTDIR)/get_delta_side_dist_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(RCASTDIR)/enemy_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(RCASTDIR)/mlx_util_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(EVENTDIR)/key_hook_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(EVENTDIR)/move_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(EVENTDIR)/rotate_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(EVENTDIR)/door_bonus.c \
				$(BNS_DIR)/$(SRCDIR)/$(UTILDIR)/print_err_and_exit_bonus.c

ifdef IF_DEBUG
	CFLAGS += $(DFLAGS)
endif

ifdef IF_BONUS
	OBJS = $(BNS_OBJS)
	INCS += $(BNS_INCS)
else
	OBJS = $(MAN_OBJS)
	INCS += $(MAN_INCS)
endif

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

MAN_OBJS	=	${MAN_SRCS:.c=.o}
BNS_OBJS	=	${BNS_SRCS:.c=.o}

$(NAME) : $(OBJS)
	@$(MAKE) -C $(MLXDIR)
	@cp $(MLXDIR)/$(MLXLIB) .
	@$(MAKE) -C $(LFTDIR) libft.a
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean :
	@$(MAKE) -C $(MLXDIR) clean
	@$(RM) $(MLXLIB)
	@$(MAKE) -C $(LFTDIR) fclean
	$(RM) $(MAN_OBJS) $(BNS_OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

rebug :
	$(MAKE) fclean
	$(MAKE) IF_DEBUG=1 all

bonus :
	$(MAKE) IF_BONUS=1 all

bdebug :
	$(MAKE) IF_BONUS=1 IF_DEBUG=1 all

brebug :
	$(MAKE) fclean
	$(MAKE) IF_BONUS=1 IF_DEBUG=1 all

.PHONY : all clean fclean re bonus bdebug brebug
