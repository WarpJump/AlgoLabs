OUTPUT_DIR = ${SRC}/temp
SRC =  $(shell pwd)
TARGET = 


TEST1: 
	$(eval TARGET=test1.c)

TEST2:
	$(eval TARGET=test2.c)

TEST3:
	$(eval TARGET=test3.c)

TEST4:
	$(eval TARGET=test4.c)


LIST: list_prelink
	gcc ${TARGET} -DLIST ${OUTPUT_DIR}/linked.o -o ${OUTPUT_DIR}/main.out

ARR: arr_prelink
	gcc ${TARGET} -DARR StackArr/stack_arr.c -o ${OUTPUT_DIR}/main.out

list_prelink: makedir
	gcc -c ${SRC}/StackList/stack_list.c -o ${OUTPUT_DIR}/linked.o

arr_prelink: makedir
	gcc -c ${SRC}/StackArr/stack_arr.c -o ${OUTPUT_DIR}/linked.o


makedir:
	mkdir -p $(OUTPUT_DIR)

clean:
	rm -r $(OUTPUT_DIR)
