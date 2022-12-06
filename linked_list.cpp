/***********************************************************************************
 * Program:linked_list.cpp
 * Author: Hyunjae Kim
 * Date: 08/14/2020
 * Description: This is cpp file of linked list.
 * ***********************************************************************************/

#include <iostream>
#include <string>

#include "linked_list.h"

using namespace std;


/*********************************************************
 * Functions: Linked_List()
 * Description: This is a constructor of linked list.
 * *******************************************************/
Linked_List::Linked_List(){
    this->length = 0;
    head = NULL;
    current = NULL;
}

/*********************************************************
 * Functions: get_length()
 * Description: This returns the number of nodes.
 * *******************************************************/
int Linked_List::get_length(){
    return length;
}

/*********************************************************
 * Functions: get_head()
 * Description: This returns the head of the node.
 * *******************************************************/
Node* Linked_List::get_head() const{
    return this->head;
}


/*********************************************************
 * Functions: print()
 * Description: This prints the list of the nodes.
 * *******************************************************/
void Linked_List::print(){
    current = head;
    while(current != NULL){
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}


/*********************************************************
 * Functions: clear()
 * Description: This deletes the nodes.
 * *******************************************************/
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
 * Functions: push_front(int ele)
 * Description: This appends the new node to the front of the list.
 * *******************************************************************/
void Linked_List::push_front(int ele){
    Node* new_node = new Node();
    new_node->val = ele;
    new_node->next = head;
    head = new_node;
    length++;
}

/*********************************************************************
 * Functions: push_back(int ele)
 * Description: This appends the new node to the last of the list.
 * *******************************************************************/
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

/****************************************************************************
 * Functions: insert(int ele)
 * Description: This appends the new node to the specific index of the list.
 * **************************************************************************/
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
 * Functions: fbs(Node* source, Node** front, Node** back)
 * Description: This splits the nodes of the list into half, and 
 *              return the two lists. 
 * *******************************************************************/
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
 * Functions: merge_sort(Node** headref)
 * Description: This merges the entire nodes of list as ascending order.
 * *******************************************************************/
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
 * Functions: merge_sort2(Node** headref)
 * Description: This merges the entire nodes of list as descending order.
 * *******************************************************************/
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
 * Functions: sorted_merge(Node* a, Node* b)
 * Description: This sorts the  nodes of sublist as ascending order.
 * *******************************************************************/
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
 * Functions: sorted_merge(Node* a, Node* b)
 * Description: This sorts the  nodes of sublist as descending order.
 * *******************************************************************/
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
 * Functions: sort_ascending()
 * Description: This sorts the  nodes of list as ascending order.
 * *******************************************************************/
void Linked_List::sort_ascending(){ //O(nlogn)
        merge_sort(&head);//call ascending sort function.

}


/*********************************************************************
 * Functions: sort_descending()
 * Description: This sorts the  nodes of list as descending order.
 * *******************************************************************/
void Linked_List::sort_descending(){ //O(nlogn)
    merge_sort2(&head); //call descending sort function.
}


/*********************************************************************
 * Functions: count_prime()
 * Description: This counts the number of prime numbers in the list.
 * *******************************************************************/
int count_prime(const Linked_List& list){ //O(n)*O(x)
    int count = 0, flag,i,m;
    Node* current = list.get_head(); // get the head of the list.
    
    while(current != NULL){
        m = current->val/2;
        flag = 0;
		  //don't count 0, 1 and negative numbers as a prime number.
        if(current->val == 1 || current->val <= 0){ 
            flag = 1;
         }
        for(i = 2;i <=m;i++){
            if(current->val % i == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
         count++;
        }
        current = current->next;
    }
    return count;
}
