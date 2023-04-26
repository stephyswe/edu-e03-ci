PROG=programmet.exe
TEST=check.exe
SOURCES=main.c calculator.c shapes.c input.c shapesfunc.c game.c gamefunc.c
DEPS=shapes.h calculator.h input.h game.h gamefunc.h
CC=gcc
CXX=g++
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

TESTDIR=bin/test
OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))
TESTOBJS = $(addprefix $(TESTDIR)/, TestShapes.o TestCalc.o TestGame.o shapesfunc.o calculator.o game.o gamefunc.o input.o)

$(PROG): $(OUTPUTDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@del /q "$(OUTPUTDIR)"
	@del /q "$(TESTDIR)"
	@del /q $(PROG) $(TEST)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

$(TESTDIR):
	@mkdir "$(TESTDIR)"

$(TEST): $(TESTOBJS)
	$(CXX) -o $@ $^ $(CFLAGS) -I $(GTEST) $(LIBGTEST)

test: $(TEST)
	./$(TEST)

$(TESTDIR)/%.o: %.c $(DEPS) | $(TESTDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(TESTDIR)/%.o: %.cpp $(DEPS) | $(TESTDIR)
	$(CXX) $(CFLAGS) -o $@ -c $<

$(TESTDIR)/TestCalc.o: TestCalc.cpp $(DEPS) | $(TESTDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean test
