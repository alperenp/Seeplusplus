/*
*	An example .cpp file to see how sort algorithm works
*/

#include <string>
#include <iostream>
using namespace std;
#include "LinkedList.cpp"
int main()
{
	LinkedList<int> list;
	list.addToEnd(61);
	list.addToEnd(109);
	list.addToEnd(149);
	list.addToEnd(111);
	list.addToEnd(34);
	list.addToEnd(2);
	list.addToEnd(24);
	list.addToEnd(119);
	list.addToEnd(122);
	list.addToEnd(125);
	list.addToEnd(27);
	list.addToEnd(145);


	list.bubbleSort(); // call sorting here
	
	list.Print();
	return 0;
}