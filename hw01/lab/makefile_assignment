CC=gcc -Wall
INC=include
BIN=bin
LIB=lib
OBJ=obj
SRC=src

# Create necessary directories if they don't exist
$(shell mkdir -p $(BIN) $(OBJ) $(LIB))

# this is for making files for my assignment only.
# all: 
all: ${BIN}/Exercise1_1 \
     ${BIN}/Exercise1_2 \
     ${BIN}/Exercise2_1_1 \
     ${BIN}/Exercise2_1_2 \
     ${BIN}/Exercise2_1_3 \
     ${BIN}/Exercise2_2_1 \
     ${BIN}/Exercise2_2_2 \
     ${BIN}/Exercise2_2_3 \
     ${SRC}/concurrent-compilation/parallel_compiler \
     ${BIN}/spy

# build answer for Exercise1
${BIN}/Exercise1_1: ${SRC}/Exercise1_1.c
	${CC} -o ${BIN}/Exercise1_1 ${SRC}/Exercise1_1.c

${BIN}/Exercise1_2: ${SRC}/Exercise1_2.c
	${CC} -o ${BIN}/Exercise1_2 ${SRC}/Exercise1_2.c

# build answer for Exercise2
${BIN}/Exercise2_1_1: ${SRC}/Exercise2_1_1.c
	${CC} -o ${BIN}/Exercise2_1_1 ${SRC}/Exercise2_1_1.c

${BIN}/Exercise2_1_2: ${SRC}/Exercise2_1_2.c
	${CC} -o ${BIN}/Exercise2_1_2 ${SRC}/Exercise2_1_2.c

${BIN}/Exercise2_1_3: ${SRC}/Exercise2_1_3.c
	${CC} -o ${BIN}/Exercise2_1_3 ${SRC}/Exercise2_1_3.c

${BIN}/Exercise2_2_1: ${SRC}/Exercise2_2_1.c
	${CC} -o ${BIN}/Exercise2_2_1 ${SRC}/Exercise2_2_1.c

${BIN}/Exercise2_2_2: ${SRC}/Exercise2_2_2.c
	${CC} -o ${BIN}/Exercise2_2_2 ${SRC}/Exercise2_2_2.c

${BIN}/Exercise2_2_3: ${SRC}/Exercise2_2_3.c
	${CC} -o ${BIN}/Exercise2_2_3 ${SRC}/Exercise2_2_3.c

# build answer for Exercise3
${BIN}/spy: ${SRC}/spy.c	
	${CC} -o ${BIN}/spy ${SRC}/spy.c

# build answer for Exercise4
${SRC}/concurrent-compilation/parallel_compiler: ${SRC}/concurrent-compilation/parallel_compiler.c
	${CC} -o ${SRC}/concurrent-compilation/parallel_compiler ${SRC}/concurrent-compilation/parallel_compiler.c

# done...

clean:
	rm -f $(BIN)/* $(OBJ)/* $(LIB)/*