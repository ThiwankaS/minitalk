CMD = gcc
CFLAGS = -Wall -Wextra -Werror -I.

TARGET_LIBFTA = libft.a
TARGET_PRINTF = libftprintf.a
TARGET_SERVER = server
TARGET_CLIENT = client

SRC_LIBFTA = \
	ft_libft/ft_atoi.c\
	ft_libft/ft_bzero.c\
	ft_libft/ft_calloc.c\
	ft_libft/ft_isalnum.c\
	ft_libft/ft_isalpha.c\
	ft_libft/ft_isascii.c\
	ft_libft/ft_isdigit.c\
	ft_libft/ft_isprint.c\
	ft_libft/ft_itoa.c\
	ft_libft/ft_memchr.c\
	ft_libft/ft_memcmp.c\
	ft_libft/ft_memcpy.c\
	ft_libft/ft_memmove.c\
	ft_libft/ft_memset.c\
	ft_libft/ft_putchar_fd.c\
	ft_libft/ft_putendl_fd.c\
	ft_libft/ft_putnbr_fd.c\
	ft_libft/ft_putstr_fd.c\
	ft_libft/ft_split.c\
	ft_libft/ft_strchr.c\
	ft_libft/ft_strdup.c\
	ft_libft/ft_striteri.c\
	ft_libft/ft_strjoin.c\
	ft_libft/ft_strlcat.c\
	ft_libft/ft_strlcpy.c\
	ft_libft/ft_strlen.c\
	ft_libft/ft_strmapi.c\
	ft_libft/ft_strncmp.c\
	ft_libft/ft_strnstr.c\
	ft_libft/ft_strrchr.c\
	ft_libft/ft_strtrim.c\
	ft_libft/ft_substr.c\
	ft_libft/ft_tolower.c\
	ft_libft/ft_toupper.c
SRC_PRINTF = \
	ft_printf/ft_helper.c\
	ft_printf/ft_pointer.c\
	ft_printf/ft_putnbr_base.c\
	ft_printf/ft_printf.c
SRC_SERVER = \
	server.c\
	utilities.c
SRC_CLIENT = \
	client.c\
	utilities.c

OBJ_LIBFTA = $(SRC_LIBFTA:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

HEADER = minitalk.h ft_printf.h libft.h

all : $(TARGET_LIBFTA) $(TARGET_PRINTF) $(TARGET_SERVER) $(TARGET_CLIENT)

$(TARGET_LIBFTA) : $(OBJ_LIBFTA)
	ar rcs $(TARGET_LIBFTA) $(OBJ_LIBFTA)

$(TARGET_PRINTF) : $(OBJ_PRINTF)
	ar rcs $(TARGET_PRINTF) $(OBJ_PRINTF)

$(TARGET_SERVER) : $(OBJ_SERVER) $(TARGET_LIBFTA) $(TARGET_PRINTF)
	$(CMD) $(CFLAGS) -o $@ $^

$(TARGET_CLIENT) : $(OBJ_CLIENT) $(TARGET_LIBFTA) $(TARGET_PRINTF)
	$(CMD) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CMD) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_LIBFTA) $(OBJ_PRINTF) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean : clean
	rm -rf $(TARGET_LIBFTA) $(TARGET_PRINTF) $(TARGET_SERVER) $(TARGET_CLIENT)

re : fclean all

.PHONY: all clean fclean re
