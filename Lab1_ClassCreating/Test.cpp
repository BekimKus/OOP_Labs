#include "Test.h"
#include "TList.h"
#include "catch2/catch.hpp"
#include <cstring>
#include <ctime>
#include <set>
#include <deque>
#include <iterator>

using namespace std;

TEST_CASE("List testing")
{
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
    //cout << list.toString() << "\n";

    list.del();
    //cout << list.toString() << "\n";

    list.deleteByIndex(0);
    //cout << list.toString() << "\n";

    int size = strlen(list.toString()) + 1;
    char ch[32] = "1 2 3 ==> \0";
    REQUIRE(strcmp(list.toString(), ch) == 0);
}

TEST_CASE("TList test int") {
    int num1 = 1;
    int num2 = 9;
    int num3 = 8;
    int num4 = 4;

    TList<int> list;
    list.add(&num1);
    list.add(&num2);
    list.add(&num4);
    list.add(&num3, 2);
    //cout << list.toString() << endl;

    char ch1[32] = "1 ==> 9 ==> 8 ==> 4 ==> \0";
    REQUIRE(strcmp(list.toString(), ch1) == 0);

    int a = *(list.getElement(0));
    REQUIRE(a == 1);

    bool isEmpty = list.isEmpty();
    REQUIRE(isEmpty == false);

    list.del();
    list.del(1);
    //cout << list.toString() << endl;

    char ch2[32] = "9 ==> 4 ==> \0";
    REQUIRE(strcmp(list.toString(), ch2) == 0);

    //cout << endl;
}

TEST_CASE("TList test float") {
    float num1 = 1.90;
    float num2 = 9.97;
    float num3 = 8.35;
    float num4 = 43.56;

    TList<float> list;
    list.add(&num1);
    list.add(&num2);
    list.add(&num3);
    list.add(&num4);
    //cout << list.toString() << endl;

    char ch[64] = "1.900000 ==> 9.970000 ==> 8.350000 ==> 43.560001 ==> \0";
    REQUIRE(strcmp(list.toString(), ch) == 0);

    float a = *(list.getElement(0));
    REQUIRE(a == 1.90f);

    bool isEmpty = list.isEmpty();
    REQUIRE(isEmpty == false);

    list.del();
    list.del(1);
    //cout << list.toString() << endl;

    char ch2[32] = "9.970000 ==> 43.560001 ==> \0";
    REQUIRE(strcmp(list.toString(), ch2) == 0);

    //cout << endl;
}

TEST_CASE("TList test Array") {
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

    TList<Array> list;
    list.add(&arr1);
    list.add(&arr2);
    list.add(&arr3);
    //listArray.show();
    //cout << list.toString() << endl;

    char ch[64] = "1 2 3 ==> 45 68 19 80 ==> 677 283 425 649 ==> \0";
    REQUIRE(strcmp(list.toString(), ch) == 0);

    Array a = *(list.getElement(0));
    REQUIRE(strcmp(a.toString(), "1 2 3 ") == 0);

    bool isEmpty = list.isEmpty();
    REQUIRE(isEmpty == false);

    list.del();
    //cout << list.toString() << endl;

    char ch2[64] = "45 68 19 80 ==> 677 283 425 649 ==> \0";
    REQUIRE(strcmp(list.toString(), ch2) == 0);

    //cout << endl;
}

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

    cout << st << endl;
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
    cout << st << endl;

    REQUIRE(strcmp(ch1, st) == 0);

    cout << endl;
    delete st;
}

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
        cout << n << " ";

        char val[10] = "";
        _itoa_s(n, val, 10);
        strcat_s(d, 64, val);
        strcat_s(d, 64, " \0");
    }

    cout << endl;
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
        cout << n << " ";

        char val[10] = "";
        _itoa_s(n, val, 10);
        strcat_s(d, 64, val);
        strcat_s(d, 64, " \0");
    }

    REQUIRE(strcmp(ch1, d) == 0);

    cout << endl;
    delete d;
}


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