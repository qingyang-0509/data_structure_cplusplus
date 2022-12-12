#ifndef DATA_STRUCTURE_CPLUSPLUS_SINGLlY_LINKED_LIST_H
#define DATA_STRUCTURE_CPLUSPLUS_SINGLlY_LINKED_LIST_H

class singly_linked_list_node {
public:
	singly_linked_list_node()
	{
		next = nullptr;
	}

	singly_linked_list_node(int data, singly_linked_list_node* ptr = nullptr)
			:info{data}, next{ptr} { }

	int info;
	singly_linked_list_node* next;
};

class singly_linked_list : public singly_linked_list_node {
public:
	singly_linked_list()
	{
		head = tail = nullptr;
	}

	~singly_linked_list();

	bool is_empty();

	void add_to_head(int);

	void add_to_tail(int);

	int delete_from_head();

	int delete_from_tail();

	void delete_node(int);

	bool is_in_list(int);

private:
	singly_linked_list_node* head, * tail;
};

#endif // DATA_STRUCTURE_CPLUSPLUS_SINGLE_LINKED_LIST_H
