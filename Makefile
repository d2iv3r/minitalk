# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:04:21 by efarhat           #+#    #+#              #
#    Updated: 2023/01/18 15:45:21 by efarhat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

LIB_PRINTF = ft_printf/libftprintf.a

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

S_SRC = server.c
C_SRC = client.c ft_atoi.c ft_isdigit.c
S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)

BS_SRC = server_bonus.c ft_bzero.c
BC_SRC = client_bonus.c ft_atoi.c ft_isdigit.c ft_strlen.c
BS_OBJ = $(BS_SRC:.c=.o)
BC_OBJ = $(BC_SRC:.c=.o)

all : $(LIB_PRINTF) $(SERVER) $(CLIENT)

bonus : $(LIB_PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER) : $(S_OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIB_PRINTF) $(S_OBJ) -o $@
	
$(CLIENT) : $(C_OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIB_PRINTF) $(C_OBJ) -o $@

$(SERVER_BONUS) : $(BS_OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIB_PRINTF) $(BS_OBJ) -o $@
	
$(CLIENT_BONUS) : $(BC_OBJ) minitalk.h
	$(CC) $(CFLAGS) $(LIB_PRINTF) $(BC_OBJ) -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
$(LIB_PRINTF) :
	$(MAKE) -C ft_printf

clean : 
	$(MAKE) clean -C ft_printf
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ft_printf
	rm -rf $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re : fclean all bonus

.PHONY : clean all fclean re bonus
