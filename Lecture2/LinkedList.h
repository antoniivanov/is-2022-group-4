#include <stdexcept>

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}

    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

class LinkedList {
    Node* head; 
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        // TODO
    }

    void insertFirst(int value) {
        
        Node* node = new Node(value, this->head);
        this->head = node;
        if (this->tail == nullptr) {
            this->tail = node;
        }
    }

    void insertLast(int value) {
        Node* node = new Node(value, nullptr);
        if (this->tail == nullptr) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail->next = node;
            this->tail = node;
        }
    }

    void insertAfter(int value, Node* iterator) {
        // insert after
        if (iterator == nullptr) {
            // do nothing
            return;
        }
        
        Node* node = new Node(value);
        node->next = iterator->next;
        iterator->next = node;


        if (iterator->next == nullptr) {
            this->tail = node;
        }
    }

    int removeFirst() {
        if (this->head == nullptr) {
            throw std::invalid_argument( "Removing element from an empty list." );
        }

        Node* tmp = this->head;
        this->head = this->head->next;
        int value = tmp->val;
        delete tmp;
        return value;
    }

    int removeLast() {
        // TODO
    }
    
    int removeAfter(Node* iterator) {
        // TODO
    }
};