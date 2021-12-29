#include "Test.h"
#include "TList.h"
#include "catch2/catch.hpp"
#include <cstring>
#include <ctime>
#include <set>
#include <deque>
#include <iterator>

using namespace std;

TEST_CASE("Array overrided operators") {
    //cout << "Array overrided operators\n----------------------\n";
    
    Array arr1;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);
    //cout << "First array:\n" << arr1.toString() << "\n";
    
    Array arr2;
    arr2.add(90);
    arr2.add(67);
    arr2.add(23);
    arr2.add(87);
    //cout << "Second array:\n" << arr2.toString() << "\n";
    
    Array arr3;
    arr3 = arr1;
    //cout << "arr3 = arr1:\n" << arr3.toString() << "\n";
    
    char ch[32] = "1 2 3 \0";
    REQUIRE(strcmp(arr3.toString(), ch) == 0);


    arr3 = arr1 - 0;
    //cout << "Delete first element. arr1 - 0:\n" << arr3.toString() << "\n";
    
    char ch1[32] = "2 3 \0";
    REQUIRE(strcmp(arr3.toString(), ch1) == 0);

    --arr2;
    arr2--;
    //cout << "Second array double '--'\n" << arr2.toString() << "\n";
    
    char ch2[32] = "88 65 21 85 \0";
    REQUIRE(strcmp(arr2.toString(), ch2) == 0);

    arr3 = arr1 + arr2;
    //cout << "arr3 = arr1 + arr2:\n" << arr3.toString() << "\n";
    
    char ch3[32] = "2 3 88 65 21 85 \0";
    REQUIRE(strcmp(arr3.toString(), ch3) == 0);
    
    arr3 = arr3 - arr1;
    //cout << "arr3 = arr3 - arr1:\n" << arr3.toString() << "\n";
    
    char ch4[32] = "88 65 21 85 \0";
    REQUIRE(strcmp(arr3.toString(), ch4) == 0);

    //cout << "arr3[1] = " << arr3[1] << "\n";
    
    REQUIRE(arr3[1] == 65);

    arr3[1] = 23;
    //cout << "arr3[1] = 23:" << arr3[1] << "\n";
    
    REQUIRE(arr3[1] == 23);

    //cout << "Third array:\n" << arr3.toString() << "\n";

    char ch5[32] = "88 23 21 85 \0";
    REQUIRE(strcmp(arr3.toString(), ch5) == 0);

}


TEST_CASE("Array overrided in/output operators") {
    //cout << "Array overrided in/output operators\n----------------------\n";

    std::ofstream outArr("array.txt", std::ios::out);
        
    Array arrayTxtFile;
    
    Array array;
    array.add(3);
    array.add(838);
    array.add(6827);
    //cout << "Array initialization:\n" << array << "\n";
    
    array.toTxtFile("array.txt");
    
    arrayTxtFile.fromTxtFile("array.txt");
    //cout << "Array from .txt file:\n" << arrayTxtFile << "\n";
    
    char ch[32] = "3 838 6827 \0";
    REQUIRE(strcmp(arrayTxtFile.toString(), ch) == 0);  
}


TEST_CASE("Checking Queue") {
    //cout << "Checking Queue\n----------------------\n";
    //cout << "Initialization: ";
    Queue que;
    que.push(25);
    que.push(89);
    que.push(9);
    que.push(1);
    que.push(76);
    //cout << "\n" << que.toString() << std::endl;
    
    char ch[64] = "25-> 89-> 9-> 1-> 76-> \0";
    REQUIRE(strcmp(que.toString(), ch) == 0);

    int a = que.pop();
    //cout << "Using pop(): " << a << std::endl;
    a = que.pop();
    //cout << "Using pop(): " << a << std::endl;
    a = que.pop();
    //cout << "Using pop(): " << a << std::endl;
    //cout << "Result:\n" << que.toString() << std::endl;
    
    char ch1[64] = "1-> 76-> \0";
    REQUIRE(strcmp(que.toString(), ch1) == 0);

    //cout << "\n\n\n";
}

