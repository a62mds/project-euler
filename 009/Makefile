EXEC=spc_pythag_triplet

all:
	g++ -std=c++11 -o $(EXEC) main.cpp

run:
	@if [ -x $(EXEC) ]; then ./$(EXEC); \
	else chmod +x $(EXEC) && ./$(EXEC); fi
