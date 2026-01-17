FT_PRINTF_TESTS = $(addprefix ft_printf/, 00_launcher.c 01_basic.c 02_cflag.c)
TESTS			= $(FT_PRINTF_TESTS)
FUNCTIONS		= $(addprefix functions/ft_printf/, ft_printf.c ft_printf_utils.c)
MAIN			= main.c
LIBS			= ../libunit.a ../lib/libft/libft.a
LDFLAGS			= $(LIBS) -lm
CFLAGS			= -Wall -Wextra -Werror -g 
CPPFLAGS		= -I../inc/ -I../lib/libft/include/
.PHONY			: all test

all: test

test: $(LIBS) $(TESTS:.c=.o) $(FUNCTIONS:.c=.o) $(MAIN:.c=.o)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $(MAIN) $(TESTS) $(FUNCTIONS) $(LDFLAGS) 

%.o	: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

../libunit.a:
	$(MAKE) -C ../
../lib/libft/libft.a:
	$(MAKE) -C ../lib/libft/

re:
	$(RM) $(LIBS) $(TESTS:.c=.o) $(FUNCTIONS:.c=.o) $(MAIN:.c=.o)
	$(MAKE)
