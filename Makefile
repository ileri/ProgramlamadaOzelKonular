CC              = gcc -std=c11 -Wall
AR              = ar rcs     # Kütüphane haline getir
RANLIB          = ranlib # Sıkıştır
OBJ             = src/matarith.o src/mattranspose.o src/fastfibo.o src/printmatrix.o src/stackproc.o
MAT_EXEC        = mattest
HANOI_EXEC      = hanoitest
STACK_EXEC      = stacktest
BRANCH_PRE_EXEC = branchpre
ARG_LIBDIR = -L./src
all: lib test

lib: $(OBJ)     # Tüm objeleri
	$(AR)     src/libmatarith.a $^
	$(RANLIB) src/libmatarith.a

test: src/libmatarith.a
	$(CC) -o $(MAT_EXEC)     $(ARG_LIBDIR) test/matrix_test.c -lmatarith
	$(CC) -o $(HANOI_EXEC)   $(ARG_LIBDIR) test/hanoi_test.c  -lmatarith
	$(CC) -o $(STACK_EXEC)   $(ARG_LIBDIR) test/stack_test.c  -lmatarith
	$(CC) -o $(BRANCH_PRE_EXEC)            test/branch_prediction.c
	
clean:
	@rm -f src/*.o src/*.a $(HANOI_EXEC) $(MAT_EXEC) $(STACK_EXEC) $(BRANCH_PRE_EXEC)
