clean:
	rm *.out
	rm *.txt

genfiles:
	python gen.py 0 100000 > ordered.txt
	python gen.py 1 100000 > reversed.txt
	python gen.py 2 100000 > random.txt

buildsearch:
	gcc -o s_search.out ./serial_search.c
	gcc -fopenmp -o p_search.out ./parallel_search.c

benchmarksearch:
	./s_search.out 5 100000 357 >  benchmark_search.txt
	echo "\n"                   >> benchmark_search.txt
	./p_search.out 5 100000 357 >> benchmark_search.txt

buildsort:
	gcc -o s_sort.out ./serial_sort.c
	gcc -fopenmp -o p_sort.out ./parallel_sort.c

benchmarksort:
	./s_sort.out 5 100000 >  benchmark_sort.txt
	echo "\n"             >> benchmark_sort.txt
	./p_sort.out 5 100000 >> benchmark_sort.txt

