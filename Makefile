clean:
	rm *.out

benchmark:
	gcc -fopenmp prog.c -o prog.out

build_sort:
	echo "hi"
