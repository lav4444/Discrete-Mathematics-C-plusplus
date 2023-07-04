#include <iostream>
#include "ListElement.h"

using namespace std;

template <class T> class List {
    public:
        ListElement<T>* head;
        List() {
            this -> head = nullptr;
        }
        void add(T val2) {
            if (head == nullptr) {
                ListElement<T>* newElem = new ListElement<T>;
                head = newElem;
                newElem -> val = val2;
                newElem -> next = nullptr;

            } else {      //nije prvi element liste
                ListElement<T>* newElem = new ListElement<T>;
                newElem -> next = head;
                newElem -> val = val2;
                head = newElem;

            }
        }
        void addSorted(T val2) {
            ListElement<T>* newElem = new ListElement<T>;
            ListElement<T>* trenutni = head;
            while (true) {
                //cout << "da";
                if (head == nullptr) {
                    newElem -> next = nullptr;
                    newElem -> val = val2;
                    head = newElem;
                    break;
                }
                if (head -> val >= val2) { //dodaj ga na mjesto prvog elem
                    newElem -> val = val2;
                    newElem -> next = trenutni;
                    head = newElem;
                    break;
                }
                if ((trenutni -> next == nullptr) && (trenutni -> val <= val2)) { //dodaj na mjesto zadnjeg
                    newElem -> val = val2;
                    newElem -> next = nullptr;
                    trenutni -> next = newElem;
                    break;
                }
                if ((trenutni -> val <= val2)&&( (trenutni -> next) -> val >= val2 )) {
                    newElem -> val = val2;
                    newElem -> next = trenutni -> next;
                    trenutni -> next = newElem;
                    break;
                }
                else {
                    trenutni = trenutni -> next;
                }
            }

        }

        void remove(T data) {
            ListElement<T>* trenutni = head;
            while (true) {
                if (head -> val == data) {
                    head = head -> next;
                    break;
                }
                if (trenutni == nullptr) {
                    break;
                }
                if ((trenutni -> next) -> val == data){
                    trenutni -> next = trenutni ->next ->next;
                    break;
                }
                else {
                    trenutni = trenutni -> next;
                }

            }
            
        }

        bool check(T data) {
            ListElement<T>* trenutni = head;
            bool vrati = false;
            while (true) {
                if (head == nullptr) {
                    break;
                }
                if (trenutni -> val == data) {
                    vrati = true;
                    break;
                }
                if ( (trenutni -> next) == nullptr) {
                    break;
                }
                trenutni = trenutni -> next;
            
            }
            return vrati;
            
        }
        int count() {
            ListElement<T>* trenutni = head;
            int suma = 0;
            while (true) {
                if (head == nullptr) {
                    break;
                }
                suma++;
                if ( (trenutni -> next) == nullptr) {
                    break;
                }
                trenutni = trenutni -> next;
            
            }
            return suma;
            
        }

        void PrintList() {
            ListElement<T>* trenutni = head;
            cout << "Lista: ";
            while (true) {
                if (trenutni == nullptr) {
                    cout << endl;
                    break;
                }
                cout << trenutni -> val << " ";

                trenutni = trenutni -> next;
            }
        }
};