#include <iostream>
#include "linked_list.h"

using namespace std;

void pause() {
        cout << "\n\nPress <enter> to continue...";
        cin.clear();
        cin.ignore(256, '\n');
}

//Here is the pattern funtion that runs and outputs the fractal
void pattern(int n, int col){

	if (n == 0) return;

	if (n == 1){

        for (int a = 0;a<2*col;a++){
                cout<<" ";  
        }
        cout<<"* ";
        cout<<endl;
	return;
	}
	else{

        pattern(n-2, col+1);
        for (int a = 0; a < 2*col; a++){
                cout<<" ";
        }

        for (int b = 0; b < n; b++){
                cout<<"* ";
        }

        cout<<endl;
        pattern(n-2, 1+col);
 
 	}
 }

int main(int argc, char const *argv[])
{
	int programChoice = 0;	//the console will ask the user which program to run
	cout<<"Enter 1 to run the fractal recursion program and 2 to run the linked list program"<<endl;
	cin >> programChoice;

//if the user chooses to run the recursive fractal, the following code will run, recursively calling the pattern function above
	if(programChoice == 1){ 
		int stars;
        int spaces;
        cout << "Enter a number"<<endl;
        cin >> stars;
        cout << "Enter a second number"<<endl;
        cin >> spaces;
        cout<<endl;
        pattern(stars, spaces);
        cout<<endl;
	}

//if the user does not choose to run the fractal, the test_linked_list.cpp file will run as it is
	else{
	Linked_List l;
	cout << "\n\nList successfully created!!\n\n";;

	cout << "**********Test 1***********\n";
	cout << "Before adding nodes...\n";
	cout << "Testing get_length()\n";
	cout << "Expected: 0\n";
	cout << "Actual  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		cout << "Test 1 PASSED\n\n";
	else
		cout << "Test 1 FAILED\n\n";


	cout << "**********Test 2***********\n";
	cout << "Adding nodes...\n";
	cout << "Test 2.1: Testing push_front()\n";
	l.push_front(5);
	l.push_front(100);
	l.push_front(0);
	l.push_front(-8);
	l.push_front(16);
	cout << "Expected: 16 -8 0 100 5\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Expected length: 5\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.1 completed.\n";
	pause();

	cout << "Test 2.2: Testing push_back()\n";
	l.push_back(5);
	l.push_back(1);
	l.push_back(2);
	l.push_back(7);
	l.push_back(7919);
	cout << "Expected: 16 -8 0 100 5 5 1 2 7 7919\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Expected length: 10\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.2 completed.\n";
	pause();

	cout << "Test 2.3: Testing insert()\n";
	l.insert(11, 0);   // insert 11 at the front of the list
	l.insert(20, 100); // 100 is not a valid index, therefore 20 is not inserted
	l.insert(50, l.get_length()); // insert 50 at the end of the list
	l.insert(9, 5); // insert 9 at index 5 
	cout << "Expected: 11 16 -8 0 100 9 5 5 1 2 7 7919 50\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Expected length: 13\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.3 completed.\n";
	pause();

	cout << "**********Test 3***********\n";
	cout << "Sorting...\n";
	cout << "Test 3.1: Testing sort_ascending()\n";
	l.sort_ascending();
	cout << "Expected: -8 0 1 2 5 5 7 9 11 16 50 100 7919\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Test 3.1 completed.\n";
	pause();

	cout << "Test 3.2: Testing sort_descending()\n";
	l.sort_descending();
	cout << "Expected: 7919 100 50 16 11 9 7 5 5 2 1 0 -8\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Test 3.2 completed.\n";
	pause();

	cout << "**********Test 4***********\n";
	cout << "Tesing count_prime()\n";
	cout << "Expected: 6\n";
	int num_prime = count_prime(l);
	cout << "Actual  : " << num_prime << "\n";
	if (num_prime == 6)
		cout << "Test 4 PASSED\n";
	else
		cout << "Test 4 FAILED\n";

	cout << "**********Test 5***********\n";
	cout << "Tesing clear()\n";
	l.clear();
	cout << "Expected length: 0\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		cout << "Test 5 PASSED\n";
	else
		cout << "Test 5 FAILED\n";

	return 0;
	}
}