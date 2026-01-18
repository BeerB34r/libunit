PRINTF_TESTS = $(addprefix printf/, 00_launcher.c 01_basic.c 02_cflag.c 03_sflag.c  \
                  04_dflag.c 05_iflag.c 06_uflag.c 07_pflag.c 08_xlflag.c 09_xuflag.c \
				  10_perflag.c 11_mixed.c)
TESTS			= $(PRINTF_TESTS)
FUNCTIONS		= $(addprefix functions/printf/, printf.c printf_utils.c)
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
