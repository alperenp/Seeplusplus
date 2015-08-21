#include "TemplateBST.h"

//private member functions
template <class AlpoType>
node<AlpoType>* TemplateBST<AlpoType>::cloneBST(node<AlpoType>* subtree) const
{
	node<AlpoType>* currentnode = NULL;
	if (subtree != NULL)
	{	
		currentnode = new node<AlpoType>(subtree->item);
		currentnode->leftchild = cloneBST(subtree->leftchild);
		currentnode->rightchild = cloneBST(subtree->rightchild);
	}
	return currentnode;
}


template <class AlpoType>
void TemplateBST<AlpoType>::clearSubtree(node<AlpoType>* subtree)
{
	if (subtree->leftchild != NULL)
	{
		clearSubtree(subtree->leftchild);
	}
	if (subtree->rightchild != NULL)
	{
		clearSubtree(subtree->rightchild);
	}

	if (subtree != NULL)
	{
		delete subtree;
	}
}

// adds new element to BST
template <class AlpoType>
node<AlpoType>* TemplateBST<AlpoType>::add(node<AlpoType>* subtree, const AlpoType & a)
{
	if (subtree == NULL)
	{
		subtree = new node<AlpoType>(a);
	}
	else if (a <= subtree->item)
	{
		subtree->leftchild = add(subtree->leftchild, a);
	}
	else
	{
		subtree->rightchild = add(subtree->rightchild, a);
	}
	return subtree;
}

// searches for given element and returns the pointer of that element
template <class AlpoType>
node<AlpoType>* TemplateBST<AlpoType>::find(node<AlpoType> * subtree, const AlpoType & a) const
{
	node<AlpoType>* ptr = NULL;
	if (subtree != NULL)
	{
		if (subtree->item == a)
		{
			return subtree;
		}
		else if (subtree->item < a)
		{
			ptr = find(subtree->rightchild, a);
		}
		else
		{
			ptr = find(subtree->leftchild, a);
		}
	}
	return ptr;
}

// removes the given item from BST without violating BST property
template <class AlpoType>
node<AlpoType>* TemplateBST<AlpoType>::remove(node<AlpoType> * subtree, const AlpoType & a, bool & isSizeUpdated)
{
	if (subtree == NULL)
	{
		return NULL;
	}
	else if (a < subtree->item)
	{
		subtree->leftchild = remove(subtree->leftchild, a, isSizeUpdated);
	}
	else if (a > subtree->item)
	{
		subtree->rightchild = remove(subtree->leftchild, a, isSizeUpdated);
	}
	else
	{
		// tobedeleted may have both childs
		if (subtree->leftchild != NULL && subtree->rightchild != NULL)
		{
			// find max of leftsubtree
			node<AlpoType>* maxofLeft = findMax(subtree->leftchild);
			// set current node to max of left subtree
			subtree->item = maxofLeft->item;
			// since we have now same items in subtree, remove the maxofLeft by calling remove again
			subtree->leftchild = remove(subtree->leftchild, maxofLeft->item, isSizeUpdated);

			//alternatively
			//// find min of right subtree
			//node<AlpoType>* minofRight = findMin(subtree->rightchild);
			//// set current node to min of right subtree
			//subtree->item = minofRight->item;
			////since we have now same items in subtree, remove the minofRight by calling remove again
			//subtree->rightchild = remove(subtree->rightchild, minofRight->item);
		}

		// tobedeleted may have only leftchild
		else if (subtree->leftchild != NULL && subtree->rightchild == NULL)
		{
			node<AlpoType>* tobedeleted = subtree;
			subtree = subtree->leftchild;
			delete tobedeleted;
		}
		// tobedeleted may have only rightchild
		else if (subtree->leftchild == NULL && subtree->rightchild != NULL)
		{
			node<AlpoType>* tobedeleted = subtree;
			subtree = subtree->rightchild;
			delete tobedeleted;
		}
		// tobedeleted may not have any child
		else
		{
			delete subtree;
			subtree = NULL;			
		}
		if (isSizeUpdated != true)
		{
			isSizeUpdated = true;
			--size;			
		}
	}
	return subtree;
}

//returns the pointer of min element in BST
template <class AlpoType>
node<AlpoType>* TemplateBST<AlpoType>::findMin(node<AlpoType>* subtree) const
{
	while (subtree->leftchild != NULL)
	{
		subtree = subtree->leftchild;
	}
	return subtree;
}

//returns the pointer of max element in BST
template <class AlpoType>
node<AlpoType>* TemplateBST<AlpoType>::findMax(node<AlpoType>* subtree) const
{
	while (subtree->rightchild != NULL)
	{
		subtree = subtree->rightchild;
	}
	return subtree;
}

