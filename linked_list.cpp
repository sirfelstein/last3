/*********************************************************************
** Program Filename: linked_list.cpp
** Author: Caden Runyan
** Date: 12-3-22
** Description: 
** Input:NA
** Output: does various tasks with the link list
*********************************************************************/

#include <iostream>
#include <string>

#include "linked_list.h"

using namespace std;

 /*********************************************************************
** Function:Linked_List()
** Description:constructor
** Parameters:NA
** Pre-Conditions:NA
** Post-Conditions:liked list is constructed
*********************************************************************/

Linked_List::Linked_List(){
    this->length = 0;
    head = NULL;
    current = NULL;
}

/*********************************************************************
** Function: get_length()
** Description: returns the amount of nodes in the list
** Parameters: NA
** Pre-Conditions: the list exists
** Post-Conditions: amount of nodes in lisk is known
*********************************************************************/

int Linked_List::get_length(){
    return length;
}

/*********************************************************************
** Function: get_head()
** Description: returns which node is the head of the list
** Parameters: NA
** Pre-Conditions: the list exists with a head
** Post-Conditions: head of list is known
*********************************************************************/

Node* Linked_List::get_head() const{
    return this->head;
}

/*********************************************************************
** Function: print()
** Description: shows the list of nodes to the user
** Parameters: NA
** Pre-Conditions: list exists
** Post-Conditions: user can see the list
*********************************************************************/

