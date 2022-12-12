#ifndef DATA_STRUCTURE_CPLUSPLUS_STACK_H
#define DATA_STRUCTURE_CPLUSPLUS_STACK_H

template<typename T>
class Array_stack {
public:
	explicit Array_stack(int cap)
			:capacity_{cap}, stack{new T[capacity_]}, index{-1}
	{
	}

	int size() const;

	bool empty() const;

	const T& top() const;

	void push(const T& element);

	void pop();

private:
	T* stack_;            // array of stack elements
	int capacity_;        // stack capacity
	int index_;           // index of the top of the stack
};

#endif //DATA_STRUCTURE_CPLUSPLUS_STACK_H
