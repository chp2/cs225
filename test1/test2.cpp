#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x;
    cout << ""how many legs?" << endl;
    cin >> x;

    switch (x)
    {
        case 1:
        cout << "you are a pirate" << endl;
        break;
        case 2:
        cout << "You are human" << endl;
        break;
        default:
        
    }
    system("pause");
    return 0;
}