void Linked_List::print(){
    current = head;
    while(current != NULL){
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

/*********************************************************************
** Function: clear()
** Description: deletes all nodes in the list, making length 0
** Parameters: NA
** Pre-Conditions: the list exists
** Post-Conditions: the list no longer has any nodes in it
*********************************************************************/

void Linked_List::clear(){
    current = head;
    Node* temp = NULL;
    while(current != NULL){
        temp = current->next;
        delete current;
        current = temp;
    }
    head = NULL;
    current = NULL;
    length = 0;
}

/*********************************************************************
** Function: push_front(int ele)
** Description: adds the new element to the front of the list
** Parameters: int ele
** Pre-Conditions: list exists and element is given
** Post-Conditions: a new element should be added to the beginning of the linked list
*********************************************************************/

void Linked_List::push_front(int ele){
    Node* new_node = new Node();
    new_node->val = ele;
    new_node->next = head;
    head = new_node;
    length++;
}

/*********************************************************************
** Function: push_back(int ele)
** Description: adds an element tot the end of the list
** Parameters: int ele
** Pre-Conditions: list exists and element is given
** Post-Conditions: a new element should be added to the end of the linked list
*********************************************************************/

void Linked_List::push_back(int ele){
    Node* new_node = new Node();
    current = head;
    new_node->val = ele;
    new_node->next = NULL;
    
    while(current->next != NULL){
        current = current->next;
    }

    current->next = new_node;
    length++;
}

/*********************************************************************
** Function: insert(int val, unsigned int index)
** Description: this will insert a given value to a given index in the list
** Parameters: int val, unsigned int index
** Pre-Conditions: list exists and element and index are given
** Post-Conditions: an element is added to the specified index of the linked list
*********************************************************************/

void Linked_List::insert(int val, unsigned int index){
    if(index == 0){
        push_front(val);
    }

    else if(index == length-1){
        push_back(val);
    }

    else if(index > length){
        cout << val << " cannot be inserted in "  << index << "th index!" <<endl;
    }

    else{
        Node* new_node = new Node();
        current = head;
        new_node->val = val;
        for(int i = 0;i < index-1;i++){ //go to the index
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
        length++;
    }
    
}

/*********************************************************************
** Function: fbs(Node* source, Node** front, Node** back)
** Description: divides the larger list into two smaller lists
** Parameters: Node* source, Node** front, Node** back
** Pre-Conditions: larger, initial list exists
** Post-Conditions: two smaller lists are created from the larger one
*********************************************************************/

void Linked_List::fbs(Node* source, Node** front, Node** back){
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

/*********************************************************************
** Function: merge_sort(Node** headref)
** Description: merges the elements of the list from smallest to largest
** Parameters: Node** headref
** Pre-Conditions: list exists with all of the nodes
** Post-Conditions: list is now sorted in ascending order
*********************************************************************/ 

void Linked_List::merge_sort(Node** headref){//sort ascending order.
    Node* head1 = *headref;
    Node* a;
    Node* b;
    if(head1 == NULL || head1->next == NULL){
        return;
    }
    fbs(head1,&a,&b);
    merge_sort(&a);
    merge_sort(&b);

    *headref = sorted_merge(a,b);
}

/*********************************************************************
** Function: merge_sort2(Node** headref)
** Description: merges the elements of the list from largest to smallest
** Parameters: Node** headref
** Pre-Conditions: list exists with all of the nodes
** Post-Conditions: list is now sorted in descending order
*********************************************************************/ 

void Linked_List::merge_sort2(Node** headref){//sort descending order.
    Node* head1 = *headref;
    Node* a;
    Node* b;
    if(head1 == NULL || head1->next == NULL){
        return;
    }
    fbs(head1,&a,&b);
    merge_sort2(&a);
    merge_sort2(&b);

    *headref = sorted_merge2(a,b);
}

/*********************************************************************
** Function: sorted_merge(Node* a, Node* b)
** Description: sort elements in ascending order
** Parameters: Node* a, Node* b
** Pre-Conditions: list exists with nodes
** Post-Conditions: elements are now sorted in ascending order
*********************************************************************/ 

Node* Linked_List::sorted_merge(Node* a, Node* b){
    Node* result = NULL;
    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }

    if(a->val <= b->val){
        result = a; //store the smaller one
        result->next = sorted_merge(a->next, b);
    }
    else{
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

/*********************************************************************
** Function: sorted_merge2(Node* a, Node* b)
** Description: sorts elements in descending order
** Parameters: Node* a, Node* b
** Pre-Conditions: list exists with nodes
** Post-Conditions: elements are now sorted in descending order
*********************************************************************/ 

Node* Linked_List::sorted_merge2(Node* a, Node* b){
    Node* result = NULL;
    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }

    if(a->val <= b->val){
        result = b; //store the bigger one
        result->next = sorted_merge2(a, b->next);
    }
    else{
        result = a;
        result->next = sorted_merge2(a->next, b);
    }
    return result;
}

/*********************************************************************
** Function: sort_ascending()
** Description: will sort all of the elements in the list in ascending order
** Parameters: NA
** Pre-Conditions: list exists 
** Post-Conditions: list is now fully sorted in ascending order
*********************************************************************/ 

void Linked_List::sort_ascending(){ //O(nlogn)
        merge_sort(&head);//call ascending sort function.

}

/*********************************************************************
** Function: sort_descending
** Description: will sort all of the elements in the list in descending order
** Parameters: NA
** Pre-Conditions: list exists
** Post-Conditions: list is now fully sorted in descending order
*********************************************************************/ 

void Linked_List::sort_descending(){ //O(nlogn)
    merge_sort2(&head); //call descending sort function.
}

/*********************************************************************
** Function: count_prime(const Linked_list& list)
** Description: this will return the amount of prime numbers in the list
** Parameters: const Linked_List& list
** Pre-Conditions: list exists
** Post-Conditions: the amount of prime numbers in the list is now known
*********************************************************************/ 

int count_prime(const Linked_List& list){ //O(n)*O(x)
    int count = 0, notPrime, saveHalf, i;
    Node* current = list.get_head(); // get the head of the list.
    
    while(current != NULL){
        saveHalf = current->val/2;
        notPrime = 0;
		  //don't count 0, 1 and negative numbers as a prime number.
        if(current->val == 1 || current->val <= 0){ 
            notPrime = 1;
         }
        for(i = 2; i<=saveHalf; i++){
            if(current->val % i == 0){
                notPrime = 1;
                break;
            }
        }
        if(notPrime == 0){
         count++;
        }
        current = current->next;
    }
    return count;
}
