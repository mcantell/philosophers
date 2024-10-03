NAME 		= philo

PHILO_DIR 	= ./srcs
PHILO_INC 	=  ./include

SRCS		=	main.c main_utils.c check_arguments.c check_arguments_1.c one_philo.c table.c\

OBJ 		= $(patsubst %.c, $(PHILO_DIR)/%.o, $(SRCS))

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
RM 			= rm -f

INC 		= -I$(PHILO_INC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(PHILO_DIR)/%.o: $(PHILO_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all fclean clean re
