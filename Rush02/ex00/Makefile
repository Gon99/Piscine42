SRCS = main.c manage_file.c nbr_to_text.c nbr_to_text_funcs.c print.c utils_1.c utils_2.c
OBJS = ${SRCS:.c=.o}
NAME = rush-02
CC = cc
rm = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	rm ${OBJS}

fclean: clean
	${RM} ${NAME}
