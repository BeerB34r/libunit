FIB_TESTS		= $(addprefix fib/, 00_launcher.c 01_basic.c 02_negative.c 03_bignum.c)
PUTS_TESTS		= $(addprefix puts/, 00_launcher.c 01_basic.c 02_null.c 03_bigger_string.c)
STRLEN_TESTS	= $(addprefix strlen/, 00_launcher.c 01_basic.c 02_null.c 03_bigger_string.c)
TESTS			= $(STRLEN_TESTS) $(PUTS_TESTS) $(FIB_TESTS)
FUNCTIONS		= $(addprefix functions/, ft_strlen.c puts.c fib.c)
MAIN			= main.c
LIBS			= ../framework/libunit.a ../framework/lib/libft/libft.a
LDFLAGS			= $(LIBS) -lm
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I../framework/inc/ -I../framework/lib/libft/include/
.PHONY			: all test run

all: test

test: run

compile: $(LIBS) $(TESTS:.c=.o) $(FUNCTIONS:.c=.o) $(MAIN:.c=.o)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(MAIN) $(TESTS) $(FUNCTIONS) $(LDFLAGS) 
run: compile
	./test

%.o	: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

../framework/libunit.a:
	$(MAKE) -C ../framework
../framework/lib/libft/libft.a:
	$(MAKE) -C ../framework/lib/libft/

re:
	$(RM) $(LIBS) $(TESTS:.c=.o) $(FUNCTIONS:.c=.o) $(MAIN:.c=.o)
	$(MAKE)
