# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:34:34 by dthan             #+#    #+#              #
#*   Updated: 2019/10/30 09:19:04 by dthan            ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

#-----------------------------Updated: 21/2/202--------------------------------#

NAME=libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES=./

#<<<<<<<<<<GET_NEXT_LINE_PROJECT>>>>>>>>>#

GNL_SRCS=get_next_line/get_next_line.c

GNL_OBJ=get_next_line.o

#<<<<<<<<<<CTYPE.H>>>>>>>>>>#

CTYPE_SRCS=ctype/ft_isalpha.c \
ctype/ft_isdigit.c \
ctype/ft_isalnum.c \
ctype/ft_isascii.c \
ctype/ft_isprint.c \
ctype/ft_isspace.c \
ctype/ft_islower.c \
ctype/ft_isupper.c \
ctype/ft_toupper.c \
ctype/ft_tolower.c

CTYPE_OBJ=ft_isalpha.o \
ft_isdigit.o \
ft_isalnum.o \
ft_isascii.o \
ft_isprint.o \
ft_isspace.o \
ft_islower.o \
ft_isupper.o \
ft_toupper.o \
ft_tolower.o

#<<<<<<<<<<LIST.H>>>>>>>>>># NOTE: Optional

LIST_SRCS=list/ft_lstnew.c \
list/ft_lstdelone.c \
list/ft_lstdel.c \
list/ft_lstadd.c \
list/ft_lstiter.c \
list/ft_lstmap.c

LIST_OBJ=ft_lstnew.o \
ft_lstdelone.o \
ft_lstdel.o \
ft_lstadd.o \
ft_lstiter.o \
ft_lstmap.o

#<<<<<<<<<<PRINT.H>>>>>>>>>># NOTE: Optional

PRINT_SRCS=print/ft_putchar.c \
print/ft_putstr.c \
print/ft_putendl.c \
print/ft_putnbr.c \
print/ft_putchar_fd.c \
print/ft_putstr_fd.c \
print/ft_putendl_fd.c \
print/ft_putnbr_fd.c

PRINT_OBJ=ft_putchar.o \
ft_putstr.o \
ft_putendl.o \
ft_putnbr.o \
ft_putchar_fd.o \
ft_putstr_fd.o \
ft_putendl_fd.o \
ft_putnbr_fd.o

#<<<<<<<<<<STDIO.H>>>>>>>>>>#

STDIO_SRCS=

STDIO_OBJ=

#<<<<<<<<<<PRINTF_H>>>>>>>>>>#

PRINTF_SRCS_DIR=stdio/ft_printf/

PRINTF_SRCS=$(addprefix $(PRINTF_SRCS_DIR)/, core.c parsing.c printing.c \
parsing/fill_struct.c parsing/parsing_helper.c \
printing/nbr_to_str.c printing/width_control.c printing/percision_control.c \
printing/flag_control.c printing/printing_helper.c \
printing/type_c.c printing/type_di.c printing/type_f.c printing/type_o.c \
printing/type_p.c printing/type_s.c printing/type_u.c printing/type_hex.c \
printing/type_percent.c)

PRINTF_OBJ=core.o parsing.o printing.o \
fill_struct.o parsing_helper.o \
nbr_to_str.o width_control.o percision_control.o flag_control.o \
printing_helper.o \
type_c.o type_di.o type_f.o type_o.o type_p.o type_s.o type_u.o type_hex.o \
type_percent.o \

#<<<<<<<<<<STDLIB.H>>>>>>>>>>#

STDLIB_SRCS=stdlib/ft_atoi.c

STDLIB_OBJ=ft_atoi.o

#<<<<<<<<<<STRING.H>>>>>>>>>>#

STRING_SRCS=string/ft_memset.c \
string/ft_bzero.c \
string/ft_memcpy.c \
string/ft_memccpy.c \
string/ft_memmove.c \
string/ft_memchr.c \
string/ft_memcmp.c \
string/ft_strlen.c \
string/ft_strdup.c \
string/ft_strcpy.c \
string/ft_strncpy.c \
string/ft_strcat.c \
string/ft_strncat.c \
string/ft_strlcat.c \
string/ft_strchr.c \
string/ft_strrchr.c \
string/ft_strstr.c \
string/ft_strnstr.c \
string/ft_strcmp.c \
string/ft_strncmp.c

STRING_OBJ=ft_memset.o \
ft_bzero.o \
ft_memcpy.o \
ft_memccpy.o \
ft_memmove.o \
ft_memchr.o \
ft_memcmp.o \
ft_strlen.o \
ft_strdup.o \
ft_strcpy.o \
ft_strncpy.o \
ft_strcat.o \
ft_strncat.o \
ft_strlcat.o \
ft_strchr.o \
ft_strrchr.o \
ft_strstr.o \
ft_strnstr.o \
ft_strcmp.o \
ft_strncmp.o

#<<<<<<<<<<UTILITY.H>>>>>>>>>># NOTE: Optional

UTILITY_SRCS=utility/ft_memalloc.c \
utility/ft_memdel.c \
utility/ft_strnew.c \
utility/ft_strdel.c \
utility/ft_strclr.c \
utility/ft_striter.c \
utility/ft_striteri.c \
utility/ft_strmap.c \
utility/ft_strmapi.c \
utility/ft_strequ.c \
utility/ft_strnequ.c \
utility/ft_strsub.c \
utility/ft_strjoin.c \
utility/ft_strtrim.c \
utility/ft_strsplit.c \
utility/ft_swap.c \
utility/ft_ctwords.c \
utility/ft_itoa.c \
utility/ft_strjoin_and_free.c \
utility/ft_itoa_signed_and_unsigned_long_long.c \
utility/ft_strrev.c

UTILITY_OBJ=ft_memalloc.o \
ft_memdel.o \
ft_strnew.o \
ft_strdel.o \
ft_strclr.o \
ft_striter.o \
ft_striteri.o \
ft_strmap.o \
ft_strmapi.o \
ft_strequ.o \
ft_strnequ.o \
ft_strsub.o \
ft_strjoin.o \
ft_strtrim.o \
ft_strsplit.o \
ft_swap.o \
ft_ctwords.o \
ft_itoa.o \
ft_strjoin_and_free.o \
ft_itoa_signed_and_unsigned_long_long.o \
ft_strrev.o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I$(INCLUDES) -c $(CTYPE_SRCS) $(LIST_SRCS) $(PRINT_SRCS) $(STDIO_SRCS) $(STDLIB_SRCS) \
	$(STRING_SRCS) $(UTILITY_SRCS) $(GNL_SRCS) $(PRINTF_SRCS)
	@ar rc $(NAME) $(CTYPE_OBJ) $(LIST_OBJ) $(PRINT_OBJ) $(STDIO_OBJ) $(STDLIB_OBJ) $(STRING_OBJ) \
	$(UTILITY_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	@ranlib $(NAME)
	@echo "\033[32mCreated LIBFT library\033[0m"

clean:
	@/bin/rm -f $(CTYPE_OBJ) $(LIST_OBJ) $(PRINT_OBJ) $(STDIO_OBJ) $(STDLIB_OBJ) $(STRING_OBJ) \
	$(UTILITY_OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
	@echo "\033[32mRemoved Object files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[32mRemoved LIBFT library\033[0m"

re: fclean all

.PHONY: all clean fclean re