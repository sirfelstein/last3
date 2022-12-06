CC = g++ -g 
exe_file = driver

all: $(exe_file)

$(exe_file): linked_list.o node.h linked_list.h test_linked_list.cpp
	$(CC) linked_list.o test_linked_list.cpp -std=c++11  -o  $(exe_file)

linked_list.o: linked_list.cpp linked_list.h
	$(CC) -c linked_list.cpp

clean:
	rm -f *.o $(exe_file)
