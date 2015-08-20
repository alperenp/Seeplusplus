#include "TemplateStack.cpp"
#include <string>
using namespace std;

//Output:
// 2
// 1
int main()
{
	TemplateStack<int> mystck;
	mystck.push(1);
	mystck.push(2);

	while (mystck.isEmpty() == false)
	{
		cout << to_string(mystck.pop()) << endl;
	}
	return 0;
}