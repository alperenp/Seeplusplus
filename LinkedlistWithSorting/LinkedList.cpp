#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class AlpoType>
node<AlpoType> * LinkedList<AlpoType>::cloneList() const
{	
	if (head == NULL)
	{
		return NULL;
	}
	node<AlpoType> * cloneHead = new node<AlpoType>(head->info);
	node<AlpoType> * prev = cloneHead;
	node<AlpoType> * iterator = head->next;

	while (iterator != NULL)
	{
		node<AlpoType> * newitem = new node<AlpoType>(iterator->info);
		prev->next = newitem;

		prev = prev->next;
		iterator = iterator->next;
	}
	return cloneHead;
}

template <class AlpoType>
int LinkedList<AlpoType>::length()
{
	int len = 0;
	node<AlpoType> * iterator = head;
	while (iterator != NULL)
	{
		++len;
		iterator = iterator->next;
	}
	return len;
}

template <class AlpoType>
void LinkedList<AlpoType>::UpdateRear()
{
	if (head == NULL)
	{
		rear = NULL;
	}
	else
	{
		node<AlpoType> * iterator = head;
		while (iterator->next != NULL)
		{
			iterator = iterator->next;
		}
		rear = iterator;
	}
}

template <class AlpoType>
void LinkedList<AlpoType>::Swap(node<AlpoType> * a, node<AlpoType> * b)
{
	AlpoType temp = a->info;
	a->info = b->info;
	b->info = temp;
}

template <class AlpoType>
void LinkedList<AlpoType>::addInOrder(AlpoType item)
{
	node<AlpoType> * newitem = new node<AlpoType>(item);
	if (head == NULL)
	{
		head = newitem;
	}
	else
	{		
		if (head->info > item)
		{
			addToBeginning(item);
		}
		else
		{
			node<AlpoType> * prev = head;
			node<AlpoType> * iterator = head->next;
			while (iterator != NULL && iterator->info <= item)
			{
				prev = prev->next;
				iterator = iterator->next;				
			}
			prev->next = newitem;
			newitem->next = iterator;
		}		
	}
	UpdateRear();
}

template <class AlpoType>
void LinkedList<AlpoType>::updateShell(node<AlpoType> * leftiterator, int sortingCount)
{
	bool updateavailable = true;
	node<AlpoType> * currentiterator = head;
	for (int i = 0; i < sortingCount; ++i)
	{
		if (leftiterator == currentiterator)
		{
			updateavailable = false;
			break;
		}
		currentiterator = currentiterator->next;
	}

	if (updateavailable)
	{
		currentiterator = head;
		node<AlpoType> * newleft = NULL;
		node<AlpoType> * inneriterator = currentiterator;
		while (newleft == NULL)
		{
			for (int i = 0; i < sortingCount; ++i)
			{
				inneriterator = inneriterator->next;
			}
			if (inneriterator == leftiterator)
			{
				newleft = currentiterator;
			}
			currentiterator = currentiterator->next;
			inneriterator = currentiterator;
		}
		if (newleft->info > leftiterator->info)
		{
			Swap(newleft,leftiterator);
			updateShell(newleft, sortingCount);
		}
	}
}

template <class AlpoType>
node<AlpoType> * LinkedList<AlpoType>::findMinNode(node<AlpoType> * startingpoint)
{
	node<AlpoType> * minNode = startingpoint;
	node<AlpoType> * iterator = startingpoint;
	while (iterator != NULL)
	{
		if (minNode->info > iterator->info)
		{
			minNode = iterator;
		}
		iterator = iterator->next;
	}
	return minNode;
}

template <class AlpoType>
void LinkedList<AlpoType>::merge(node<AlpoType> * lefthead, node<AlpoType> * righthead)
{
	Clear();
	node<AlpoType> * leftiterator = lefthead;
	node<AlpoType> * rightiterator = righthead;
	while (leftiterator != NULL && rightiterator != NULL)
	{
		if (leftiterator->info <= rightiterator->info)
		{
			addToEnd(leftiterator->info);
			leftiterator = leftiterator->next;
		}
		else
		{
			addToEnd(rightiterator->info);
			rightiterator = rightiterator->next;
		}
	}

	while (leftiterator != NULL)
	{
		addToEnd(leftiterator->info);
		leftiterator = leftiterator->next;
	}

	while (rightiterator != NULL)
	{
		addToEnd(rightiterator->info);
		rightiterator = rightiterator->next;
	}
}

template <class AlpoType>
LinkedList<AlpoType>::LinkedList()
{
	head = NULL;
	UpdateRear();
}


template <class AlpoType>
LinkedList<AlpoType>::LinkedList(const LinkedList & tobecopied)
{
	head = tobecopied.cloneList();
	UpdateRear();
}

template <class AlpoType>
LinkedList<AlpoType>::~LinkedList()
{
	Clear();
}


template <class AlpoType>
void LinkedList<AlpoType>::Clear()
{
	node<AlpoType> * iterator = head;
	while (iterator != NULL)
	{
		node<AlpoType> * temp = iterator;
		iterator = iterator->next;
		delete temp;
	}
	head = NULL;
	UpdateRear();
}

