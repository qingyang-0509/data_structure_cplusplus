#include "stack.h"

template<typename T>
int Array_stack<T>::size() const
{
	return (index+1);
}

template<typename T>
bool Array_stack<T>::empty() const
{
	return (index<0);
}

template<typename T>
const T& Array_stack::top() const
{
	if (!empty()) {
		return stack[index];
	}
}

template<typename T>
void Array_stack<T>::push(const T& element)
{
	if (size()!=capacity) {
		stack[++index] = element;
	}
}

templete<typename T>
void Array_stack<T>::pop()
{
	if(!empty())
	{
		--index;
	}
}
