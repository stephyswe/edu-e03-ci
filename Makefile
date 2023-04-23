PROG=programmet.exe
TEST=check.exe
SOURCES=main.c calculator.c shapes.c input.c shapesfunc.c
DEPS=shapes.h calculator.h input.h
CC=gcc
CFLAGS=-Wall -Werror
DEBUG?=1
GTEST = gtest
LIBGTEST = C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=programmet-debug.exe
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif

OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@del /q "$(OUTPUTDIR)"
	@del /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

$(TEST): input.o TestShapes.o calculator.o shapesfunc.o
	g++ -o $@ $^ $(CFLAGS) -I $(GTEST)  $(LIBGTEST)

test: $(TEST)
	./$(TEST)

.PHONY: clean test