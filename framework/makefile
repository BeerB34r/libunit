SRC				=	load_test.c create_ctx.c free_ctx.c get_last.c status.c
SRCDIR			:=	src/
BIN				=	$(addprefix $(BINDIR),$(SRC:.c=.o))
BINDIR			:=	bin/
DEP				=	$(addprefix $(DEPDIR),$(SRC:.c=.d))
DEPDIR			:=	dep/
DEPFLAG			=	-MM -MF $@ -MT $@ -MT $(BINDIR)$(notdir $(basename $<)).o
INC				=	-Iinc/
VPATH			=	$(SRCDIR)
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	$(INC)
LDFLAGS			:=
CC				:=	cc
RM				:=	rm -fr
AR				:=	ar rcs
NAME			:=	libunit.a

MAKEFLAGS		+=	-r --no-print-directory -j
.EXTRA_PREREQS	=	$(firstword $(MAKEFILE_LIST))
.DEFAULT_GOAL	=	all
.PRECIOUS		:	$(BINDIR) $(DEPDIR)
.PHONY			:	clean fclean re all

-include $(DEP)

all				:	$(NAME)

$(NAME)			:	$(BIN)
	$(AR) $@ $?

$(DEPDIR)%.d	:	%.c | $(DEPDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAG) $<
$(BINDIR)%.o	:	%.c | $(BINDIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%/				:
	mkdir -p $@

clean			:
	$(RM) $(BINDIR)
fclean			:
	$(RM) $(BINDIR)
	$(RM) $(NAME) $(DEPDIR)
re				:
	+$(MAKE) fclean
	+$(MAKE) all
