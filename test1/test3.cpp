#include <iostream>
#include <string>
#define ADD(X,Y) X.append(Y)
using namespace std;

int main(void)
{
	int num1 = 5, num2 = 3;
	
    string result;
    string h = "hi";
	//result = ADD("hi", num2+10);
    result = ADD(h,"13");
    cout << result;
    return 0;
}