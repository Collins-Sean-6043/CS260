/*
	ToDo:
		complete add
		implement remove
		implement search
*/

#include <iostream>
#include <string>

#include "node.h"
#include "auto_sorted_list.h"

using std::cout;
using std::endl;
using std::string;

void print_message(string message);

//emulate auto-sorted list functionality
int main() {
	print_message("Creating new auto sorted list asl.");
	Auto_sorted_list asl;
	print_message("asl.get_length(): " + std::to_string(asl.get_length()));
	print_message("");
	
	print_message("adding value 10 to list asl");
	asl.add(10);
	print_message("asl.get_length(): " + std::to_string(asl.get_length()));
	asl.print();
	
	return 0;
}

void print_message(string message) {
	cout << message << endl;
}
