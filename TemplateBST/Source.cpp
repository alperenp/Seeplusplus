#include "TemplateBST.cpp"

using namespace std;

int main()
{
	TemplateBST<int> intbst;
	intbst.AddNewElement(12);
	intbst.AddNewElement(5);
	intbst.AddNewElement(15);
	intbst.AddNewElement(3);
	intbst.AddNewElement(7);
	intbst.AddNewElement(13);
	intbst.AddNewElement(17);
	intbst.AddNewElement(1);
	intbst.AddNewElement(9);
	
	int* AlpoA = intbst.pre_order_array();
	for (int i = 0; i < intbst.getSize(); i++)
	{
		cout << AlpoA[i] << " ";
	}
	delete [] AlpoA;	
	return 0;
}