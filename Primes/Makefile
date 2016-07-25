CMPL=g++ -std=c++11
CFLGS=-I.
EXEC=prime_tests
SRCS=tests.cpp Primes.cpp
DEPS=Primes.h
OBJS=$(SRCS:%.cpp=%.o)

all: $(EXEC)
	@make run

$(EXEC): $(OBJS)
	$(CMPL) $(CFLGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CMPL) $(CFLGS) -c -o $@ $<

run:
	@if [ -x $(EXEC) ]; then ./$(EXEC); \
	else chmod +x $(EXEC) && ./$(EXEC); fi 

clean:
	@rm -f *.o
