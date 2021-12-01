#include <iostream>
#include "Array.h"
#include "Queue.h"
#include "List.h"
#include "Test.h"

using std::cout;

int main()
{
    setlocale(LC_ALL, "");
    /*
    Test::test1();

    Test::test2();

    Test::test3();

    try {
        Test::test4();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }


    try {
        Test::test5();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }
    

    try {
        Test::test6();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }
    */

    try {
        Test::test7();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    /*
    Map map;
    map.add("key1", 25);
    map.add("key2", 76);
    map.add("key3", 90);
    map.add("key4", 649);
    map.add("key5", 88);

    Map map1;
    map1 = map;
    cout << "\n" << map1.toString() << std::endl;
    */
}