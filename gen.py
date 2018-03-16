import sys
import random
size = int(sys.argv[1])
if int(sys.argv[2]) == 1:	#ordered
	for i in range(0,size):
		print(i)
elif int(sys.argv[2]) == 2: #reverse ordered
	for i in range(0,size):
		print(size - i)
else:
	for i in range(0,size): #random
	#f.write(str(int(random.uniform(0,size))) + '\n') 
	print(int(random.uniform(0,size)))

