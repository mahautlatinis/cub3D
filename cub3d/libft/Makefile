INC_DIR		= .
SRC_DIR		= .

M_NAMES		= 	atoi.c bzero.c calloc.c inrange.c isalnum.c isalpha.c isascii.c \
				isdigit.c isprint.c itoa.c memccpy.c memchr.c memcmp.c \
				memcpy.c memmove.c memset.c putchar_fd.c putendl_fd.c \
				putnbr_fd.c putstr_fd.c split.c strchr.c strdup.c strjoin.c \
				strlcat.c strlcpy.c strlen.c strmapi.c strncmp.c strnstr.c \
				strrchr.c strtrim.c substr.c tolower.c toupper.c gnl.c strcmp.c \
				lstnew.c lstadd_front.c lstsize.c lstlast.c lstadd_back.c \
				lstdelone.c lstclear.c lstiter.c lstmap.c
M_SRCS		= $(addprefix $(SRC_DIR)/ft_, $(M_NAMES))

M_OBJS		= $(M_SRCS:.c=.o)

NAME		= libft.a

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

AR			= ar -rc

RM			= rm -f

RL			= ranlib

.c.o:
			$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(M_OBJS)
			$(AR) $(NAME) $(M_OBJS)
			$(RL) $(NAME)

all:		$(NAME)

clean:
			$(RM) $(M_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
