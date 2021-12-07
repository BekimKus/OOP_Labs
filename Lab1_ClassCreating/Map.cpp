#include "Map.h"

Map::Map()
{
    setIndex(0);
    setArraySize(5);
    keysArray = new char* [getArraySize()];

    for (int i = 0; i < 5; i++) {
        keysArray[i] = new char[32];
        keysArray[i][0] = '\0';
    }
}

Map::Map(char** keysArray, int* values)
{
    this->keysArray = keysArray;
    setPtrArray(values);
}

void Map::add(const char* key, int value)
{
    if (key == 0 || strcmp(key, "") == 0) throw ArrayException(ArrayException::Error::MAP_KEY_EMPTY);
    if (value < 0) throw ArrayException(ArrayException::Error::NEGATIVE_VALUE);

    for (int i = 0; i < getIndex(); i++) {
        if (strcmp(key, keysArray[i]) == 0) throw "Exception: This key already is in map";
    }

    if (getIndex() == getArraySize() - 1) {
        setArraySize(getArraySize() * 2);
        char** temp = new char* [getArraySize() * 10];
        for (int i = 0; i < getIndex(); i++) {
            temp[i] = new char[32];
            strcpy_s(temp[i], 32 * sizeof(char), keysArray[i]);
            delete[] keysArray[i];
        }
        delete[] keysArray;

        keysArray = temp;
    }

    keysArray[getIndex()] = new char[32];

    strcpy_s(keysArray[getIndex()], 32 * sizeof(char), key);
    Array::add(value);
}

int Map::getValue(const char* key)
{
    if (key == 0 || strcmp(key, "") == 0) throw ArrayException(ArrayException::Error::MAP_KEY_EMPTY);

    for (int i = 0; i < getIndex(); i++) {
        if (!strcmp(key, keysArray[i])) return Array::getElement(i);
    }

    return -1;
}

char* Map::findKeyByValue(int value)
{
    if (value < 0) throw ArrayException(ArrayException::Error::NEGATIVE_VALUE);

    return keysArray[Array::findElement(value)];
}

void Map::replace(const char* key, int value)
{
    if (value < 0) throw ArrayException(ArrayException::Error::NEGATIVE_VALUE);
    if (key == 0 || strcmp(key, "") == 0) throw ArrayException(ArrayException::Error::MAP_KEY_EMPTY);

    int index;
    for (int i = 0; i < getIndex(); i++) {
        if (strcmp(key, keysArray[i]) == 0) {
            index = i;
            break;
        }
        if (strcmp(key, keysArray[i]) != 0 && i == getIndex() - 1)
            throw ArrayException(ArrayException::Error::MAP_KEY_NOT_FOUND);
        else index = i;
    }

    strcpy_s(keysArray[index], 32 * sizeof(char), key);
    Array::replace(value, index);
}

void Map::deleteElement(const char* key)
{
    if (key == 0 || strcmp(key, "") == 0) throw ArrayException(ArrayException::Error::MAP_KEY_EMPTY);

    int index;
    for (int i = 0; i < getIndex(); i++) {
        if (strcmp(key, keysArray[i]) == 0) {
            index = i;
            break;
        }

        if (strcmp(key, keysArray[i]) != 0 && i == getIndex() - 1)
            throw ArrayException(ArrayException::Error::MAP_KEY_NOT_FOUND);
    }
    
    for (int i = index; i < getIndex() - 1; i++) {
        memcpy(keysArray[i], keysArray[i + 1], 32 * sizeof(char));
    }
    Array::deleteElement(index);
}

void Map::setKeysArray(char** keysArray)
{
    if (this->keysArray[0][0] != '\0') {
        for (int i = 0; i < getIndex(); i++) {
            delete[] this->keysArray[i];
        }
    }

    this->keysArray = keysArray;
}