template <class AlpoType>
int TemplateBST<AlpoType>::currentmaxdepth(node<AlpoType>* subtree) const
{
	if (subtree == NULL)
	{
		return 0;
	}
	int leftdepth = currentmaxdepth(subtree->leftchild);
	int rightdepth = currentmaxdepth(subtree->rightchild);

	//if left is lesser, then choose right depth as max
	if (leftdepth < rightdepth)
	{
		return (1 + rightdepth);
	}
	return (1 + leftdepth);
}

template <class AlpoType>
int TemplateBST<AlpoType>::currentmindepth(node<AlpoType>* subtree) const
{
	if (subtree == NULL)
	{
		return 0;
	}
	int leftdepth = currentmindepth(subtree->leftchild);
	int rightdepth = currentmindepth(subtree->rightchild);

	//if left is greater, then choose right depth as min
	if (leftdepth > rightdepth)
	{
		return (1 + rightdepth);
	}
	return (1 + leftdepth);
}

template <class AlpoType>
void TemplateBST<AlpoType>::preorder(node<AlpoType>* subtree, AlpoType *& AlpoArray, int & index) const
{
	if (subtree == NULL)
	{
		--index;
		return;
	}
	AlpoArray[index] = subtree->item;
	preorder(subtree->leftchild, AlpoArray, (++index));
	preorder(subtree->rightchild, AlpoArray, (++index));
}

template <class AlpoType>
void TemplateBST<AlpoType>::inorder(node<AlpoType>* subtree, AlpoType *& AlpoArray, int & index) const
{
	if (subtree == NULL)
	{		
		return;
	}
	inorder(subtree->leftchild, AlpoArray, index);
	AlpoArray[index] = subtree->item;
	++index;
	inorder(subtree->rightchild, AlpoArray, index);
}

template <class AlpoType>
void TemplateBST<AlpoType>::postorder(node<AlpoType>* subtree, AlpoType *& AlpoArray, int & index) const
{
	if (subtree == NULL)
	{
		return;
	}
	postorder(subtree->leftchild, AlpoArray, index);
	postorder(subtree->rightchild, AlpoArray, index);
	AlpoArray[index] = subtree->item;
	++index;	
}

//public member functions
template <class AlpoType>
TemplateBST<AlpoType>::TemplateBST()
{
	root = NULL;
	size = 0;
}

template <class AlpoType>
TemplateBST<AlpoType>::TemplateBST(const TemplateBST & tree)
{
	root = tree.cloneBST(tree.root);
	size = tree.size;
}

template <class AlpoType>
TemplateBST<AlpoType>::~TemplateBST()
{
	clearSubtree(root);
}

template <class AlpoType>
void TemplateBST<AlpoType>::AddNewElement(const AlpoType & a)
{
	root = add(root, a);
	++size;
}

template <class AlpoType>
void TemplateBST<AlpoType>::RemoveElement(const AlpoType & a)
{	
	root = remove(root, a, false);
}

template <class AlpoType>
bool TemplateBST<AlpoType>::SearchElement(const AlpoType & a) const
{
	if (find(root, a) == NULL)
	{
		return false;
	}
	return true;
}

template <class AlpoType>
AlpoType TemplateBST<AlpoType>::GetMinElement() const
{
	return findMin(root)->item;
}

template <class AlpoType>
AlpoType TemplateBST<AlpoType>::GetMaxElement() const
{
	return findMax(root)->item;
}
template <class AlpoType>
int TemplateBST<AlpoType>::CalculateMaxDepth() const
{	
	return currentmaxdepth(root);
}

template <class AlpoType>
int TemplateBST<AlpoType>::CalculateMinDepth() const
{
	return currentmindepth(root);
}

template <class AlpoType>
int TemplateBST<AlpoType>::getSize() const
{
	return size;
}


template <class AlpoType>
AlpoType* TemplateBST<AlpoType>::pre_order_array() const
{
	AlpoType* AlpoArray = new AlpoType[size];
	int start = 0;
	preorder(root, AlpoArray, start);
	return AlpoArray;
}

template <class AlpoType>
AlpoType* TemplateBST<AlpoType>::in_order_array() const
{
	AlpoType* AlpoArray = new AlpoType[size];
	int start = 0;
	inorder(root, AlpoArray, start);
	return AlpoArray;
}

template <class AlpoType>
AlpoType* TemplateBST<AlpoType>::post_order_array() const
{
	AlpoType* AlpoArray = new AlpoType[size];
	int start = 0;
	postorder(root, AlpoArray, start);
	return AlpoArray;
}