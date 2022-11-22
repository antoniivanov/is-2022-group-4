
#include <iostream>
#include <exception>
#include <initializer_list>
#include <vector>
#include <cassert>

using namespace std;

#include <stdexcept>



template <typename T>
struct Node {
    T val;
    Node<T>* next;
    Node() : val(T()), next(nullptr) {}

    Node(T x) : val(T()), next(nullptr) {}
    Node(T x, Node<T>* next) : val(x), next(next) {}
};

template <typename T>
class LinkedList {
    Node<T>* head; 
    Node<T>* tail;

public:
    LinkedList();

    ~LinkedList();

    class Iterator;

    void insertFirst(T value);

    void insertLast(T value);

    void insertAfter(T value, Iterator iterator);

    T removeFirst();
    T removeLast();
    

    T removeAfter(Iterator iterator);
    
    std::vector<T> to_string();
    
    Iterator get_iterator_starting_at_index(T index);

  
    Iterator begin() {
        return Iterator(this->head);
    }
  
    Iterator end() {
        return Iterator(nullptr);
    }

    class Iterator
    {
    public:
        Iterator() noexcept ;
    
        Iterator(const Node<T>* node) ;

        // Prefix ++ overload
        Iterator& operator++() ;

        // Postfix ++ overload
        Iterator operator++(int);

        bool operator!=(const Iterator& iterator);

        T operator*();
    
    private:
            const Node<T>* current_node;
    };

};

 