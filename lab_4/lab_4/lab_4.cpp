#include <iostream>
#include <cstdlib>

template<class T>
class Node {
public:
    Node* next;
    T data;
    Node* previous;
};

using namespace std;

template<class T>
class Deque {
public:
    int length;
    Node<T>* head;
    Node<T>* end;
    Deque();
    ~Deque();
    void pushFront(T data);
    void pushBack(T date);
    void print();
    
    class myiterator;
    friend class myiterator;
    
    myiterator begin() {
        myiterator tmp = head;
        return tmp;
    }
    /*myiterator end() {
        return *end;
    }*/


};

//ITERATOR REALISATION
template<class T>
class myiterator {
public:
    Node<T>* p;
    myiterator();
    myiterator(const Deque<T>& deq);
    //myiterator operator++(int);
    T& operator*();
    myiterator operator=(myiterator it) {
        p = it->p;
        return *this;
    }
    myiterator operator++(int) {
        myiterator tmp = *this;
        if (p->next != NULL)
            p = p->next;
        else p = NULL;
        return tmp;
    }
    int operator!=(myiterator it) {
        return p != it->p;
    }
};

template<class T>
myiterator<T>::myiterator() {
    p = NULL;
}

template<class T>
myiterator<T>::myiterator(const Deque<T>& deq) {
    p = deq->head;
}


template<class T>
T& myiterator<T>::operator*() {
    return fact(p->data);
}

//DEQUE REALISATION
template<class T>
Deque<T>::Deque() {
    this->length = 0;
    this->head = NULL;
    this->end = head;
    for (int i = 0; i < 10; ++i)
        pushBack(i + 1);
}


template<class T>
Deque<T>::~Deque() {
    Node<T>* current, * next;
    if (head) {
        current = head;
        while (current) {
            next = current->next;
            delete(current);
            current = next;
        }
    }
    std::cout << "LIST DELETED";
}

template<class T>
void Deque<T>::pushFront(T data) {
    Node<T>* node = new Node<T>();
    node->data = data;
    if (head == NULL) {
        head = node;
        end = node;
        length++;
    } else {
        node->next = this->head;
        this->head = node;
        this->length++;
    }
}

template<class T>
void Deque<T>::pushBack(T data) {
    Node<T>* node = new Node<T>();
    node->data = data;
    if (this->head == NULL) {
        head = node;
        end = node;
        length++;
    } else {
        node->previous = end;
        end->next = node;
        end = node;
        length++;
    }
}

template<class T>
void Deque<T>::print() {
    Node<T>* head = this->head;
    int i = 1;
    while (head) {
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

int main(int argc, char const* argv[]) {
    Deque<int>* list = new Deque<int>();
    string str = "qwe";
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    myiterator<int> it = list->begin();
    cout << *it;
   /* for (myiterator<int> it = list->begin(); it != list->end(); it++) {

    }*/
    delete list;
    return 0;
}