TEST_CASE("Cheking Map") {
    //cout << "Checking Map\n----------------------\n";
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
    //cout << "Initialization: ";
    //cout << "\n" << map.toString() << std::endl;

    char ch[64] = { "key1: 25\nkey2: 76\nkey3: 90\nkey4: 649\nkey5: 88\n" };
    REQUIRE(strcmp(map.toString(), ch) == 0);
        
    //cout << "Key 'key1' contain: " << map.getValue("key1") << std::endl;
    REQUIRE(map.getValue("key1") == 25);

    //cout << "Key index containing 90: " << map.findElement(90) << std::endl;
    REQUIRE(map.findElement(90) == 2);

    //cout << "Replace first element with 884\n";
    map.replace("key1", 884);

    //cout << "Key 'key1' contain: " << map.getValue("key1") << std::endl;
    REQUIRE(map.getValue("key1") == 884);

    //cout << "Delete element with key 'key2'\n";
    map.deleteElement("key2");
    //cout << "\n" << map.toString() << std::endl;

    char ch1[64] = { "key1: 884\nkey3: 90\nkey4: 649\nkey5: 88\n" };
    REQUIRE(strcmp(map.toString(), ch1) == 0);

    char** temp = map.getKeysArray();
    for (int i = 0; i < map.getIndex(); i++) {
        //cout << temp[i] << " ";

        char ch2[4][16] = { "key1", "key3", "key4", "key5" };
        REQUIRE(strcmp(temp[i], ch2[i]) == 0);
    }
    
    //cout << "\n---------------------------------\nChange keysArray, index and arraySize";
    map.setKeysArray(text);
    map.setIndex(3);
    map.setArraySize(5);
    
    //cout << "\n" << map.toString() << std::endl;

    char ch3[64] = { "message0: 884\nmessage1: 90\nmessage2: 649\n" };
    REQUIRE(strcmp(map.toString(), ch3) == 0);
    REQUIRE(map.getIndex() == 3);
    REQUIRE(map.getArraySize() == 5);
}


TEST_CASE("List testing")
{
    //cout << "Checking List\n----------------------\n";
    //cout << "Array nitialization: \n";
    Array arr1;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);
    //cout << arr1.toString() << "\n";

    //cout << "Queue nitialization: \n";
    Queue queue;
    queue.push(45);
    queue.push(68);
    queue.push(19);
    queue.push(80);
    //cout << queue.toString() << "\n";

    //cout << "Map nitialization: \n";
    Map map;
    map.add("key1", 677);
    map.add("key2", 283);
    map.add("key3", 425);
    map.add("key4", 649);
    //cout << map.toString() << "\n\n";

    //cout << "List nitialization: \n";
    List list;
    list.add(arr1);
    list.add(queue);
    list.insert(map, 0);
    //cout << list.toString() << "\n";

    char ch[128] = "key1: 677\nkey2: 283\nkey3: 425\nkey4: 649\n==> 1 2 3 ==> 45-> 68-> 19-> 80-> ==> \0";
    REQUIRE(strcmp(list.toString(), ch) == 0);

    //cout << "Delete list last element:\n";
    list.del();
    //cout << list.toString() << "\n";

    char ch1[128] = "key1: 677\nkey2: 283\nkey3: 425\nkey4: 649\n==> 1 2 3 ==> \0";
    REQUIRE(strcmp(list.toString(), ch1) == 0);
    
    //cout << "Delete list first element:\n";
    list.deleteByIndex(0);
    //cout << list.toString() << "\n";

    char ch2[32] = "1 2 3 ==> \0";
    REQUIRE(strcmp(list.toString(), ch2) == 0);
}


TEST_CASE("TList test int") {
    //cout << "Checking template List with int\n----------------------\n";

    int num1 = 1;
    int num2 = 9;
    int num3 = 8;
    int num4 = 4;

    //cout << "TList initialization: \n";
    TList<int> list;
    list.add(&num1);
    list.add(&num2);
    list.add(&num4);
    list.add(&num3, 2);
    //cout << list.toString() << endl;

    char ch1[32] = "1 ==> 9 ==> 8 ==> 4 ==> \0";
    REQUIRE(strcmp(list.toString(), ch1) == 0);

    int a = *(list.getElement(0));
    //cout << "First element: " << a << "\n";
    REQUIRE(a == 1);

    bool isEmpty = list.isEmpty();
    //cout << "TList is empty: " << isEmpty << "\n";
    REQUIRE(isEmpty == false);

    list.del();
    //cout << "Delete first element:\n" << list.toString() << "\n";

    char ch2[32] = "9 ==> 8 ==> 4 ==> \0";
    REQUIRE(strcmp(list.toString(), ch2) == 0);

    list.del(1);
    //cout << "Delete second element:\n" << list.toString() << "\n";
    
    char ch3[32] = "9 ==> 4 ==> \0";
    REQUIRE(strcmp(list.toString(), ch3) == 0);

    //cout << endl;
}

