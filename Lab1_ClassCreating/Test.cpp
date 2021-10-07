#include "Test.h"

void Test::test1()
{
    cout << "\n==============================================\n\n";
    cout << "Тест номер 1: Проверка методов класса\n\n\n";

    int array[15] = { 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69 };
    int* ptrArray = array;
    Array myArr(15, 11, ptrArray);

    cout << "Изначальный массив: " << myArr.toString() << "\n\n";

    cout << "Добавим число 76 в начало массива\n";
    myArr.add(76, 0);
    cout << "Добавим число 77 в начало массива\n";
    myArr.add(77, 0);
    cout << "Добавим число 24 в конец массива\n";
    myArr.add(24);
    cout << "Добавим число 45 в конец массива\n";
    myArr.add(45);
    cout << "Добавим число 9 в конец массива\n";
    myArr.add(9);
    cout << "Добавим число 780 в конец массива\n";
    myArr.add(780);
    cout << std::endl << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 77, 76, 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69, 24, 45, 9, 780 };
    int* ptrExpectedArray = expectedArray;
    cout << "Ожидаемый массив и реальный сходятся: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "Два раза удалим элемент с индексом 0\n";
    myArr.deleteElement(0);
    myArr.deleteElement(0);

    cout << "Сожмем массив до последнего ненулевого элемента\n";
    myArr.collapse();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;

    expectedArray = new int[myArr.getArraySize()]{ 3, 453, 6549, 83, 85, 3, 1, 12, 5, 659, 69, 24, 45, 9, 780 };
    ptrExpectedArray = expectedArray;
    cout << "Ожидаемый массив и реальный сходятся: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "Отсортируем массив\n";
    myArr.sort();
    cout << "---------------------------------\n";
    cout << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    cout << "Индекс: " << myArr.getIndex() << ", Последний не нулевой элемент: " << myArr.getElement(myArr.getIndex() - 1)
        << ", Максимальный размер массива: " << myArr.getArraySize();
    cout << "\n" << myArr.toString() << std::endl;
    cout << "---------------------------------\n";

    cout << "Значение '69' встречается в элементе с индексом " << myArr.findElement(69) << std::endl;

    myArr.replace(675838, 0);
    cout << "\nЗамена нулевого элемента\n" << myArr.toString() << std::endl;

    expectedArray = new int[myArr.getArraySize()]{ 675838, 3, 3, 5, 9, 12, 24, 45, 69, 83, 85, 453, 659, 780, 6549 };
    ptrExpectedArray = expectedArray;
    cout << "Ожидаемый массив и реальный сходятся: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

}

void Test::test2()
{
    cout << "\n==============================================\n\n";
    cout << "Тест номер 2: Проверка методов класса\n\n\n";

    Array myArr;

    cout << "Индекс: " << myArr.getIndex() << ", Элемент: " << myArr.getElement(myArr.getIndex())
        << ", Максимальный размер массива: " << myArr.getArraySize();

    cout << "\nДобавим число 85 в конец массива\n";
    myArr.add(85);
    cout << "Добавим число 7 в конец массива\n";
    myArr.add(7);
    cout << "Добавим число 934 в конец массива\n";
    myArr.add(934);
    cout << "Добавим число 2 в начало массива\n";
    myArr.add(2, 0);
    cout << "Добавим число 34 в конец массива\n";
    myArr.add(34);

    cout << "\n" << myArr.toString() << std::endl;

    int* expectedArray = new int[myArr.getArraySize()]{ 2, 85, 7, 934, 34 };
    int* ptrExpectedArray = expectedArray;
    cout << "Ожидаемый массив и реальный сходятся: " << equal(myArr, ptrExpectedArray) << "\n";
    delete[] expectedArray;

    cout << "---------------------------------\n";

    cout << "Изменим максимальный размер массива\n";
    myArr.setArraySize(10);
    cout << "Изменим индекс текущего элемента\n";
    myArr.setIndex(0);
    cout << "Изменим указатель на массив\n";
    int* arr = new int[myArr.getArraySize()];
    myArr.setPtrArray(arr);

    cout << "Заполним новый массив\n\n";
    myArr.add(62);
    myArr.add(5);
    myArr.add(485);
    myArr.add(313);
    myArr.add(899);
    myArr.add(236);
    myArr.add(200);

    cout << "Индекс: " << myArr.getIndex() << ", Последний не нулевой элемент: " << myArr.getElement(myArr.getIndex() - 1)
        << ", Максимальный размер массива: " << myArr.getArraySize();

    expectedArray = new int[myArr.getArraySize()]{ 62, 5, 485, 313, 899, 236, 200 };
    ptrExpectedArray = expectedArray;
    cout << "\nОжидаемый массив и реальный сходятся: " << equal(myArr, ptrExpectedArray) << "\n";
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
