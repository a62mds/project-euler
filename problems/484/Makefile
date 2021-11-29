EXEC=arith_deriv

all:
	g++ -std=c++11 -o $(EXEC) main.cpp Primes.cpp -I.

run:
	@if [ -x $(EXEC) ]; then ./$(EXEC); \
	else chmod +x $(EXEC) && ./$(EXEC); fi