TEST_CASE("TList test float") {
    //cout << "Checking template List with float\n----------------------\n";
    float num1 = 1.90;
    float num2 = 9.97;
    float num3 = 8.35;
    float num4 = 43.56;

    //cout << "TList initialization: \n";
    TList<float> list;
    list.add(&num1);
    list.add(&num2);
    list.add(&num3);
    list.add(&num4);
    //cout << list.toString() << endl;

    char ch[64] = "1.900000 ==> 9.970000 ==> 8.350000 ==> 43.560001 ==> \0";
    REQUIRE(strcmp(list.toString(), ch) == 0);

    int a = *(list.getElement(0));
    //cout << "First element: " << a << "\n";
    REQUIRE(a == 1);

    bool isEmpty = list.isEmpty();
    //cout << "TList is empty: " << isEmpty << "\n";
    REQUIRE(isEmpty == false);

    list.del();
    //cout << "Delete first element:\n" << list.toString() << "\n";

    char ch1[64] = "9.970000 ==> 8.350000 ==> 43.560001 ==> \0";
    REQUIRE(strcmp(list.toString(), ch1) == 0);

    list.del(1);
    //cout << "Delete second element:\n" << list.toString() << endl;

    char ch2[32] = "9.970000 ==> 43.560001 ==> \0";
    REQUIRE(strcmp(list.toString(), ch2) == 0);

    //cout << endl;
}

TEST_CASE("TList test Array") {
    //cout << "Checking template List with Array\n----------------------\n";
    Array arr1;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);

    Array arr2;
    arr2.add(45);
    arr2.add(68);
    arr2.add(19);
    arr2.add(80);

    Array arr3;
    arr3.add(677);
    arr3.add(283);
    arr3.add(425);
    arr3.add(649);

    //cout << "TList initialization: \n";
    TList<Array> list;
    list.add(&arr1);
    list.add(&arr2);
    list.add(&arr3);
    //cout << list.toString() << endl;

    char ch[64] = "1 2 3 ==> 45 68 19 80 ==> 677 283 425 649 ==> \0";
    REQUIRE(strcmp(list.toString(), ch) == 0);

    Array a = *(list.getElement(0));
    //cout << "First element: " << a << "\n";
    REQUIRE(strcmp(a.toString(), "1 2 3 ") == 0);

    bool isEmpty = list.isEmpty();
    //cout << "TList is empty: " << isEmpty << "\n";
    REQUIRE(isEmpty == false);

    list.del();
    //cout << "Delete first element:\n" << list.toString() << "\n";

    char ch2[64] = "45 68 19 80 ==> 677 283 425 649 ==> \0";
    REQUIRE(strcmp(list.toString(), ch2) == 0);

    //cout << endl;
}




