#Compiles the MIPS architecture simulation.
all:
	acsim mips1.ac -abi
	make -f Makefile.archc

#Runs the simulation. 
#Ignore the "make: *** [run] Error 1" message.
run:
#	./mips1.x --load=qsort_large input_large.dat
	./mips1.x --load=susan input_large.pgm out.pgm
