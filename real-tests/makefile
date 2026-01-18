F_KO			= $(addprefix KO/, 00_launcher.c 01_return.c 02_stdout_capture.c)
F_OK			= $(addprefix OK/, 00_launcher.c 01_return.c 02_stdout_capture.c)
FRAMEWORK_TESTS	= $(addprefix framework/, 00_launcher.c $(F_OK) $(F_KO) $(F_SEGV) $(F_BUS) $(F_ABRT) $(F_FPE) $(F_PIPE) $(F_ILL) $(F_TIME))
TESTS			= $(FRAMEWORK_TESTS)
MAIN			= main.c
LIBS			= ../framework/libunit.a ../framework/lib/libft/libft.a
LDFLAGS			= $(LIBS) -lm
CFLAGS			= -Wall -Wextra -Werror -g 
CPPFLAGS		= -I../framework/inc/ -I../framework/lib/libft/include/
.PHONY			: all test

all: test

test: $(LIBS) $(TESTS:.c=.o) $(MAIN:.c=.o)
	$(CC) $(CFLAGS) -o $@ $(MAIN:.c=.o) $(TESTS:.c=.o) $(LDFLAGS) 

%.o	: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

../framework/libunit.a:
	$(MAKE) -C ../framework
../framework/lib/libft/libft.a:
	$(MAKE) -C ../framework/lib/libft/

re:
	$(RM) $(LIBS) $(TESTS:.c=.o) $(FUNCTIONS:.c=.o) $(MAIN:.c=.o)
	$(MAKE)
