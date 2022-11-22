
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
    Node<T>* prev; // TODO: implement double linked list
    Node() : val(T()), next(nullptr) {}

    Node(T x) : val(T()), next(nullptr) {}
    Node(T x, Node<T>* next) : val(x), next(next) {}
};

template <typename T>
class LinkedList {
    Node<T>* head; 
    Node<T>* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        while (this->head != nullptr) {
            Node<T>* toDelete = this->head; 
            this->head = this->head->next; 
            delete toDelete;
        }
    }

    void insertFirst(T value) {
        
        Node<T>* node = new Node<T>(value, this->head);
        this->head = node;
        if (this->tail == nullptr) {
            this->tail = node;
        }
    }

    void insertLast(T value) {
        Node<T>* node = new Node<T>(value, nullptr);
        if (this->tail == nullptr) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail; 
            this->tail = node;
        }
    }

    void insertAfter(T value, Node<T>* iterator) {
        // insert after
        if (iterator == nullptr) {
            // do nothing
            return;
        }
        
        Node<T>* node = new Node<T>(value);
        node->next = iterator->next;
        iterator->next = node;


        if (iterator->next == nullptr) {
            this->tail = node;
        }
    }

    T removeFirst() {
        if (this->head == nullptr) {
            throw std::invalid_argument( "Removing element from an empty list." );
        }

        Node<T>* tmp = this->head;
        this->head = this->head->next;
        T value = tmp->val;
        delete tmp;
        return value;
    }


    T removeLast() {
        if (this->head == nullptr) {
            throw std::runtime_error("deleting from Empty list");
        }
        T value;
        if (this->head != this->tail) {
            Node<T>* prev = this->tail->prev;
            prev->next = nullptr;
             value = this->tail->val;
            delete this->tail;
            this->tail = prev ;
        } else {
            value = this->head->val;
            delete this->head ;
            this->head = nullptr;
            this->tail = nullptr;
        }
        return value;
    }
    

    T removeAfter(Node<T>* iterator) {
        // we assume iterator is part of the list
        if (this->head == nullptr) {
            throw std::runtime_error("deleting from Empty list ");
        }
        if (iterator == nullptr or iterator->next == nullptr) {
            throw std::runtime_error("No element found to remove ");
        }
        Node<T>* toDelete = iterator->next ;
        iterator->next = toDelete->next ;
        if (this->tail == toDelete) {
            this->tail = iterator;
        }
        T value = toDelete->val;
        delete toDelete;
        return value;
    }
    
    std::vector<T> to_vector() {
        Node<T>* current = this->head;
        std::vector<T> v;
        while (current != nullptr) {
            v.push_back(current->val);
            current = current->next ;
        }
        return v;
    }
    
    Node<T>* get_node_at_index(T index) {
        Node<T>* current = this->head; 
        while (current != nullptr && index > 0) {
            index--;
            current = current->next;
        }
        return current;
    }


    class Iterator;
  
    Iterator begin() {
        return Iterator(this->head);
    }
  
    Iterator end() {
        return Iterator(nullptr);
    }

    class Iterator
    {
    public:
        Iterator() noexcept :
            current_node (nullptr) { }
    
        Iterator(const Node<T>* node) noexcept :
            current_node (node) { }
    
        Iterator& operator=(Node<T>* node) {
            this->current_node = node;
            return *this;
        }

        // Prefix ++ overload
        Iterator& operator++() {
            if (current_node)
                current_node = current_node->next;
            return *this;
        }

        // Postfix ++ overload
        Iterator operator++(int) {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator) {
            return current_node != iterator.current_node;
        }

        T operator*() {
            return current_node->val;
        }
    
    private:
            const Node<T>* current_node;
    };



};



LinkedList create_test_list( std::initializer_list<int> list )
{
    LinkedList<int> test_list;
    for( auto elem : list )
    {
        test_list.insertFirst(elem);
    }
    return test_list;
}

void test_insertFirst_toEmptyList () {
    std::cout << "test_insertFirst\n";
    LinkedList<int> test;
    
    test.insertFirst(12);
    
    assert (std::vector<int>({12}) == test.to_vector());
}




void test_insertFirst_toListWithOneElement () {
    std::cout << "test_insertFirst\n";
    LinkedList<int> test;
    test.insertFirst(12);
    
    test.insertFirst(14);
    
    assert (std::vector<int>({14, 12}) == test.to_vector());
}



void test_insertLast_toEmptyList () {
    std::cout << "test_insertLast\n";
    LinkedList<int> test;
    
    test.insertLast(12);
    
    assert (std::vector<int>({12}) == test.to_vector()); 
}

void test_insertLast_toListWithOneElement () {
    std::cout << "test_insertLast\n";
    LinkedList test;
    test.insertLast(12); 
    
    test.insertLast(14);
    
    assert (std::vector<int>({12, 14}) == test.to_vector());
}

void test_insertAfter_toEmptyList () {
    std::cout << "test_insertAfter\n";
    LinkedList test;
    
    test.insertAfter(10, nullptr);
    
    assert (std::vector<int>({}) == test.to_vector());
}


void test_insertAfter_toListWithOneElement  () {
    std::cout << "test_insertAfter\n";
    LinkedList test;
    test.insertLast(12);
    
    test.insertAfter(10, test.get_node_at_index(0));
    
    assert (std::vector<int>({12, 10}) == test.to_vector());
}


void test_insertAfter_firstElement  () {
    std::cout << "test_insertAfter\n";
    LinkedList<int> test;
    
    test.insertLast(12); 
    test.insertLast(10); 
    
    test.insertAfter(14, test.get_node_at_index(0));
    
    assert (std::vector<int>({12, 14, 10}) == test.to_vector());
}

void test_insertAfter () {
    std::cout << "test_insertAfter\n";
    LinkedList<int> test;
    test.insertAfter(10, nullptr);
    assert (std::vector<int>({}) == test.to_vector());

    
    test.insertLast(12);
    test.insertAfter(10, test.get_node_at_index(0));
    assert (std::vector<int>({12, 10}) == test.to_vector());
    
    test.insertAfter(14, test.get_node_at_index(0));
    assert (std::vector<int>({12, 14, 10}) == test.to_vector());
}

void test_iterator() {
    LinkedList<int> l;
    l.insertFirst(12);
    l.insertFirst(122); 
    int expected[2] = { 12, 122 } ;
    
    // if iterator is implemented properly the for loop would work: 
    int i = 0;
    for (auto x: l) {
        assert (x == expected[i]);
        ++i;
    }

}

void test_removeFirst() {
    // TODO
}


void test_removeLast() {
    // TODO
}

int main()
{
    test_insertFirst_toEmptyList()
    test_insertFirst_toListWithOneElement ()  
        
    test_insertLast_toEmptyList () 
    test_insertLast_toListWithOneElement ()  
        
    test_insertAfter_toEmptyList ()  
    test_insertAfter_toListWithOneElement()
    test_insertAfter_firstElement()
    test_insertAfter()

    return 0;
}
