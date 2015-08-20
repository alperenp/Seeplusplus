#include "TemplateStack.h"
#include <iostream>
template <class AlpoType>

// private member functions
node<AlpoType>* TemplateStack<AlpoType>::cloneStack() const
{
	node<AlpoType>* newTop = NULL;
	node<AlpoType>* iterator = top;

	// if current stack is empty then clone is going to be also empty
	if (iterator != NULL)
	{
		newTop = new node(top->item, NULL);
		node<AlpoType>* newiterator = newTop;
		while (iterator->next != NULL)
		{
			// new item generation for stack
			newiterator->next = new node(iterator->next->item, NULL);

			// iterate over current and clone stack
			newiterator = newiterator->next;
			iterator = iterator->next;
		}
	}
	return newTop;
}

template <class AlpoType>
void TemplateStack<AlpoType>::clear()
{
	while (isEmpty() != true)
	{
		pop();
	}
}

// public member functions
template <class AlpoType>
TemplateStack<AlpoType>::TemplateStack()
{
	top = NULL;
	size = 0;
}

template <class AlpoType>
TemplateStack<AlpoType>::TemplateStack(const TemplateStack & stack)
{
	clear();
	top = stack.cloneStack();
	size = stack.size;
}

template <class AlpoType>
TemplateStack<AlpoType>::~TemplateStack()
{
	clear();
}

template <class AlpoType>
void TemplateStack<AlpoType>::push(AlpoType item)
{
	node<AlpoType>* newTop = new node<AlpoType>(item, top);
	top = newTop;
	++size;
}

template <class AlpoType>
AlpoType TemplateStack<AlpoType>::pop()
{
	AlpoType item = top->item;
	node<AlpoType>* todelete = top;
	top = top->next;
	--size;
	delete todelete;
	return item;
}

template <class AlpoType>
int TemplateStack<AlpoType>::getSize() const
{
	return size;
}

template <class AlpoType>
bool TemplateStack<AlpoType>::isEmpty() const
{
	if (top == NULL)
	{
		return true;
	}
	return false;
}