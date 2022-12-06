
#include <iostream>
#include <cassert>

using namespace std;



template<typename T>
struct Node {
    T data;   
    Node<T> *left; 
    Node<T> *right;

    Node(T data, Node<T>* left, Node<T>* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


template <typename K, typename V>
class Dictionary {
private: 

    Node< std::pair<K, V> > *root;

    

    Node< std::pair<K,V> >* get_node_and_parent_iterative(
                    Node< std::pair<K,V> >* root, 
                    K key, 
                    Node< std::pair<K,V> > **parent_node)
    {
        Node< std::pair<K,V> >* parent = NULL;
        Node< std::pair<K,V> >* current = root;

        while (current != nullptr) {
            if (current->data.first > key) {
                parent = current;
                current = current->left;
            }
            else if (current->data.first < key) {
                parent = current;
                current = current->right;
            } if (current->data.first == key) {
                if (parent_node != nullptr) {
                    *parent_node = parent;
                }
                return current;
            }
        }
        return nullptr;
    }
 


    Node< std::pair<K,V> >* add_helper (Node< std::pair<K,V> >* root, std::pair<K,V> data) {
        if (root == nullptr) {
            return new Node< std::pair<K,V> >(data, nullptr, nullptr);
        } 
        auto value = root.data;
        if (data.first > root.data.first) {
            root->right = add_helper(root->right, value);
        } else if (data.first < root.data.first) {
            root->left = add_helper(root->left, value);
        } else {
            root->data = data;
        }
     
        return root;
    }

public:

    void add(K key, V value) {
        std::pair<K,V> data (key, value);
        
        //this->root = add_helper(root, data);
        
        if (this->root == nullptr) {
            this->root = new Node< std::pair<K,V> >(data, nullptr, nullptr);
        } else {
            Node<std::pair<K,V> >* parent;
            auto found = this->get_node_and_parent_iterative(this->root, key, &parent);
            if (found == nullptr) {
                if(parent->data.first > key) {
                    parent->left = new Node< std::pair<K,V> >(data, nullptr, nullptr);
                } else {
                    parent->right = new Node< std::pair<K,V> >(data, nullptr, nullptr);
                }
            } else {
                found->data = data;
            }
        }
    }

    V get_value(K key) {

        auto found = this->get_node_and_parent_iterative(this->root, key, nullptr);
        if (found != nullptr) {
            return found->data.second;
        } else {
            throw std::runtime_error("not found");
        }
    }

    bool contains (K key) {
        auto found = this->get_node_and_parent_iterative(this->root, key, nullptr);
        return found != nullptr;
    }

    void remove(K key) {
        Node<std::pair<K,V> >* parentOfToDelete;
        Node<std::pair<K,V> >* toDeleteNode = this->get_node_and_parent_iterative(this->root, key, &parentOfToDelete);
    }
};

void test_contains_using_empty_dictionary() {
    Dictionary<std::string, int> d;
    assert (d.contains("foo") == false);
}

void test_contains_using_few_elements_not_found() {
    Dictionary<std::string, int> d;
    d.add("other", 1);
    d.add("other2", 2);
    assert (d.contains("foo") == false);
}

void test_contains_using_few_element_found() {
    Dictionary<std::string, int> d;
    d.add("foo", 1);
    d.add("other2", 2);
    std::cerr << "vlaue " << d.get_value("foo"); 
    //assert (d.contains("foo") == true);
}

int main()
{
    std::cerr<<"Hello World";
    test_contains_using_few_element_found();

    return 0;
}
