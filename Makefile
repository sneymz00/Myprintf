NAME 		= 		libftprintf.a
LIB 		= 		ar -rcs
RM 			= 		rm -f

###############################################################################
#									COMPILER								  #
###############################################################################

CC 		= 		gcc
CCFLAGS	= 		-Wall -Wextra -Werror

###############################################################################
#									SRC										  #
###############################################################################

SRC 	= 		ft_putstr.c ft_putdecimal.c ft_hexadecimal.c ft_printf.c

OBJ 	= 		$(SRC:.c=.o)

###############################################################################
#						          SRC BONUS			   						  #
###############################################################################

BONUSSRC = 

BONUSOBJ = $(BONUSSRC:.c=.o)

###############################################################################
#									INLUDES									  #
###############################################################################

INCLUDE = 		ft_printf.h

###############################################################################
#									RULES									  #
###############################################################################

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE) Makefile
	$(LIB) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ) $(INCLUDE)
	$(LIB) $(NAME) $(BONUSOBJ) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
