#include "cons_list.h"
#include <iostream>
#include <functional>
/*
implementation (5)
isn't always functional, (7)
the api is (5)
*/

#define NULL_LIST NULL
template <typename T>
void List<T>::add(T x) {
    if (this->tailList == NULL_LIST) {
        this->tailList = new List<T>(x);
    } else {
        this->tailList->add(x);
    }
}

template <typename T>
List<T>::List() {
    this->isEmptyList = true;
    this->tailList = NULL_LIST;
}

template <typename T>
List<T>::List(T head, List<T> *tail) {
    this->isEmptyList = false;
    this->headElement = head;
    this->tailList = tail;
}

template <typename T>
List<T>::List(std::initializer_list<T> array) {
    if (array.size() == 0) {
        this->isEmptyList = true;
        this->tailList = NULL_LIST;
    } else if (array.size() == 1) {
        this->headElement = *(array.begin());
        this->isEmptyList = false;
        this->tailList = NULL_LIST;
    } else {
        this->headElement = *(array.begin());
        this->isEmptyList = false;
        List<T> *it = this;
        for (
            auto x = array.begin() + 1;
            x != array.end();
            x++
        ) {
            it->tailList = new List<T>(*x);
            it = it->tailList;
        }
    }
}

template <typename T>
T List<T>::head() {
    if (this->isEmptyList)
        throw "error: no head exists on empty list";
    else
        return this->headElement;
}

template <typename T>
List<T> List<T>::tail() {
    return &this->tailList;
}

template <typename T>
bool List<T>::isEmpty() {
    return this->isEmptyList;
}

template <typename T>
template <typename U>
List<U>* List<T>::mapInternal(std::function<U(T)> func) {
    if (this->tailList == NULL_LIST) {
        return new List<U>(func(this->headElement));
    } else {
        return new List<U>(
            func(this->headElement),
            this->tailList->mapInternal(func)
        );
    }
}

template <typename T>
template <typename U>
List<U> List<T>::map(std::function<U(T)> func) {
    return *this->mapInternal(func);
}

template <typename T>
template <typename U>
List<U> * List<T>::mapInternal(
    std::function<U(T, int)> func, int i
) {
    if (this->tailList == NULL_LIST) {
        return new List<U>(func(this->headElement, i));
    } else {
        return new List<U>(
            func(this->headElement, i),
            this->tailList->mapInternal(func, i+1)
        );
    }
}

template <typename T>
template <typename U>
List<U> List<T>::map(std::function<U(T, int)> func) {
    return *this->mapInternal(func, 0);
}

template <typename T>
void List<T>::forEach(std::function<void(T)> func) {
    if (this->tailList == NULL_LIST) {
        func(this->headElement);
    } else if (this->tailList->tailList == NULL_LIST) {
        func(this->headElement);
        func(this->tailList->headElement);
    } else {
        List<T> *it = this;
        while (it->tailList != NULL_LIST) {
            func(it->headElement);
            it = it->tailList;
        }
        func(it->headElement);
    }
}

template <typename T>
void List<T>::forEach(std::function<void(T, int)> func) {
    if (this->isEmptyList)
        return;
    if (this->tailList == NULL_LIST) {
        func(this->headElement, 0);
    } else if (this->tailList->tailList == NULL_LIST) {
        func(this->headElement, 0);
        func(this->tailList->headElement, 1);
    } else {
        List<T> *it = this;
        int i = 0;
        func(it->headElement, i);
        while (it->tailList->tailList != NULL_LIST) {
            it = it->tailList;
            i++;
            func(it->headElement, i);
        }
        i++;
        it = it->tailList;
        func(it->headElement, i);
    }
}

template <typename T>
void List<T>::forEach(
    std::function<void(T, int, bool, bool)> func
) {
    if (this->isEmptyList)
        return;
    if (this->tailList == NULL_LIST) {
        func(this->headElement, 0, true, true);
    } else if (this->tailList->tailList == NULL_LIST) {
        func(this->headElement, 0, true, false);
        func(this->tailList->headElement, 1, false, true);
    } else {
        List<T> *it = this;
        int i = 0;
        func(it->headElement, i, true, false);
        while (it->tailList->tailList != NULL_LIST) {
            it = it->tailList;
            i++;
            func(it->headElement, i, false, false);
        }
        i++;
        it = it->tailList;
        func(it->headElement, i, false, true);
    }
}

template <typename T>
void List<T>::print() {
    this->forEach([](
        T t,
        int index,
        bool isFirst,
        bool isLast
    ) {
        std::cout
            << (isFirst ? "[ " : "")
            << t //<< "(" << index << ")"
            << (isLast ? " ]\n" : " | ")
        ;
    });
}

template <typename T>
List<T> List<T>::join(List<T> that) {
    if (this->isEmptyList) {
        return that;
    } else if (that.isEmptyList) {
        return *this;
    } else {
        List<T> * x = new List<T>(this->headElement);
        this->forEach([x](T head, int index) {
            if (index != 0) x->add(head);
        });
        that.forEach([x](T head) {
            x->add(head);
        });
        return *x;
    }
}

int main() {
    List<int> a = {1, 2, 3, 4};
    a.print();

    List<int> b = {5, 6, 7};
    b.print();
    b.print();

    List<int> c = a.join(b);
    c.print();

    // List<bool> d = c.map<bool>([](int i) -> bool {
    //     return i % 2 == 0;
    // });
    // d.print();

    // a.map<int>([](int i, int index) -> int {
    //     return i;
    // }).print();
    // b.print();

    return 0;
}