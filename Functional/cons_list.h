#ifndef CONS_LIST_H
#define CONS_LIST_H

#include <functional>

/*
implementation (5)
isn't always functional, (7)
the api is (5)
*/

#define NULL_LIST NULL
template <typename T>
class List {
private:
    bool isEmptyList;
    T headElement;
    List<T> *tailList;
    void add(T x);

    template <typename U>
    List<U> *mapInternal(std::function<U(T)> func);
    template <typename U>
    List<U> *mapInternal(std::function<U(T, int)> func, int i);

public:
    List();
    List(T head, List<T> *tail=NULL_LIST);
    List(std::initializer_list<T> array);
    ~List();

    T head();
    List<T> tail();
    bool isEmpty();

    template <typename U>
    List<U> map(std::function<U(T)> func);
    template <typename U>
    List<U> map(std::function<U(T, int)> func);

    void forEach(std::function<void(T)> func);
    void forEach(std::function<void(T, int)> func);
    void forEach(std::function<void(T, int, bool, bool)> func);

    void print();

    List<T> join(List<T> that);
};

#endif