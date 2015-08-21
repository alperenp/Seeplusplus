/*
*
*	This file is generated by N. Alperen Pulur
*	21/08/2015     -     Istanbul
*	for questions related with source code : alperenp@sabanciuniv.edu
*
*	This is a Binary Search Tree implementation
*	The BST nodes contain template class type elements
*
*	Moreover, there are 3 important tree traversal algorithms are implemented.
*	namely; pre-order, in-order and post-order traversal
*/

#ifndef _TemplateBST_H
#define _TemplateBST_H
#include <iostream>
#include <vector>
template <class AlpoType>
struct node
{
	AlpoType item;
	node* leftchild;
	node* rightchild;
	node() :leftchild(NULL), rightchild(NULL){}
	node(AlpoType a) :item(a), leftchild(NULL), rightchild(NULL)
	{}	
};

template <class AlpoType>
class TemplateBST
{
private:
	node<AlpoType>* root;													//root of BST
	int size;																//number of elements in BST
	node<AlpoType>* cloneBST(node<AlpoType>* subtree) const;				//create a deep copy of current tree
	void clearSubtree(node<AlpoType>* subtree);								//delete all elements in given subtree
	
	//basic BST operations
	node<AlpoType>* add(node<AlpoType>* subtree, const AlpoType & a);		//recursive call for inserting new item to BST
	node<AlpoType>* find(node<AlpoType> * subtree, const AlpoType & a) const;		//search for node and returns its address
	node<AlpoType>* remove(node<AlpoType> * subtree, const AlpoType & a, bool & isSizeUpdated);//recursive call for removing the item from the BST
	
	//min & max functions
	node<AlpoType>* findMin(node<AlpoType>* subtree) const;					//finds the min element of given subtree
	node<AlpoType>* findMax(node<AlpoType>* subtree) const;					//finds the max element of given subtree
	
	//depth functions
	int currentmaxdepth(node<AlpoType>* subtree) const;						//returns the max depth of subtree
	int currentmindepth(node<AlpoType>* subtree) const;						//returns the min depth of subtree
	
	//tree traversal functions
	void preorder(node<AlpoType>* subtree, AlpoType *& AlpoArray, int & index) const;	//inserts elements to template array with respect to pre-oreder
	void inorder(node<AlpoType>* subtree, AlpoType *& AlpoArray, int & index) const;	//inserts elements to template array with respect to in-oreder
	void postorder(node<AlpoType>* subtree, AlpoType *& AlpoArray, int & index) const;	//inserts elements to template array with respect to post-oreder
public:
	TemplateBST();									//Default constructor
	TemplateBST(const TemplateBST & tree);			//Deep Copy constructor
	~TemplateBST();									//Destructor
	void AddNewElement(const AlpoType & a);			//Adds new element to BST if it is not in BST
	void RemoveElement(const AlpoType & a);			//Removes element from BST if exists
	bool SearchElement(const AlpoType & a) const;	//Searches for given element is in BST or not
	AlpoType GetMinElement() const;					//Gets the min element from BST
	AlpoType GetMaxElement() const;					//Gets the max element from BST
	int CalculateMaxDepth() const;					//Computes the max depth of BST
	int CalculateMinDepth() const;					//Computes the min depth of BST
	int getSize() const;							//Returns number of elements in BST

	// 3 important tree traversal
	AlpoType* pre_order_array() const;
	AlpoType* in_order_array() const;
	AlpoType* post_order_array() const;
};
#endif