template <class AlpoType>
void LinkedList<AlpoType>::Print()
{
	node<AlpoType> * iterator = head;
	if (head == NULL)
	{
		cout << "Empty List" << endl;
	}
	else
	{
		cout << "List Items:" << endl;
	}
	while (iterator != NULL)
	{
		cout << iterator->info << " ";
		iterator = iterator->next;
	}
	cout << endl;
}





template <class AlpoType>
void LinkedList<AlpoType>::addToBeginning(AlpoType item)
{
	node<AlpoType> * newitem = new node<AlpoType>(item, head);
	head = newitem;
}

template <class AlpoType>
void LinkedList<AlpoType>::addToEnd(AlpoType item)
{
	node<AlpoType> * newitem = new node<AlpoType>(item);	
	if (head == NULL)
	{
		head = newitem;
		UpdateRear();
	}
	else
	{		
		rear->next = newitem;
		rear = newitem;
	}
}

// Best Case : already Sorted => O(n)
// Worst Case: Reverse Sorted => O(n^2)
template <class AlpoType>
void LinkedList<AlpoType>::bubbleSort()
{
	if (head == NULL)
	{
		return;
	}

	node<AlpoType> * inneriterator = head;
	node<AlpoType> * outeritrator = head;
	while (outeritrator != NULL)
	{
		bool isSwapped = false;
		while (inneriterator->next != NULL)
		{
			if (inneriterator->info > inneriterator->next->info)
			{
				Swap(inneriterator, inneriterator->next);
				isSwapped = true;
			}
			inneriterator = inneriterator->next;
		}
		if (isSwapped == false) // if no swap is done, then list is sorted
		{
			break;
		}
		outeritrator = outeritrator->next;
		inneriterator = head;
	}
	UpdateRear();
}

// Best Case: Reverse Sorted => O(n)
// Worst Case: Sorted => O(n^2)
template <class AlpoType>
void LinkedList<AlpoType>::insertionSort()
{
	node<AlpoType> * outeriterator = head;	
	LinkedList<AlpoType> newlist;
	while (outeriterator != NULL)
	{
		newlist.addInOrder(outeriterator->info); //find appropriate place		
		outeriterator = outeriterator->next;
	}
	Clear();
	head = newlist.cloneList();
	UpdateRear();
}




template <class AlpoType>
void LinkedList<AlpoType>::shellSort()
{
	for (int iterationNumber = length() / 2; iterationNumber > 0; iterationNumber = iterationNumber / 2)
	{
		node<AlpoType> * leftiterator = head;
		node<AlpoType> * rightiterator = head;
		for (int i = 0; i < iterationNumber; ++i)
		{
			rightiterator = rightiterator->next;
		}

		while (rightiterator != NULL)
		{
			if (leftiterator->info > rightiterator->info)
			{
				Swap(leftiterator,rightiterator);
				updateShell(leftiterator, iterationNumber);
			}

			leftiterator = leftiterator->next;
			rightiterator = rightiterator->next;
		}		
	}
	
}

template <class AlpoType>
void LinkedList<AlpoType>::selectionSort()
{
	node<AlpoType> * iterator = head;
	while (iterator != NULL)
	{
		node<AlpoType> * minnode = findMinNode(iterator);
		Swap(iterator, minnode);
		iterator = iterator->next;
	}
	UpdateRear();
}



template <class AlpoType>
void LinkedList<AlpoType>::mergeSort()
{
	int listlen = length();

	if (listlen <= 1)
	{
		return;
	}

	if (listlen == 2)
	{
		node<AlpoType> * leftnode = head;
		if (leftnode->info > leftnode->next->info)
		{
			Swap(leftnode, leftnode->next);
		}
		return;
	}
	node<AlpoType> * lefthead = cloneList();

	node<AlpoType> * iterator = lefthead;
	for (int i = 0; i < (listlen / 2) - 1; ++i)
	{
		iterator = iterator->next;
	}
	node<AlpoType> * righthead = iterator->next;
	iterator->next = NULL;

	LinkedList<AlpoType> leftlist;
	LinkedList<AlpoType> rightlist;

	leftlist.head = lefthead;
	leftlist.UpdateRear();
	rightlist.head = righthead;
	rightlist.UpdateRear();


	leftlist.mergeSort();
	rightlist.mergeSort();

	merge(lefthead, righthead);
}

template <class AlpoType>
void LinkedList<AlpoType>::quickSort()
{
	int listlen = length();

	if (listlen <= 1)
	{
		return;
	}

	node<AlpoType> * pivot = head;
	for (int i = 0; i < listlen / 2; ++i)
	{
		pivot = pivot->next;
	}

	LinkedList<AlpoType> leftlist;
	LinkedList<AlpoType> rightlist;

	node<AlpoType> * iterator = head;
	while (iterator != NULL)
	{
		if (iterator->info <= pivot->info)
		{
			leftlist.addToBeginning(iterator->info);
		}
		else
		{
			rightlist.addToBeginning(iterator->info);
		}
		iterator = iterator->next;
	}
	leftlist.quickSort();
	rightlist.quickSort();
	merge(leftlist.head, rightlist.head);
}