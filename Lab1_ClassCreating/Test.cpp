#include "Test.h"

void Test::test1()
{
    cout << "\n==============================================\n\n";
    cout << "���� ����� 1: �������� ������� ������\n\n\n";

    int array[15] = { 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69 };
    int* ptrArray = array;
    Array myArr(15, 11, ptrArray);

    cout << "����������� ������: " << myArr.toString() << "\n\n";

    cout << "������� ����� 76 � ������ �������\n";
    myArr.add(76, 0);
    cout << "������� ����� 77 � ������ �������\n";
    myArr.add(77, 0);
    cout << "������� ����� 24 � ����� �������\n";
    myArr.add(24);
    cout << "������� ����� 45 � ����� �������\n";
    myArr.add(45);
    cout << "������� ����� 9 � ����� �������\n";
    myArr.add(9);
    cout << "������� ����� 780 � ����� �������\n";
    myArr.add(780);
    cout << std::endl << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 77, 76, 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69, 24, 45, 9, 780 };
    int* ptrExpectedArray = expectedArray;
    cout << "��������� ������ � �������� ��������: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "��� ���� ������ ������� � �������� 0\n";
    myArr.deleteElement(0);
    myArr.deleteElement(0);

    cout << "������ ������ �� ���������� ���������� ��������\n";
    myArr.collapse();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;

    expectedArray = new int[myArr.getArraySize()]{ 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69, 24, 45, 9, 780 };
    ptrExpectedArray = expectedArray;
    cout << "��������� ������ � �������� ��������: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "����������� ������\n";
    myArr.sort();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    cout << "������: " << myArr.getIndex() << ", ��������� �� ������� �������: " << myArr.getElement(myArr.getIndex() - 1)
        << ", ������������ ������ �������: " << myArr.getArraySize();
    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    cout << "�������� '69' ����������� � �������� � �������� " << myArr.findElement(69) << std::endl;

    myArr.replace(675838, 0);
    cout << "\n������ �������� ��������\n" << myArr.toString() << std::endl;

    expectedArray = new int[myArr.getArraySize()]{ 675838, 3, 3, 5, 9, 12, 24, 45, 69, 83, 85, 453, 659, 780, 6549 };
    ptrExpectedArray = expectedArray;
    cout << "��������� ������ � �������� ��������: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

}

void Test::test2()
{
    cout << "\n==============================================\n\n";
    cout << "���� ����� 2: �������� ������� ������\n\n\n";

    Array myArr;

    cout << "������: " << myArr.getIndex() << ", �������: " << myArr.getElement(myArr.getIndex())
        << ", ������������ ������ �������: " << myArr.getArraySize();

    cout << "\n������� ����� 85 � ����� �������\n";
    myArr.add(85);
    cout << "������� ����� 7 � ����� �������\n";
    myArr.add(7);
    cout << "������� ����� 934 � ����� �������\n";
    myArr.add(934);
    cout << "������� ����� 2 � ������ �������\n";
    myArr.add(2, 0);
    cout << "������� ����� 34 � ����� �������\n";
    myArr.add(34);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 2, 85, 7, 934, 34 };
    int* ptrExpectedArray = expectedArray;
    cout << "��������� ������ � �������� ��������: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";

    cout << "������� ������������ ������ �������\n";
    myArr.setArraySize(10);
    cout << "������� ������ �������� ��������\n";
    myArr.setIndex(0);
    cout << "������� ��������� �� ������\n";
    int* arr = new int[myArr.getArraySize()];
    myArr.setPtrArray(arr);

    cout << "�������� ����� ������\n\n";
    myArr.add(62);
    myArr.add(5);
    myArr.add(485);
    myArr.add(313);
    myArr.add(899);
    myArr.add(236);
    myArr.add(200);

    cout << "������: " << myArr.getIndex() << ", ��������� �� ������� �������: " << myArr.getElement(myArr.getIndex() - 1)
        << ", ������������ ������ �������: " << myArr.getArraySize();

    expectedArray = new int[myArr.getArraySize()]{ 62, 5, 485, 313, 899, 236, 200 };
    ptrExpectedArray = expectedArray;
    cout << "\n��������� ������ � �������� ��������: " << equal(myArr, ptrExpectedArray) << "\n";
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
            if (i >= array.getArraySize()) {
                break;
            }
        }
        expectedArray++;
        realArray++;
        i++;
    }

    return false;
}
