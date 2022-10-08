#include "dirModule1/module1.h"
#include "dirModule2/module2.h"
#include "dirModule3/module3.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cout <<  "Hello world!" << "\n";

    cout << Module1::getMyName() << "\n";
    cout << Module2::getMyName() << "\n";

    cout << Module1::getMyName() << "\n"; // (A)
    cout << Module2::getMyName() << "\n";


    cout << Module2::getMyName() << "\n";

    cout << Module2::getMyName() << "\n"; // (D)

    cout << Module3::getMyName() << "\n";
}
