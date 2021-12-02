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

void Test::test5()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 5: Checking Map and Queue\n\n";

    int arr1[] = { 79, 57, 80 };
    int* arr = arr1;

    char** text = new char*[3];
    
    int i;
    for (i = 0; i < 3; i++) {
        char temp[10] = "";
        char* ch = new char[10];
        sprintf_s(temp, "message%d", i);
        strcpy_s(ch, sizeof(temp), temp);
        text[i] = ch;
    }

    Map map;
    map.add("key1", 25);
    map.add("key2", 76);
    map.add("key3", 90);
    map.add("key4", 649);
    map.add("key5", 88);
    cout << "\n" << map.toString() << std::endl;

    cout << "Key 'key1' contain: " << map.getValue("key1") << std::endl;
    cout << "First key containing value 90: " << map.findElement(90) << std::endl;
    
    cout << "Replace first element with 884\n";
    map.replace("key1", 884);

    cout << "\n" << map.toString() << std::endl;
    
    cout << "Delete element with key 'key2'\n";
    map.deleteElement("key2");
    cout << "\n" << map.toString() << std::endl;

    char** temp = map.getKeysArray();
    for (int i = 0; i < map.getIndex(); i++) {
        cout << temp[i] << " ";
    }

    cout << "\n---------------------------------\nChange keysArray, index and arraySize";
    map.setKeysArray(text);
    map.setIndex(3);
    map.setArraySize(5);

    cout << "\n" << map.toString() << std::endl;

    cout << "\n---------------------------------\n";
    cout << "Checking Queue work\n";

    Queue que;
    que.push(25);
    que.push(89);
    que.push(9);
    que.push(1);
    que.push(76);
    cout << "\n" << que.toString() << std::endl;
    
    int* expectedArray = new int[que.getArraySize()]{ 25, 89, 9, 1, 76 };
    int* ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(que, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << que.pop() << std::endl;
    cout << que.pop() << std::endl;
    cout << que.pop() << std::endl;
    cout << que.toString() << std::endl;

    expectedArray = new int[que.getArraySize()]{ 1, 76 };
    ptrExpectedArray = expectedArray;
    cout << "\nExpected and real array is equal: " << equal(que, ptrExpectedArray) << "\n";
    delete[] expectedArray;
}

void Test::test6()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 6: Checking List and Virtual\n\n";

    Array arr1;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);

    Queue queue;
    queue.push(45);
    queue.push(68);
    queue.push(19);
    queue.push(80);

    Map map;
    map.add("key1", 677);
    map.add("key2", 283);
    map.add("key3", 425);
    map.add("key4", 649);

    List list;
    list.add(arr1);
    list.add(queue);
    list.insert(map, 0);
    cout << "Initial list\n";
    cout << list.toString() << "\n";

    Array arr = list.getElement(1);
    cout << "Second element is \n" << arr.toString() << "\n";

    cout << "Index of map is " << list.find(map) << "\n";

    cout << "Deleting head\n";
    list.deleteByIndex(0);
    cout << list.toString() << "\n";

    cout << "Deleting last element\n";
    list.del();
    cout << list.toString() << "\n";

    
    cout << "--------------------------------------\nCheking of Virtual function toString\n\n";
    cout << "Create Queue\n";
    Queue qu;
    qu.push(25);
    qu.push(90);
    Array& arr3 = qu;
    cout << "Calling inheritor function 'toString()' from a parent\n";
    cout << arr3.toString() << "\n";
    cout << "Calling inheritor function 'toString()' from a child\n";
    cout << qu.toString() << "\n";
    
}

void Test::test7()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 7: Checking Operators\n\n";
    
    cout << "Checking Array\n\n";

    Array arr1;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);
    cout << "First array:\n" << arr1.toString() << "\n";

    Array arr2;
    arr2.add(90);
    arr2.add(67);
    arr2.add(23);
    arr2.add(87);
    cout << "Second array:\n" << arr2.toString() << "\n";

    Array arr3;
    arr3 = arr1;
    cout << "Third array:\n" << arr3.toString() << "\n";

    arr3 = arr1 - 0;
    cout << "Delete first element with different:\n" << arr3.toString() << "\n";

    --arr2;
    arr2--;
    cout << "Second array after '--'\n" << arr2.toString() << "\n";

    arr3 = arr1 + arr2;
    cout << "First array plus second:\n" << arr3.toString() << "\n";

    arr3 = arr3 - arr1;
    cout << "Third array minus first:\n" << arr3.toString() << "\n";

    arr3[1] = 23;
    cout << "arr3[1] = " << arr3[1] << "\n";
    cout << "Third array:\n" << arr3.toString() << "\n";


    cout << "--------------------------------------\nCheking Queue\n\n";

    Queue q1;
    q1.push(45);
    q1.push(68);
    q1.push(19);
    q1.push(80);
    cout << "First queue:\n" << q1.toString() << "\n";

    Queue q2;
    q2.push(234);
    q2.push(654);
    q2.push(909);
    q2.push(803);
    cout << "Second queue:\n" << q2.toString() << "\n";

    Queue q3;
    q3 = q2;
    cout << "Third queue equal to second:\n" << q3.toString() << "\n";

    q3 = q1 + q2;
    cout << "First queue plus second:\n" << q3.toString() << "\n";

    q3 = q3 - q1;
    cout << "Third queue minus fisrt:\n" << q3.toString() << "\n";

    q3--;
    --q3;
    cout << "Third queue:\n" << q3.toString() << "\n";

    cout << "--------------------------------------\nCheking Map\n\n";
    Map map3;
    Map map1;
    map1.add("key1", 677);
    map1.add("key2", 283);
    map1.add("key3", 425);
    map1.add("key4", 649);
    cout << "First map:\n" << map1.toString() << "\n";

    Map map2;
    map2.add("code1", 9899);
    map2.add("code2", 3721);
    map2.add("code3", 7866);
    map2.add("code4", 6728);
    cout << "Second map:\n" << map2.toString() << "\n";

    map3 = map2;
    cout << "Third map equal to second:\n" << map3.toString() << "\n";

    map3 = map2 + map1;
    cout << "First map plus second:\n" << map3.toString() << "\n";

    map3 = map3 - map2;
    cout << "Third map minus second:\n" << map3.toString() << "\n";

    map3--;
    --map3;
    map3["key1"] = 666;
    cout << "map3[\"key1\"] = " << map3["key1"] << "\n";

    map3 = map3 - "key2";
    cout << "Third map:\n" << map3.toString() << "\n";

}

void Test::test8()
{
    cout << "\n==============================================\n\n";
    cout << "Test number 8: Checking override input and output operators\n\n";

    cout << "Checking Array\n\n";
    Array arr;
    //std::cin >> arr;
    //cout << arr << "\n";

    cout << "--------------------------------------\nCheking Queue\n\n";
    Queue queue;
    /*
    std::cin >> queue;
    cout << queue << "\n";
    */


    cout << "--------------------------------------\nCheking Map\n\n";
    Map map;
    std::cin >> map;
    cout << map << "\n";
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
