CC = gcc
FLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes

SRCS	= ${SRCDIR}/ft_putchar.c ${SRCDIR}/ft_swap.c ${SRCDIR}/ft_putstr.c ${SRCDIR}/ft_strlen.c ${SRCDIR}/ft_strcmp.c

OBJS	=  ${SRCS:.c=.o}

TARGET = libft.a

all: $(TARGET)

%.o: %.c 
	$(CC) $(FLAGS) -I$(INCDIR) -c $< -o $@ 
$(TARGET) : $(OBJS)
	ar -rcs $(TARGET) $(OBJS)

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(TARGET)

re : fclean all
