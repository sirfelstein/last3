TA guess: Zakarie Leskowsky

Caden Runyan - 934382825

This program will recreate a linked list without using the list library. Linked
lists normally have many elements in them that connect to one another through
links. These elements are known as nodes. This program simulates some of the
functions that are offered in the list libraries including get_length, get_head,
print, clear, push_front, push_back, insert, sort_ascending, sort_descending, 
and count_prime.

It is a simple program to run because the test_linked_list.cpp file has most of 
the content that needs to be run, and it was given to us. All the user needs
to do is make and run the files and then select 2, which will run the test.
The program can then be continued by pressing enter and seeing how the tests 
are run.

There are a few limitations with this program, because the test file is already
created. If the user wants to test different elements, they would need to change
the test_linked_list file before making and running the program.

EC: recursive descending sorting

The sort_ascending function will first divide the list into two equal sized
sections. The program will then sort the two smaller lists into ascending
order using recursive programming. Then, the elements will be merged into
a larger, sorted list. The list will then be returned to the user.
This function has a runtime complexity of O(nlogn)

The sort_descending function will work similarly by finding the middle of 
the larger list and divide it into two smaller lists. These smaller lists
will then be sorted in descending order and the elements of these smaller
lists will then be merged into a larger list in descending order. This final
list will then be returned to the user. (or tested from the testing file) 
This function has a runtime complexity of O(nlogn)

The count_prime function will look through the entire given list and check
if the selected number is prime. It does this by repeating the code until 
the end of the list. It first sets a save variable to 0 (unless the element 
being tested is 0, 1, or negative) which will stay 0 if the number is prime, 
and change to 1 if the numebr is not prime. It then calculates half of the 
element and saves that number in another save variable. It then checks the 
remainder of the element divided by i starting at 2 to make sure it is not 
0 (which would mean it is not prime). It will repeat this until the end of 
the list. If the selected number is prime, it will add one to the counter. 
The function will then return the amount of prime numbers inside the list. 
This function has a runtime complexity of O(n * [amount of elements in list])
