#include <iostream>
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
    void add(T x) {
        if (this->tailList == NULL_LIST) {
            this->tailList = new List<T>(x);
        } else {
            this->tailList->add(x);
        }
    }
public:
    List() {
        this->isEmptyList = true;
        this->tailList = NULL_LIST;
    }
    List(T head, List<T> *tail=NULL_LIST) {
        this->isEmptyList = false;
        this->headElement = head;
        this->tailList = tail;
    }
    List (T *array, size_t array_size) {
        this->headElement = array[0];
        if (array_size > 1)
            this->tailList = new List<T>(++array, --array_size);
    }
    T head() {
        if (this->isEmptyList)
            throw "error: no head exists on empty list";
        else
            return this->headElement;
    }
    List<T> * tail() {
        return this->tailList;
    }
    ~List<T>() {
        if (this->tailList != NULL_LIST)
            delete this->tailList;
    }
    bool isEmpty() {
        return this->isEmptyList;
    }

    template <typename U>
    List<U> *map(std::function<U(T)> func) {
        List<U> *tail;
        if (this->tailList != NULL_LIST) {
            tail = this->tailList->map<U>(func);
        } else {
            tail = NULL_LIST;
        }
        List<U> *ans = new List<U>(func(this->headElement), tail);
        return ans;
    }

    void forEach(std::function<void(T)> func) {
        List<T> *it = this;
        while (it->tailList != NULL_LIST) {
            func(it->headElement);
            it = it->tailList;
        }
        func(it->headElement);
    }
    void forEach(std::function<void(T, int, bool, bool)> func) {
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
    void print() {
        this->forEach([](T t, int index, bool isFirst, bool isLast) {
            std::cout
                << (isFirst ? "[" : "")
                << t << "(" << index << ")"
                << (isLast ? " ]\n" : " | ")
            ;
        });
    }
    List<T> * join(List<T> *that) {
        if (this->isEmptyList) {
            return that;
        } else if (that->isEmptyList) {
            return this;
        } else {
            List<T> * x = new List<T>();
            that->forEach([x](T head) {
                x->add(head);
            });
            this->forEach([x](T head) {
                x->add(head);
            });
            return x;
        }
    }
};

int main() {
    List<int> *a = new List<int>(
        1, new List<int>(
            2, new List<int>(
                3, new List<int>(
                    4
                )
            )
        )
    );
    a->print();

    List<int> *b = new List<int>(
        5, new List<int>(
            6, new List<int>(
                7
            )
        )
    );
    b->print();

    List<int> *c = a->join(b);
    c->print();

    int arr[5] = {5, 4, 3, 2, 1};
    List<int> *d = new List<int>(arr, 5);
    d->print();

    List<bool> *e = a->map<bool>([](int n) -> bool {
        return n % 2 == 0;
    });
    e->print();

    std::string strs[] = {"hello", "my", "name", "is", "samridh"};
    List<std::string> *f = new List<std::string>(strs, 5);
    f->print();

    // cleanup
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;

    return 0;
}