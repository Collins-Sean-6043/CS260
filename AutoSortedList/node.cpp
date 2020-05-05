#include "node.h"

Node::Node() {
	value = 0;
	next = nullptr;
	prev = nullptr;
}

Node::Node(int new_value, Node *new_next, Node *new_prev) {
	value = new_value;
	next = new_next;
	prev = new_prev;
}

int Node::get_value() {return value;}
void Node::set_value(int new_value) {value = new_value;}

Node *Node::get_next() {return next;}
void Node::set_next(Node *new_next) {next = new_next;}

Node *Node::get_prev() {return prev;}		
void Node::set_prev(Node *new_prev) {prev = new_prev;}
