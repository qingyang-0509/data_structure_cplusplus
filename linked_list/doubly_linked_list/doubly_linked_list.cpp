#include "doubly_linked_list.h"

doubly_linked_list::~doubly_linked_list() {
	doubly_linked_list_node *temp;
	for (temp = head; temp != tail;) {
		temp = temp->next;
		delete head;
		head = temp;
	}
	delete temp;
}

bool doubly_linked_list::is_empty() {
	return (tail == nullptr);
}

void doubly_linked_list::add_to_head(int element) {
	doubly_linked_list_node *temp = new doubly_linked_list_node{element};

	if (tail == nullptr) {
		head = tail = temp;
	} else {
		head->prev = temp;
		head->prev->next = head;
	}
}

void doubly_linked_list::add_to_tail(int element) {
	doubly_linked_list_node *temp = new doubly_linked_list_node{element};

	if (tail == nullptr) {
		head = tail = temp;
	} else {
		temp->prev = tail;
		temp->prev->next = temp;
		tail = temp;
	}
}
int doubly_linked_list::delete_from_head() {
	if (!is_empty()) {
		doubly_linked_list_node *temp;
		int element = head->info;
		if (head == tail) {
			head = tail = nullptr;
		} else {
			temp = head;
			head = temp->next;

			delete temp;
		}
		return element;
	}

}
int doubly_linked_list::delete_from_tail() {
	if (!is_empty()) {
		doubly_linked_list_node *temp;
		int element = tail->info;
		if (head == tail) {
			delete head;
			head = tail = nullptr;
		} else {
			temp = tail;
			tail = temp->prev;
			delete temp;
			tail->next = nullptr;
		}
	}
}
void doubly_linked_list::delete_node(int element) {
	if (!is_empty()) {
		doubly_linked_list_node *temp;
		if (head == tail && head->info == element) {
			delete head;
			head = tail = nullptr;
		} else if (head->info == element) {
			temp = head;
			head = temp->next;
			delete temp;
		} else {
			for (temp = head; temp->next != nullptr && temp->info == element; temp = temp->next);
			if (temp != nullptr) {
				if (temp == tail) {
					tail = temp->prev;
					tail->next = nullptr;
					delete temp;
				} else {
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete temp;
				}
			}
		}
	}
}
bool doubly_linked_list::is_in_list(int element) {
	doubly_linked_list_node *temp;
	for (temp = head; temp->info != element && temp != nullptr; temp = temp->next);
	return temp != nullptr;
}





