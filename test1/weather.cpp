#include <iostream>
#include <string>
using namespace std;
 
enum Weather {DONG, KURO};

int main(void)

{

    int input;

    Weather wt;

 
/*
    cout << "input : " << endl;

    cout << "(SUNNY=0, CLOUD=10, RAIN=20, SNOW=30)" << endl;

    cin >> input;

    wt = (Weather)input;
    */
    wt = KURO;

 

    switch (wt)

    {

        case DONG:

            cout << "Dong" << endl;
            cout << DONG;

            break;

        case KURO:

            cout << "Kuro" << endl;
            cout << KURO;

            break;

        default:

            cout << "different";

            break;

    }


    return 0;

}