char** Map::getKeysArray()
{
    char** temp1 = new char* [getArraySize()];

    for (int i = 0; i < getIndex(); i++) {
        char* temp = new char [strlen(keysArray[i])];
        memcpy(temp, keysArray[i], strlen(keysArray[i]));
        temp[strlen(keysArray[i])] = '\0';
        temp1[i] = temp;
    }

    return temp1;
}

Map& Map::operator=(Map& map)
{
    setPtrArray(map.getPtrArray());
    setArraySize(map.getArraySize());
    setIndex(map.getIndex());
    keysArray = map.getKeysArray();
    return *this;
}

Map& Map::operator--(void)
{
    int* ptrArr = getPtrArray();

    for (int i = 0; i < getIndex(); i++) {
        if (ptrArr[i] - 1 > 1) {
            ptrArr[i]--;
        }
    }

    setPtrArray(ptrArr);

    return *this;
}

Map& Map::operator--(int d)
{
    int* ptrArr = getPtrArray();

    for (int i = 0; i < getIndex(); i++) {
        if (ptrArr[i] - 1 > 1) {
            ptrArr[i]--;
        }
    }

    setPtrArray(ptrArr);

    return *this;
}

int& Map::operator[](const char* key)
{
    int &element = this->Array::operator[](findElement(getValue(key)));
    return element;
}

Map& operator+(Map& map1, Map& map2)
{
    Map* map = new Map();

    map->setArraySize(map1.getArraySize() + map2.getArraySize());

    char** chPtr = new char* [map->getArraySize() + 1];
    char* temp = new char[1];
    temp[0] = '\0';

    for (int i = 0; i < map->getArraySize() + 1; i++) {
        chPtr[i] = new char[32];
        chPtr[i][0] = '\0';
    }
   
    int* ptrRes = new int[map->getArraySize()];
    memset(ptrRes, -1, map->getArraySize() * sizeof(int));
    int* ptrArr1 = map1.getPtrArray();
    int* ptrArr2 = map2.getPtrArray();
    char** keys1 = map1.getKeysArray();
    char** keys2 = map2.getKeysArray();

    int i;
    for (i = 0; i < map1.getIndex(); i++) {
        ptrRes[i] = ptrArr1[i];
        temp = keys1[i];
        strcpy_s(chPtr[i], strlen(temp) + 1, temp);
    }
    for (int j = 0; j < map2.getIndex(); j++, i++) {
        ptrRes[i] = ptrArr2[j];
        temp = keys2[j];
        strcpy_s(chPtr[i], strlen(temp) + 1, temp);
    }

    delete[] ptrArr1;
    delete[] ptrArr2;

    map->setPtrArray(ptrRes);
    map->setKeysArray(chPtr);
    map->setIndex(map1.getIndex() + map2.getIndex());

    return *map;
}

Map& operator-(Map& map1, Map& map2)
{
    Map* map = new Map();
    map->setArraySize(map1.getArraySize() + map2.getArraySize());

    char** chPtr = new char* [map->getArraySize() + 1];
    char* temp = new char[1];
    temp[0] = '\0';

    for (int i = 0; i < map->getArraySize() + 1; i++) {
        chPtr[i] = new char[32];
        chPtr[i][0] = '\0';
    }

    int* ptrRes = new int[map1.getArraySize() + map2.getArraySize()];
    memset(ptrRes, -1, map->getArraySize() * sizeof(int));
    int* ptrArr1 = map1.getPtrArray();
    int* ptrArr2 = map2.getPtrArray();
    char** keys1 = map1.getKeysArray();
    char** keys2 = map2.getKeysArray();

    int i = 0;
    for (int j = 0; j < map1.getIndex(); j++) {
        bool equal = false;
        for (int k = 0; k < map2.getIndex(); k++) {
            if (ptrArr1[j] == ptrArr2[k] || strcmp(keys1[j], keys2[k]) == 0) {
                equal = true;
                break;
            }
        }

        if (!equal) {
            ptrRes[i] = ptrArr1[j];
            chPtr[i] = keys1[j];
            i++;
        }
    }

    delete[] ptrArr1;
    delete[] ptrArr2;

    map->setPtrArray(ptrRes);
    map->setKeysArray(chPtr);
    map->setIndex(i);

    return *map;
}

