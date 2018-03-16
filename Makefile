clean:
	rm *.out

genfiles:
	python gen.py 100000 0 > ordered
	python gen.py 100000 1 > unordered
	python gen.py 100000 2 > random


benchmark:
	gcc -fopenmp prog.c -o prog.out

