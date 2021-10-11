#include <iostream>
#include "Array.h"
#include "Test.h"

using std::cout;

int main()
{
    setlocale(LC_ALL, "");
    
    Test::test1();

    Test::test2();

    Test::test3();

    try {
        Test::test4();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }
}