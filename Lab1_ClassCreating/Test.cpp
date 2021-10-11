#include "Test.h"

void Test::test1()
{
    cout << "\n==============================================\n\n";
    cout << "Test nimber 1: Checking classes methods\n\n\n";

    int array[15] = { 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69 };
    int* ptrArray = array;
    Array myArr(15, 11, ptrArray);

    cout << "Initial array: " << myArr.toString() << "\n\n";

    cout << "Add number 76, 77 at the array start\n";
    try {
        myArr.add(76, 0);
        myArr.add(77, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Add number 24 at the array end\n";
    myArr.add(24);
    cout << "Add number 45 at the array end\n";
    myArr.add(45);
    cout << "Add number 9 at the array end\n";
    myArr.add(9);
    cout << "Add number 780 at the array end\n";
    myArr.add(780);
    cout << std::endl << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 77, 76, 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69, 24, 45, 9, 780 };
    int* ptrExpectedArray = expectedArray;
    cout << "Expected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "Two times delete element with index 0\n";
    try {
        myArr.deleteElement(0);
        myArr.deleteElement(0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Collaps array to the last not null element\n";
    myArr.collapse();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;

    expectedArray = new int[myArr.getArraySize()]{ 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69, 24, 45, 9, 780 };
    ptrExpectedArray = expectedArray;
    cout << "Expected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "Sort array\n";
    myArr.sort();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    try {
        cout << "Index: " << myArr.getIndex() << ", The last not null element: " << myArr.getElement(myArr.getIndex() - 1)
            << ", Max array size: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";

    }

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    cout << "Number '69' meets at the element with index " << myArr.findElement(69) << std::endl;

    try {
        myArr.replace(675838, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }
    cout << "\nReplace element with index 0\n" << myArr.toString() << std::endl;

    expectedArray = new int[myArr.getArraySize()]{ 675838, 3, 3, 5, 9, 12, 24, 45, 69, 83, 85, 453, 659, 780, 6549 };
    ptrExpectedArray = expectedArray;
    cout << "Expected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

}

void Test::test2()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 2: Checking classes methods and exceptions works\n\n\n";

    Array myArr;

    cout << "Index: " << myArr.getIndex() << ", The last not null element: " << myArr.getElement(myArr.getIndex())
        << ", Max array size: " << myArr.getArraySize();

    cout << "\nAdd number 85 at the array end\n";
    myArr.add(85);
    cout << "Add number 7 at the array end\n";
    myArr.add(7);
    cout << "Add number 934 at the array end\n";
    myArr.add(934);
    cout << "Add number 2 at the array start\n";

    try {
        myArr.add(2, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";

    }

    cout << "Add number 24 at the array end\n";
    myArr.add(34);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 2, 85, 7, 934, 34 };
    int* ptrExpectedArray = expectedArray;
    cout << "Expected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";

    cout << "Change Max array size to 10, then to -1\n";
    try {
        myArr.setArraySize(10);
        myArr.setArraySize(-1);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Change Index to 0, than to number bigger Max array size\n";    
    try {
        myArr.setIndex(0);
        myArr.setIndex(myArr.getArraySize() + 20);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Current Max array size: " << myArr.getArraySize() << std::endl;
    cout << "Current Index: " << myArr.getIndex() << std::endl;
    
    cout << "Change array pointer\n";
    int* arr = new int[myArr.getArraySize()];
    myArr.setPtrArray(arr);

    cout << "Fill new array\n\n";
    myArr.add(62);
    myArr.add(5);
    myArr.add(485);
    myArr.add(313);
    myArr.add(899);
    myArr.add(236);
    myArr.add(200);

    try {
        cout << "Index: " << myArr.getIndex() << ", The last no null: " << myArr.getElement(myArr.getIndex() - 1)
            << ", Max array siz: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    expectedArray = new int[myArr.getArraySize()]{ 62, 5, 485, 313, 899, 236, 200 };
    ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";
}

void Test::test3()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 3: Checking exception works\n\n\n";

    Array myArr;

    try {
        cout << "Index: " << myArr.getIndex() << ", The last not null element: " << myArr.getElement(myArr.getIndex())
            << ", Max array size: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "\nAdd number 289 at the array end\n";
    myArr.add(289);
    cout << "Add number 8 at the array end\n";
    myArr.add(8);
    cout << "Add number 12 at the array end\n";
    myArr.add(12);
    cout << "Add number 3 at the array start\n";

    try {
        myArr.add(3, 0);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Add number 48 at the array end\n";
    myArr.add(48);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 3, 289, 8, 12, 48 };
    int* ptrExpectedArray = expectedArray;
    cout << "Expected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";
    
    cout << "Change Max array size to 10, then to -1\n";
    try {
        myArr.setArraySize(10);
        myArr.setArraySize(-1);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }
    cout << "Try to change Index to number bigger max array size\n";

    try {
        myArr.setIndex(myArr.getArraySize() + 20);
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    cout << "Add numbers 86, 94, 4 at the array end\n";
    myArr.add(86);
    myArr.add(94);
    myArr.add(4);

    try {
        cout << "Index: " << myArr.getIndex() << ", The last not null element: " << myArr.getElement(myArr.getIndex() - 1)
            << ", Max array size: " << myArr.getArraySize();
    }
    catch (ArrayException& e) {
        cout << "==================================\n" << e.what() << "\n==================================\n";
    }

    expectedArray = new int[myArr.getArraySize()]{ 3, 289, 8, 12, 48, 86, 94, 4 };
    ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";
}

void Test::test4()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 4: Checking exception works (stops on exception)\n\n\n";

    Array myArr;

    cout << "Index: " << myArr.getIndex() << ", The last not null element: " << myArr.getElement(myArr.getIndex())
        << ", Max array size: " << myArr.getArraySize();

    cout << "\nAdd number 57 at the array end\n";
    myArr.add(57);
    cout << "Add number 80 at the array end\n";
    myArr.add(80);
    cout << "Add number 903 at the array end\n";
    myArr.add(903);
    cout << "Add number 79 at the array start\n";
    myArr.add(79, 0);

    cout << "Add number 99 at the array end\n";
    myArr.add(99);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 79, 57, 80, 903, 99 };
    int* ptrExpectedArray = expectedArray;
    cout << "Expected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";
    
    cout << "Change Max array size to 10, then to -1\n";
    myArr.setArraySize(10);
    myArr.setArraySize(-1);
    cout << "Try to change Index to number bigger max array size\n";

    myArr.setIndex(myArr.getArraySize() + 20);

    cout << "Add numbers 30, 89, 11 at the array end\n";
    myArr.add(30);
    myArr.add(89);
    myArr.add(11);

    cout << "Index: " << myArr.getIndex() << ", The last not null element: " << myArr.getElement(myArr.getIndex() - 1)
        << ", Max array size: " << myArr.getArraySize();

    expectedArray = new int[myArr.getArraySize()]{ 79, 57, 80, 903, 99, 30, 89, 11 };
    ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";
}

bool Test::equal(Array& array, int* expectedArray)
{
    int* realArray = array.getPtrArray();
    int i = 0;
    while (*expectedArray > 0 && *realArray > 0 && i < array.getIndex()) {
        if (*expectedArray != *realArray) {
            break;
        }
        else {
            if (*(expectedArray + 1) <= 0 && *(realArray + 1) <= 0) {
                return true;
            }
            if (i >= array.getIndex()) {
                break;
            }
        }
        expectedArray++;
        realArray++;
        i++;
    }

    return false;
}
