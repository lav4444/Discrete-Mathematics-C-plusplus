#include <iostream>

using namespace std;

template <class T> class ListElement {
    public:
        T val;
        ListElement<T>* next;
};
