#ifndef DATA_STRUCTURE_CPLUSPLUS_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURE_CPLUSPLUS_DOUBLY_LINKED_LIST_H

class doubly_linked_list_node {
public:
	doubly_linked_list_node() { next = nullptr; prev = nullptr; }
	doubly_linked_list_node(int data, doubly_linked_list_node *ptr1 = nullptr, doubly_linked_list_node *ptr2 = nullptr)
		: info{data}, next{ptr1}, prev{ptr2} {}

	int info {};
	doubly_linked_list_node *prev;
	doubly_linked_list_node *next;
};

class doubly_linked_list : public doubly_linked_list_node {
public:
	doubly_linked_list() {
		head = tail = nullptr;
	}

	~doubly_linked_list();

	bool is_empty();

	void add_to_head(int);

	void add_to_tail(int);

	int delete_from_head();

	int delete_from_tail();

	void delete_node(int);

	bool is_in_list(int);

protected:
	doubly_linked_list_node *head, *tail;
};

#endif //DATA_STRUCTURE_CPLUSPLUS_DOUBLY_LINKED_LIST_H
