#include "singly_linked_list.h"

singly_linked_list::~singly_linked_list()
{
	singly_linked_list_node* temp;
	for (temp = head; temp!=tail;) {
		temp = temp->next;
		delete head;
		head = temp;
	}
}

bool singly_linked_list::is_empty()
{
	return (head==nullptr);
}

void singly_linked_list::add_to_head(int element)
{
	singly_linked_list_node* temp = new singly_linked_list_node{element};
	if (tail==nullptr) {
		head = tail = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
}

void singly_linked_list::add_to_tail(int element)
{
	singly_linked_list_node* temp = new singly_linked_list_node{element};

	if (tail==nullptr) {
		head = tail = temp;
	}
	else {
		tail->next = temp;
		tail = temp;
	}
}

int singly_linked_list::delete_from_head()
{
	int element = head->info;

	if (head==tail) {
		head = tail = nullptr;
	}
	else {
		singly_linked_list_node* temp = head;
		head = temp->next;
		delete temp;
	}

	return element;
}

int singly_linked_list::delete_from_tail()
{
	int element = tail->info;

	if (head==tail) {
		head = tail = nullptr;
	}
	else {
		singly_linked_list_node* temp;
		for (temp = head; temp->next!=tail; temp = temp->next);
		tail = temp;
		temp->next = nullptr;
		delete temp;
	}

	return element;
}

void singly_linked_list::delete_node(int element)
{
	singly_linked_list_node* temp1, * temp2;
	if (!is_empty()) {
		if (head==tail && head->info==element) {
			delete head;
			head = tail = nullptr;
		}
		else if (head->info==element) {
			temp1 = head->next;
			delete head;
			head = temp1;
		}
		else {
			for (temp1 = head, temp2 = head->next; temp2!=nullptr && temp2->info!=element; temp1 = temp1->next, temp2 = temp2->next);
			if (temp2!=nullptr) {
				temp1->next = temp2->next;
				if (temp2==tail) {
					tail = temp1;
				}
				delete temp2;
			}
		}
	}
}

bool singly_linked_list::is_in_list(int element)
{
	singly_linked_list_node* temp;
	for (temp = head; temp!=nullptr && temp->info!=element; temp = temp->next);
	return (temp!=nullptr);
}









