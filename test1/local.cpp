#include <iostream>
using namespace std;

void Local(int*);

 

int main(void)

{

    int var = 10;

    cout << "initial var: " << var << endl;

 

    Local(&var);

    cout << "var after Local(): " << var;

    return 0;

}

 

void Local(int* num)
{

    *num += 10;
}