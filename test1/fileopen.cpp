#include <iostream>

#include <fstream>

#include <string>

using namespace std;

 

int main()

{

    ifstream ifs;

    string str;

 

    ifs.open("address.txt"); // "C++ 프로그래밍"

    if(!ifs.is_open())

    {

        cout << "Cannot open the file!" << endl;

        exit(1);

    }

    else

    {

        cout << "Success!" << endl;

        //getline(ifs, str);
        ifs >> str;

        cout << str << endl;

        ifs.close();

    }
    return 0;
}