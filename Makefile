#Compiles the MIPS architecture simulation.
all:
	acsim mips1.ac -abi
	make -f Makefile.archc

#Runs the simulation. 
#Ignore the "make: *** [run] Error 1" message.
qsort:
	./mips1.x --load=../bench/qsort/qsort_large ../bench/qsort/input_large.dat

susan:
	./mips1.x --load=../bench/susan/susan ../bench/susan/input_large.pgm ../bench/susan/output_susan.txt

jpeg:
	./mips1.x --load=../bench/jpeg/djpeg ../bench/jpeg/input_large.jpg > ../bench/jpeg/output.ppm

sha:
	./mips1.x --load=../bench/sha/sha ../bench/sha/input_large.asc

gsm:
	./mips1.x --load=../bench/gsm/toast ../bench/gsm/large.au
	rm ../bench/gsm/large.au.gsm

bench:
	make susan
	make jpeg
	make sha
	make gsm
	make qsort
