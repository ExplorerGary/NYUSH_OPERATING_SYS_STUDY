
First Name: Ziqi

Last Name: Gu

NYU ID: zg2598

=======================================================================================
Files submitted:

include:
	fifo.h: Definition of a queue
	list.h: Definition of a doubly linked list
	stack.h: Definition of a stack

src:
	stack_test.c: Script to test stack.
	list_impl.c: ...
	stack_array.c: ...
	fifo_test.c: ...

	// contents for assignments: //
	Exercise1: 
	Exercise1_1.c: create N_CHILDREN child processes for the same parent process in an iterative way.
	Exercise1_2.c: create N_CHILDREN child processes for the same parent process in an recursive way.

	Exercise2:
	Exercise2_1_1.c: create N_CHILDREN child processes for the same parent process in an iterative way. and wait for any child to complete via wait(NULL) cmd.
	Exercise2_1_2.c: create N_CHILDREN child processes for the same parent process in an iterative way. and wait for the last child to complete via waitpid() cmd.
	Exercise2_1_3.c: create N_CHILDREN child processes for the same parent process in an iterative way. and wait for all the child to complete via multiple wait() cmd.
	Exercise2_2_1.c: create N_CHILDREN child processes for the same parent process in an recursive way. and wait for any child to complete via wait(NULL) cmd.
	Exercise2_2_2.c: create N_CHILDREN child processes for the same parent process in an recursive way. and wait for the last child to complete via waitpid() cmd.
	Exercise2_2_3.c: create N_CHILDREN child processes for the same parent process in an recursive way. and wait for all the child to complete via multiple wait() cmd.
	
	Exercise3:
	concurrent-compilation/: the source folder for exercise 3: Parallel compilation
	concurrent-compilation/:parallel_compiler.c: compiles each of given source file separately and simultaneously, and finally link them together
	
	Exercise4:
	spy.c: a shell program with a spy wrapper.



[Note: Please list ALL files you have submitted. For each file, briefly describe its purpose and which question it belongs to.]

=======================================================================================
Compilation rules in the Makefile:

// NO SPECIFIC RULES TO FOLLOW TO COMPILE AND RUN THE PROGRAM IN THIS SUBMISSION //

[Please complete this part by describing what each make command does and which question it corresponds to.]

=======================================================================================
Comments:

To wait for the last child created, the parent records the PID returned by the last fork() and calls waitpid() with that PID. 
In the recursive implementation, the PID of the last-created child is returned through the recursive calls to main().

For exercise 3, the program outputs "a.out" by default.

All implemented programs can compile and run successfully on the virtual machine.


[Please provide explanations of the program logic either in this document or in code comments]
[This will help improve the overall readability of the project]

=======================================================================================
Textual answers: 

// N/A //

	