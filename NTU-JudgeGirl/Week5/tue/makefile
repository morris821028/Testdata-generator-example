CFLAGS = -O2 -Wall -std=c99
LDLIBS = -lm

run:
	gcc $(CFLAGS) main.c -o main

testdata_output: main
	./main <1.in >1.out
	./main <2.in >2.out
	./main <3.in >3.out
	./main <4.in >4.out
	./main <5.in >5.out
	./main <6.in >6.out
	./main <7.in >7.out
	./main <8.in >8.out
	./main <9.in >9.out
	./main <10.in >10.out
clean:
	rm main
