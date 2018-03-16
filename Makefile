clean:
	rm *.out
	rm *.txt

genfiles:
	python gen.py 0 100000 > ordered.txt
	python gen.py 1 100000 > reversed.txt
	python gen.py 2 100000 > random.txt


benchmark:
	gcc -fopenmp prog.c -o prog.out

