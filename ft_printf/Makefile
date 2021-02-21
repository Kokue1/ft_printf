NAME = libftprintf.a

SOURCE = 	srcs/ft_printf.c\
			\
			srcs/Flags/flags.c\
			srcs/Flags/ft_minus_flags.c\
			srcs/Flags/ft_zero_flags.c\
			\
			srcs/Precision/precision.c\
			\
			srcs/Verify_ALL/ft_verify_everything.c\
			srcs/Verify_ALL/initialize.c\
			\
			srcs/Width/width.c\
			\
			srcs/Write/write_char.c\
			srcs/Write/write_percen.c\
			srcs/Write/write_string_nulls.c\
			srcs/Write/write_string.c\
			srcs/Write/write_pointer.c\
			srcs/Write/write_pointer_width.c\
			srcs/Write/write_int_rnd.c\
			srcs/Write/write_integer.c\
			\
			srcs/libft_extra/ft_strjoinchr.c\

SOURCES_O = ft_printf.o\
			\
			flags.o\
			ft_minus_flags.o\
			ft_zero_flags.o\
			\
			precision.o\
			\
			ft_verify_everything.o\
			initialize.o\
			\
			width.o\
			\
			write_char.o\
			write_percen.o\
			write_string_nulls.o\
			write_string.o\
			write_pointer.o\
			write_pointer_width.o\
			write_int_rnd.o\
			write_integer.o\
			\
			ft_strjoinchr.o\

OBJS = $(SOURCE:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -c -Wall -Werror -Wextra
INCLUDES = -I./includes

all : $(NAME)

$(NAME) :	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(FLAGS) $(INCLUDES) $(SOURCE)
			ar -rcs $(NAME) $(OBJS)

clean :
			$(MAKE) clean -C ./libft
			$(RM) $(SOURCES_O)
			$(RM) $(OBJS)

fclean :
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME)

re :		fclean all
