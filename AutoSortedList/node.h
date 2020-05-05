#pragma once

class Node {
	private:
		int value;
		Node *next;
		Node *prev;
		
	public:
		Node();
		Node(int new_value, Node *new_next, Node *new_prev);
		
		int get_value();
		void set_value(int new_value);
		
		Node *get_next();
		void set_next(Node *new_next);
		
		Node *get_prev();
		void set_prev(Node *new_prev);
};
