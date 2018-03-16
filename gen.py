import sys
import random

size = int(sys.argv[2])

if int(sys.argv[1]) == 0:
	for i in range(0,size):
		print(i)
elif int(sys.argv[1]) == 1:
	for i in range(0,size):
		print(size - i)
else:
	for i in range(0,size):
		print(str(int(random.uniform(0,size))))