// dequeue and set with array and int
/*
TEST_CASE("Test STL Deque with Array") {
    cout << endl;
    Array arr1;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);

    Array arr2;
    arr2.add(45);
    arr2.add(68);
    arr2.add(19);
    arr2.add(80);

    Array arr3;
    arr3.add(677);
    arr3.add(283);
    arr3.add(425);
    arr3.add(649);

    deque<Array> deq;
    deq.push_back(arr1);
    deq.push_back(arr2);
    deq.push_front(arr3);

    char ch[64] = "677 283 425 649 ==> 1 2 3 ==> 45 68 19 80 ==> \0";
    char* st = new char[128];
    st[0] = '\0';
    for (Array a : deq) {
        char* str = a.toString();
        strcat_s(st, 128, str);
        strcat_s(st, 128, " ==> \0");
    }

    cout << st << endl;
    REQUIRE(strcmp(ch, st) == 0);
    //copy(mySet.begin(), mySet.end(), ostream_iterator<Array>(cout, " "));
    delete st;

    deq.pop_front();
    deq.pop_back();
    //copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));

    char ch1[64] = "1 2 3 ==> \0";
    st = new char[64];
    st[0] = '\0';
    for (Array a : deq) {
        char* str = a.toString();
        strcat_s(st, 128, str);
        strcat_s(st, 128, " ==> \0");
    }
    cout << st << endl;

    REQUIRE(strcmp(ch1, st) == 0);

    cout << endl;
    //delete st;
}
*/
/*
TEST_CASE("Test STL Set with Array") {
    cout << endl;

    Array arr1;
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);

    Array arr2;
    arr2.add(45);
    arr2.add(68);
    arr2.add(19);
    arr2.add(80);

    Array arr3;
    arr3.add(677);
    arr3.add(283);
    arr3.add(425);
    arr3.add(649);

    set<Array> mySet;
    mySet.insert(arr1);
    mySet.insert(arr2);
    mySet.insert(arr3);

    char ch[64] = "1 2 3 ==> 45 68 19 80 ==> 677 283 425 649 \0";
    char* st = new char[128];
    st[0] = '\0';
    set<Array> ::iterator it = mySet.begin();
    for (int i = 1; it != mySet.end(); i++, it++) {
        Array a(*it);
        char* str = a.toString();
        strcat_s(st, 128, str);
        strcat_s(st, 128, " ==> \0");
    }

    cout << st << endl;
    REQUIRE(strcmp(ch, st) == 0);
    //copy(mySet.begin(), mySet.end(), ostream_iterator<Array>(cout, " "));
    delete st;

    mySet.erase(arr1);
    mySet.erase(mySet.find(arr2));
    //copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));

    char ch1[64] = "677 283 425 649 \0";
    st = new char[64];
    st[0] = '\0';
    it = mySet.begin();
    for (int i = 1; it != mySet.end(); i++, it++) {

    }
    cout << st << endl;

    //REQUIRE(strcmp(ch1, st) == 0);

    cout << endl;
    //delete st;
}
*/
/*
TEST_CASE("Test STL Set with int") {
    set<int> mySet;
    mySet.insert(5);
    mySet.insert(9);
    mySet.insert(64);
    mySet.insert(2);

    char ch[64] = "2 5 9 64 \0";
    char* st = new char[64];
    st[0] = '\0';
    set<int> ::iterator it = mySet.begin();
    for (int i = 1; it != mySet.end(); i++, it++) {
        char val[10] = "";
        _itoa_s(*it, val, 10);
        strcat_s(st, 64, val);
        strcat_s(st, 64, " \0");
    }

    //cout << st << endl;
    REQUIRE(strcmp(ch, st) == 0);
    //copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
    delete st;

    mySet.erase(2);
    mySet.erase(mySet.find(9));
    //copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));

    char ch1[64] = "5 64 \0";
    st = new char[64];
    st[0] = '\0';
    it = mySet.begin();
    for (int i = 1; it != mySet.end(); i++, it++) {
        char val[10] = "";
        _itoa_s(*it, val, 10);
        strcat_s(st, 64, val);
        strcat_s(st, 64, " \0");
    }
    //cout << st << endl;

    REQUIRE(strcmp(ch1, st) == 0);

    //cout << endl;
    delete st;
}

TEST_CASE("Test STL Deque with int") {
    deque<int> deq;
    deq.push_back(8);
    deq.push_back(4);
    deq.push_front(9);
    deq.push_front(1);

    char ch[64] = "1 9 8 4 \0";
    char* d = new char[64];
    d[0] = '\0';
    for (int n : deq) {
        //cout << n << " ";

        char val[10] = "";
        _itoa_s(n, val, 10);
        strcat_s(d, 64, val);
        strcat_s(d, 64, " \0");
    }

    //cout << endl;
    REQUIRE(strcmp(ch, d) == 0);
    delete d;
    //copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));

    deq.pop_front();
    deq.pop_back();
    //copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));

    char ch1[64] = "9 8 \0";
    d = new char[64];
    d[0] = '\0';
    for (int n : deq) {
        //cout << n << " ";

        char val[10] = "";
        _itoa_s(n, val, 10);
        strcat_s(d, 64, val);
        strcat_s(d, 64, " \0");
    }

    REQUIRE(strcmp(ch1, d) == 0);

    //cout << endl;
    delete d;
}
*/