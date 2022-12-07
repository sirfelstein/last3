1. Your name and ONID:

2. Description: One paragraph advertising what your program does (for a user who knows
nothing about this assignment, does not know C++, and is not going to read your code).
Highlight any special features:

3. Instructions: Step-by-step instructions telling the user how to compile and run your
program. Each menu choice should be described. If you expect a certain kind of input at
specific steps, inform the user what the requirements are. Include examples to guide the
user:

4. Limitations: Describe any known limitations for things the user might want or try to do
but that program does not do/handle:

5. Extra credit: If your program includes extra credit work, describe it here for
the user:

6. Complexity analysis: For each of the following function, explain the
algorithm you used and the Big O for runtime complexity:
a. sort_ascending():

b. sort_descending():

c. count_prime():


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

The sort_ascending function will first divide the list into two equal sized
sections. The program will then sort the two smaller lists into ascending
order using recursive programming. Then, the elements will be merged into
a larger, sorted list. The list will then be returned to the user.

The sort_descending function will work similarly by finding the middle of 
the larger list and divide it into two smaller lists. These smaller lists
will then be sorted in descending order and the elements of these smaller
lists will then be merged into a larger list in descending order. This final
list will then be returned to the user. (or tested from the testing file) 

The count_prime function will look through the entire given list and check
if the selected number is prime. If the selected number is prime, it will 
add one to the counter. The function will then return the amount of prime
numbers inside the list. 
