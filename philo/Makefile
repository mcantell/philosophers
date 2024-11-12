NAME 		= philo

PHILO_DIR 	= ./srcs
PHILO_INC 	=  ./include

SRCS		=	main.c main_utils.c check_arguments.c check_arguments_1.c one_philo.c init.c routine.c action.c observer.c \

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

test: re
	rm -f $(OBJ)
	clear
	echo /$(NAME)
	-./$(NAME)
	echo
	echo ./$(NAME) 0 800 200 200
	-./$(NAME) 0 800 200 200
	echo
	echo ./$(NAME) 2 0 200 200
	-./$(NAME) 2 0 200 200
	echo
	echo ./$(NAME) 2 800 0 200
	-./$(NAME) 2 800 0 200
	echo
	echo ./$(NAME) 2 800 200 0
	-./$(NAME) 2 800 200 0
	echo
	echo ./$(NAME) 0 0 0 0
	-./$(NAME) 0 0 0 0
	echo
	echo ./$(NAME) 2 800 200 0
	-./$(NAME) 2 800 200 0
	echo
	echo ./$(NAME) 0 0 0 0 0
	-./$(NAME) 0 0 0 0 0
	@rm -f $(NAME)

test2: re
	rm -f $(OBJ)
	clear
	echo valgrind --leak-check=full ./$(NAME) $(ARGS)
	valgrind --leak-check=full ./$(NAME) $(ARGS)
	@echo Norminette error:
	norminette | grep Error! | wc -l
	@echo
# @leaks -atExit -- ./$(NAME) $(ARGS) > temp.txt
# cat temp.txt | grep "total leaked bytes."
# rm temp.txt
	@rm -f $(NAME)

test3: re
	rm -f $(OBJ)
	clear
	echo ./$(NAME) $(ARGS)
	./$(NAME) $(ARGS)
	@rm -f $(NAME)

# ARGS = 200 800 200 200

#ARGS = 1 800 200 200 #no eat, dies
# ARGS = 5 800 200 200 #no dies ever
# ARGS = 5 800 200 200 7 #no dies, but finish at eat 7
# ARGS = 4 410 200 200 #no dies ever
ARGS = 4 310 200 100 #one philo dies

# ARGS = 2 800 200 200 #no dies ever
# ARGS = 2 800 200 200 7 #no dies, but finish at eat 7
# ARGS = 2 410 200 200 #no dies ever
# ARGS = 2 310 200 100 #uno philo dies


.PHONY: all fclean clean re test test2 test3
