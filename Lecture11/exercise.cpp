
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

    // returns the node with the pass "key" and the found parent node
    // if not such node exist then reutrns nullptr. and set parent_node to the parent where it should be inserted.
    Node< std::pair<K,V> >* get_node_and_parent_iterative(
                    Node< std::pair<K,V> >* root_node, 
                    const K& key, 
                    Node< std::pair<K,V> > **parent_node)
    {
        Node< std::pair<K,V> >* current = root_node;

        while (current != nullptr) {
            
            if (current->data.first > key) {
                if (parent_node != nullptr) {
                    *parent_node = current;
                }
                current = current->left;
            }
            // TODO line
                if (parent_node != nullptr) {
                    *parent_node = current;
                }
                current = current->right;
            }
            else if (current->data.first == key) {
                return current;
            }

        }
        return nullptr;
    }
 


    Node< std::pair<K,V> >* add_helper (Node< std::pair<K,V> >* root_node, std::pair<K,V> data) {
        if (root_node == nullptr) {
            return new Node< std::pair<K,V> >(data, nullptr, nullptr);
        } 
        auto value = root_node.data;
        // TODO line
            root_node->right = add_helper(root_node->right, value);
        } else if (data.first < root_node.data.first) {
            root_node->left = add_helper(root_node->left, value);
        } else {
            root_node->data = data;
        }
     
        return root_node;
    }
    
    Node<std::pair<K,V> >* find_next_in_order(Node<std::pair<K,V> >* node) {
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:

    Dictionary() {
        this->root = nullptr;
    }

    void add(K key, V value) {
        std::pair<K,V> data (key, value);
        
        if (this->root == nullptr) {
            this->root = new Node< std::pair<K,V> >(data, nullptr, nullptr);
        } else {
            Node<std::pair<K,V> >* parent = nullptr;
            auto found = this->get_node_and_parent_iterative(this->root, key, &parent);
            if (found == nullptr) {
                if(parent->data.first > key) {
                    // TODO line
                } else {
                    // TODO line
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
    
    void replace_child(Node<std::pair<K,V> >* parent, 
                       Node<std::pair<K,V> >* child, 
                    Node<std::pair<K,V> >* new_child) {
        if (parent == nullptr) {
            this->root = new_child;
            return;
        }
        if (parent->left == child) {
            parent->left = new_child;
        } else {
            parent->right = new_child;
        }
    }

    void remove(K key) {
        Node<std::pair<K,V> >* parentOfToDelete = nullptr;
        Node<std::pair<K,V> >* toDeleteNode = this->get_node_and_parent_iterative(this->root, key, &parentOfToDelete);
        if (toDeleteNode == nullptr) {
            // it is already deleted 
            return;
        }
        if(toDeleteNode->left == nullptr && toDeleteNode->right == nullptr) {
            replace_child(parentOfToDelete, toDeleteNode, nullptr);
        } else if (toDeleteNode->left == nullptr) {
            replace_child(parentOfToDelete, toDeleteNode, toDeleteNode->right);
        } else if (toDeleteNode->right == nullptr) {
            replace_child(parentOfToDelete, toDeleteNode, toDeleteNode->left);
        } else {
            auto nextInOrder = this->find_next_in_order(toDeleteNode->right);
            // TODO line
            // TODO line
        }
        delete toDeleteNode;
    }
};

void test_contains_using_empty_dictionary() {
    std::cerr << "test_contains_using_empty_dictionary\n";
    Dictionary<std::string, int> d;
    assert (d.contains("foo") == false);
}

void test_contains_using_few_elements_not_found() {
    std::cerr << "test_contains_using_few_elements_not_found\n";
    Dictionary<std::string, int> d;
    d.add("other", 1);
    d.add("other2", 2);
    assert (d.contains("foo") == false);
}

void test_contains_using_few_element_found() {
    std::cerr << "test_contains_using_few_element_found\n";
    Dictionary<std::string, int> d;
    d.add("foo", 1);
    d.add("other2", 2);
    assert (d.contains("foo") == true);
}


void test_get_value_using_few_element_found() {
    std::cerr << "test_get_value_using_few_element_found\n";
    Dictionary<std::string, int> d;
    d.add("foo", 1);
    d.add("other2", 2);
    assert (d.get_value("foo") == 1);
}


void test_remove_leaf() {
    std::cerr << "test_remove_leaf\n";
    Dictionary<std::string, int> d;
    /** TODO method */
}



void test_remove_root() {
    std::cerr << "test_remove_root\n";
    Dictionary<std::string, int> d;
    /** TODO method */
}


void test_remove_single_child() {
    std::cerr << "test_remove_single_child\n";
    Dictionary<std::string, int> d;
    /** TODO method */
}


void test_remove_two_children() {
    std::cerr << "test_remove_two_children\n";
    Dictionary<std::string, int> d;
    /** TODO method */
}


void test_remove_not_found() {
    std::cerr << "test_remove_not_found\n";
    Dictionary<std::string, int> d;
    /** TODO method */
}

int main()
{
    test_contains_using_empty_dictionary();
    test_contains_using_few_elements_not_found();
    test_contains_using_few_element_found();
    test_get_value_using_few_element_found();
    test_remove_leaf();
    test_remove_root();
    test_remove_single_child();
    test_remove_two_children();
    test_remove_not_found();
    
    std::cerr << "DONE";
    
    return 0;
}
