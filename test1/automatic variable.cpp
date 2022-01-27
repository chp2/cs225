#include <iostream>
using namespace std;

void Local(void);

int main(void)
{
	int i = 5;
	int var = 10;
	cout << "automatic variable in main(): " << var << endl;
	
	if (i < 10)
	{
		Local();
		int var = 30;
		cout << "automatic variable in if statement: " << var << endl;
	}
	cout << "current automatic variable: " << var << endl;
	return 0;
}

void Local(void)
{
	int var = 20;
	cout << "automatic variable at Local(): " << var << endl;
}