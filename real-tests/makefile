# FRAMEWORK SECTION
F_ERR			= $(addprefix ERR/, 00_launcher.c 01_return.c 02_stdout_capture.c) 10_err.c
F_BUS			= $(addprefix BUS/, 00_launcher.c 01_return.c 02_stdout_capture.c) 04_bus.c
F_ABRT			= $(addprefix ABRT/, 00_launcher.c 01_return.c 02_stdout_capture.c) 05_abrt.c
F_FPE			= $(addprefix FPE/, 00_launcher.c 01_return.c 02_stdout_capture.c) 06_fpe.c
F_PIPE			= $(addprefix PIPE/, 00_launcher.c 01_return.c 02_stdout_capture.c) 07_pipe.c
F_ILL			= $(addprefix ILL/, 00_launcher.c 01_return.c 02_stdout_capture.c) 08_ill.c
F_TIME			= $(addprefix TIME/, 00_launcher.c 01_return.c 02_stdout_capture.c) 09_time.c
F_SEGV			= $(addprefix SEGV/, 00_launcher.c 01_return.c 02_stdout_capture.c) 03_segv.c
F_KO			= $(addprefix KO/, 00_launcher.c 01_return.c 02_stdout_capture.c) 02_ko.c
F_OK			= $(addprefix OK/, 00_launcher.c 01_return.c 02_stdout_capture.c) 01_ok.c
FRAMEWORK_TESTS	= $(addprefix framework/, 00_launcher.c $(F_OK) $(F_KO) $(F_SEGV) $(F_BUS) $(F_ABRT) $(F_FPE) $(F_PIPE) $(F_ILL) $(F_TIME) $(F_ERR))

# PRINTF SECTION
PRINTF_TESTS	= $(addprefix printf/, 00_launcher.c 01_basic.c 02_cflag.c 03_sflag.c 04_dflag.c 05_iflag.c 06_uflag.c 07_pflag.c 08_xlflag.c 09_xuflag.c 10_perflag.c 11_mixed.c)

# REST OF THE OWL
TESTS			= $(FRAMEWORK_TESTS) $(PRINTF_TESTS)
MAIN			= main.c
LIBS			= ../framework/libunit.a ../framework/lib/libft/libft.a
LDFLAGS			= $(LIBS) -lm
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I../framework/inc/ -I../framework/lib/libft/include/
.PHONY			: all test run

all: test

test: compile run

run:
	./test
compile: $(LIBS) $(TESTS:.c=.o) $(MAIN:.c=.o)
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
