 /*********************************************************************
** Program Filename: linked_list.h
** Author: Caden Runyan
** Date: 12-3-22
** Description: header file for linked_list.cpp and test_linked_list.cpp
** Input: NA
** Output: NA
*********************************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

class Linked_List {
private:
		unsigned int length; // the number of nodes contained in the list
		Node* head; 
		Node* current;// a pointer to the first node in the list
		// anything else you need...
public:
		Linked_List(); 

		int get_length();
		Node* get_head() const;
		// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
		void print(); // output a list of all integers contained within the list
		void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
		void push_front(int); // insert a new value at the front of the list 
		void push_back(int); // insert a new value at the back of the list 
		void insert(int val, unsigned int index); // insert a new value in the list at the specified index 
		void split(Node*, Node**, Node**);
		void mergeSortAscending(Node**);
		void mergeSortDescending(Node**);
		Node* recursiveSortAscending(Node*, Node*);
		Node* recursiveSortDescending(Node*, Node*);
		void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	
		// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
		void sort_descending(); // sort the nodes in descending order
		void swap_node(Node**, Node*, Node*, Node*);
		Node* recursive_selection(Node*);
		void selection_sort(Node**);
	
		// you can add extra member variables or functions as desired
};

int count_prime(const Linked_List&); //count and return the number of prime numbers within the list

#endif