Map& operator-(Map& map, const char* key)
{
    map.deleteElement(key);
    return map;
}

std::ostream& operator<<(std::ostream& out, Map& map)
{
    out << map.toString();

    return out;
}

std::istream& operator>>(std::istream& in, Map& map)
{
    int arraySize;
    cout << "Array size: ";
    in >> arraySize;
    map.setArraySize(arraySize);

    int index;
    cout << "Index: ";
    in >> index;
    cout << "Key and value: ";
    map.setIndex(index);

    char** ch = new char* [map.getArraySize()];
    int* ptr = new int[map.getArraySize()];

    for (int i = 0; i < map.getIndex(); i++) {
        ch[i] = new char[32];
        ch[i][0] = '\0';
        in >> ch[i];

        in >> ptr[i];
    }
    map.setPtrArray(ptr);
    map.setKeysArray(ch);

    return in;
}
std::ifstream& operator>>(std::ifstream& in, Map& map)
{
    int arraySize;
    in >> arraySize;
    map.setArraySize(arraySize);

    int index;
    in >> index;
    map.setIndex(index);

    int* ptr = new int[map.getArraySize()];
    char** keys = new char* [arraySize];
    memset(ptr, -1, map.getArraySize() * sizeof(int));

    for (int i = 0; i < map.getIndex(); i++) {
        keys[i] = new char[32];
        keys[i][0] = '\0';
        in >> keys[i];

        in >> ptr[i];
    }
    map.setPtrArray(ptr);

    return in;
}
std::ofstream& operator<<(std::ofstream& out, Map& map)
{
    // Clean for txt file
    char** keys = map.getKeysArray();
    int sizeCh = 1024;
    char ch[1024] = "";
    int i;
    for (i = 0; i < map.getIndex(); i++) {
        char val[10] = "";
        char* temp = *(keys++);
        _itoa_s(map.Array::getElement(i), val, 10);
        strcat_s(ch, sizeof(ch), temp);
        strcat_s(ch, sizeof(ch), ": ");
        strcat_s(ch, sizeof(ch), val);
        strcat_s(ch, sizeof(ch), " \0");
    }
    keys -= i;
    char* ptr = new char[sizeof(ch)];
    strcpy_s(ptr, sizeof(ch), ch);

    // string for txt file
    char val[10] = "";
    _itoa_s(map.getArraySize(), val, 10);
    strcat_s(ch, sizeCh, val);
    strcat_s(ch, sizeCh, " ");
    _itoa_s(map.getIndex(), val, 10);
    strcat_s(ch, sizeCh, val);
    strcat_s(ch, sizeCh, "\t");
    strcat_s(ch, sizeCh, ptr);
    strcat_s(ch, sizeCh, "\n\0");

    out << ch;

    return out;
}

char* Map::toString()
{
    char ch[1024] = "";
    int i;
    for (i = 0; i < getIndex(); i++) {
        char val[10] = "";
        char* temp = *(keysArray++);
        _itoa_s(Array::getElement(i), val, 10);
        strcat_s(ch, sizeof(ch), temp);
        strcat_s(ch, sizeof(ch), ": ");
        strcat_s(ch, sizeof(ch), val);
        strcat_s(ch, sizeof(ch), "\n\0");
    }
    keysArray -= i;
    char* ptr = new char[sizeof(ch)];
    strcpy_s(ptr, sizeof(ch), ch);

    return ptr;
}

Map::~Map()
{
    for (int i = 0; i < getIndex() - 1; i++) {
        //delete[] keysArray[i];
    }
}

