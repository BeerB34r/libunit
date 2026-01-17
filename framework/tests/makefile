CPPFLAGS	= -I../inc/

all: test

test:
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ main.c functions/ft_strlen.c strlen/*.c ../libunit.a ../lib/libft/libft.a -lm
