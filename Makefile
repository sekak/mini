NAME = server
NAMECLT = client
Header = header.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = server.c  fuc_server.c
FILECLT = client.c  fuc_client.c

FILE_O = $(FILE:.c=.o)
FILECLT_O = $(FILECLT:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAMECLT) $(NAME)

$(NAMECLT) : $(FILECLT_O)
	$(CC) $(CFLAGS) $(FILECLT_O) -o $(NAMECLT)

$(NAME) : $(FILE_O)
	$(CC) $(CFLAGS) $(FILE_O) -o $(NAME)

clean: 
	$(RM) $(FILECLT_O) $(FILE_O)

fclean: clean
	$(RM) $(NAME) $(NAMECLT)

re: fclean all

bonus: re
	

.PHONY: all clean fclean re 