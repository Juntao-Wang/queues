all: deque_main rand_main Subset Palindrome
deque_main: deque_main.o
	g++ -o deque_main deque_main.o
deque_main.o: deque_main.cpp Deque.h
	g++ -c deque_main.cpp
rand_main: rand_main.o
	g++ -o rand_main rand_main.o
rand_main.o: rand_main.cpp RandomizedQueue.h
	g++ -c rand_main.cpp
Subset: Subset.o
	g++ -o Subset Subset.o
Subset.o: Subset.cpp RandomizedQueue.h
	g++ -c Subset.cpp
Palindrome: Palindrome.o
	g++ -o Palindrome Palindrome.o
Palindrome.o: Palindrome.cpp Deque.h
	g++ -c Palindrome.cpp
clean:
	rm *.o
