CC=gcc -Wall
INC=include
BIN=bin
LIB=lib
OBJ=obj
SRC=src

# Create necessary directories if they don't exist
$(shell mkdir -p $(BIN) $(OBJ) $(LIB))

# Default target
all: runstack

# build bin/stack_test
${OBJ}/stack_array.o: ${INC}/stack.h ${SRC}/stack_array.c
	${CC} -c -o ${OBJ}/stack_array.o ${SRC}/stack_array.c -I${INC}

${OBJ}/stack_test.o: ${INC}/stack.h ${SRC}/stack_test.c
	${CC} -c -o ${OBJ}/stack_test.o ${SRC}/stack_test.c -I${INC}

${BIN}/stack_test: ${OBJ}/stack_test.o ${OBJ}/stack_array.o
	${CC} -o ${BIN}/stack_test ${OBJ}/stack_test.o ${OBJ}/stack_array.o

# run stack_test
runstack: ${BIN}/stack_test
	echo "Testing Stack"
	${BIN}/stack_test


# build bin/libstack_test
${LIB}/libstack.a: ${OBJ}/stack_list.o ${OBJ}/list_impl.o
	ar rcv ${LIB}/libstack.a ${OBJ}/stack_list.o ${OBJ}/list_impl.o
	ranlib ${LIB}/libstack.a

${BIN}/libstack_test: ${OBJ}/stack_test.o ${LIB}/libstack.a
	${CC} -o ${BIN}/stack_test ${OBJ}/stack_test.o -L${LIB} -lstack

# test for Q3
runlibstack: ${BIN}/libstack_test
	echo "Testing Stack"
	${BIN}/stack_test

# test for Q4
runlibfifo: # todo

# Clean rule
# !Be very careful to use "rm -rf"
clean:
	rm -f $(LIB)/* $(OBJ)/* $(BIN)/*
