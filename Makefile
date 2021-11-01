LIBFT_DIR	=	libft

MANDA_DIR	=	manda
MANDA_INC	=	${MANDA_DIR}/includes
MANDA_NAMES	=	cub_parser/cub_data.c \
				cub_parser/cub_parser.c \
				cub_parser/cub_parser_extra.c \
				cub_parser/cub_to_map.c \
				cub_parser/utils.c \
				game/init_free.c \
				game/player_movements.c \
				graphics/draw.c \
				graphics/events.c \
				graphics/image_handlers.c \
				graphics/init_free.c \
				graphics/utils.c \
				ray_casting/calculate.c \
				ray_casting/math.c \
				ray_casting/ray_casting.c \
				main.c \
				misc.c
MANDA_SRCS	= $(addprefix $(MANDA_DIR)/, $(MANDA_NAMES))

BONUS_DIR		=	bonus
BONUS_INC		=	${BONUS_DIR}/includes
BONUS_COMMONS	= 	cub_parser/cub_data.c \
					cub_parser/cub_parser.c \
					cub_parser/cub_parser_extra.c \
					cub_parser/cub_to_map.c \
					cub_parser/utils.c \
					game/init_free.c \
					game/player_movements.c \
					graphics/draw.c \
					graphics/events_key.c \
					graphics/events_win.c \
					graphics/image_handlers.c \
					graphics/init_free.c \
					graphics/utils.c \
					minimap/minimap.c \
					minimap/minimap_utils.c \
					ray_casting/calculate.c \
					ray_casting/math.c \
					ray_casting/ray_casting.c \
					main.c \
					misc.c

ifeq ($(shell uname), Darwin)
MLX_DIR		=	mlx_mac
MLX_FLAGS	=	-framework OpenGL -framework AppKit
BONUS_NAMES =	$(BONUS_COMMONS) graphics/events_mouse_mac.c
else
MLX_DIR		=	mlx_linux
MLX_FLAGS	=	-lX11 -lXext -lm
BONUS_NAMES =	$(BONUS_COMMONS) graphics/events_mouse_linux.c
endif

LIB_FLAGS	= -L ${LIBFT_DIR} ${MLX_FLAGS} -lft -L ${MLX_DIR} -lmlx

BONUS_SRCS	= $(addprefix $(BONUS_DIR)/, $(BONUS_NAMES))

MANDA_OBJS	= ${MANDA_SRCS:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

NAME		= cub3D
BONUS_NAME	= cub3D_bonus

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${MANDA_OBJS}
			make -C ${MLX_DIR}
			make -C ${LIBFT_DIR}
			${CC} ${CFLAGS} -o ${NAME} ${MANDA_OBJS} ${LIB_FLAGS}

bonus:		${BONUS_OBJS}
			make -C ${MLX_DIR}
			make -C ${LIBFT_DIR}
			${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${LIB_FLAGS}

all:		${NAME}

clean:
			make -C ${LIBFT_DIR} clean
			make -C ${MLX_DIR} clean
			${RM} ${MANDA_OBJS} ${BONUS_OBJS}

fclean:		clean
			make -C ${LIBFT_DIR} fclean
			${RM} ${NAME} ${BONUS_NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
