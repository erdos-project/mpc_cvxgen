# Produced by CVXGEN, 2020-03-22 19:57:34 -0400.
# CVXGEN is Copyright (C) 2006-2017 Jacob Mattingley, jem@cvxgen.com.
# The code in this file is Copyright (C) 2006-2017 Jacob Mattingley.
# CVXGEN, or solvers produced by CVXGEN, cannot be used for commercial
# applications without prior written permission from Jacob Mattingley.

# Filename: Makefile.
# Description: Basic Makefile.
OPT = -Wall -Os
# libmath is needed for sqrt, which is used only for reporting the gap. Can
# remove if desired for production solvers..
LDLIBS = -lm
CFLAGS = $(OPT) $(INCLUDES) -fPIC -g
CC = gcc
.PHONY: all
all: testsolver applysolver.so
testsolver: solver.o matrix_support.o ldl.o testsolver.o util.o
# Include util.o for random functions and easy matrix printing.
#testsolver: solver.o matrix_support.o ldl.o util.o testsolver.o
solver.o: solver.h
matrix_support.o: solver.h
ldl.o: solver.h
util.o: solver.h
testsolver.o: solver.h
applysolver.o: solver.h
applysolver.so: applysolver.o solver.o matrix_support.o ldl.o testsolver.o util.o
	$(CC) -shared $^ -o $@
.PHONY : clean
clean :
	-rm -f *.o *.so testsolver
