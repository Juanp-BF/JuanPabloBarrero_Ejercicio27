all: output1 output2

output1: listing2.x
	mpirun -np 4 ./listing2.x

output2: listing3.x
	mpirun -np 4 ./listing3.x

listing2.x: listing2.c
	mpicc listing2.c -o listing2.x

listing3.x: listing3.c
	mpicc listing3.c -o listing3.x

clean:
	rm -f output1
	rm -f output2
