#pragma once
#include "node.h"
//Let's make an ascending ordered list

/*some tests?
add to an empty list
remove from an empty list
print an empty list
search in an empty list

add before head of list
add after head of list
add farther down the list (may be similar to previous test)

remove head
remove after head
remove non-existent value

print list of size 1
print list of size > 1 (may be similar to previous test)

search list of size 1
search list of size > 1 (may be similar to previous test)
search non-existant value (may be similar to searching an empty list?)

others?

*/


//operations I need for my Auto_sorted_list class:
class Auto_sorted_list {
//attributes I want to track:
private:
//head //points to first node in list
	Node *head;
//tail //points to last node in list
	Node *tail;
//length? //total number of nodes in the list... optional
	int length;
	
public:
//constructor
	Auto_sorted_list();
//should probably make destructor and copy constructor...
//add(value) //add the new value into the appropraite location in the list, return whether the operation succeeded.
	bool add(int new_value);
//remove(value) //find and remove the first appearance of a value in the list, return either that value or -1 if not found. (I do not like this way...)
	int remove(int old_value);
//print() //print whole list (optional...)
	void print();
//search(value) //search the list to see if the value is in it and return the position of that value if it exists.
	int search(int candidate_value);
	
	int get_length();
};
