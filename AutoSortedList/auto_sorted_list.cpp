#include <iostream>

#include "auto_sorted_list.h"

using std::cout;
using std::endl;

//operations I need for my Auto_sorted_list class:
//constructor
Auto_sorted_list::Auto_sorted_list() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}
//should probably make destructor and copy constructor...
//add(value) //add the new value into the appropraite location in the list, return whether the operation succeeded.
bool Auto_sorted_list::add(int new_value) {
	Node *new_node = new Node(new_value, nullptr, nullptr);
	
	head = tail = new_node;
	
	length++;
	
	return true;
}
//remove(value) //find and remove the first appearance of a value in the list, return either that value or -1 if not found. (I do not like this way...)
int remove(int old_value) {
	return -1;
}
//print() //print whole list (optional...)
void Auto_sorted_list::print() {
	Node *current = head;
	while(current != nullptr) {
		cout << current->get_value() << ", ";
		current = current->get_next();
	}
	cout << endl;
}
//search(value) //search the list to see if the value is in it and return the position of that value if it exists or -1 if it does not exist.
int search(int candidate_value) {
	return -1;
}

int Auto_sorted_list::get_length() {
	return length;
}
