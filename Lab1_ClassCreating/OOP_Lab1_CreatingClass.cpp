#include <iostream>
#include "Array.h"
#include "Test.h"

using std::cout;

int main()
{
    setlocale(LC_ALL, "");
    cout << "Тест номер 1\n\n";
    Test::test1();

    cout << "\n==============================================\n\n";

    cout << "Тест номер 2\n\n";
    Test::test2();
}