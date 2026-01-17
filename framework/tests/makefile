PUTS_TESTS		= $(addprefix puts/, 00_launcher.c 01_basic.c 02_null.c 03_bigger_string.c)
STRLEN_TESTS	= $(addprefix strlen/, 00_launcher.c 01_basic.c 02_null.c 03_bigger_string.c)
TESTS			= $(STRLEN_TESTS) $(PUTS_TESTS)
FUNCTIONS		= functions/ft_strlen.c functions/puts.c
MAIN			= main.c
LIBS			= ../libunit.a ../lib/libft/libft.a
LDFLAGS			= $(LIBS) -lm
CFLAGS			= -Wall -Wextra -Werror -g 
CPPFLAGS		= -I../inc/ -I../lib/libft/include/
.PHONY			: all test

all: test

test: $(LIBS) $(TESTS:.c=.o) $(FUNCTIONS:.c=.o) $(MAIN:.c=.o)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(MAIN) $(TESTS) $(LDFLAGS) 

%.o	: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

../libunit.a:
	$(MAKE) -C ../
../lib/libft/libft.a:
	$(MAKE) -C ../lib/libft/

re:
	$(RM) $(LIBS) $(TESTS:.c=.o) $(FUNCTIONS:.c=.o) $(MAIN:.c=.o)
	$(MAKE)
