#include "cons_list.h"
#include <iostream>
#include <list>
int main() {
    List<int> a = {1, 2, 3, 4};
    a.print();
    std::list<int> a;
    List<int> b = {5, 6, 7};
    b.print();

    List<int> c = a.join(b);
    c.print();

    List<bool> d = c.map<bool>([](int i) -> bool {
        return i % 2 == 0;
    });
    d.print();

    a.map<int>([](int i, int index) -> int {
        return i;
    }).print();

    return 0;
}