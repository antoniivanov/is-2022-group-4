
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
            else if (current->data.first < key) {
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
        if (data.first > root_node.data.first) {
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
        
        //this->root = add_helper(root, data);
        
        if (this->root == nullptr) {
            this->root = new Node< std::pair<K,V> >(data, nullptr, nullptr);
        } else {
            Node<std::pair<K,V> >* parent = nullptr;
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
            nextInOrder->left = toDeleteNode->left; 
            replace_child(parentOfToDelete, toDeleteNode, toDeleteNode->right);
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
    d.add("5-Root", 1);
    d.add("4-Left-leaf", 2);
    d.add("6-Right-leaf", 3);
    assert (d.contains("6-Right-leaf") == true);
    d.remove("6-Right-leaf");
    assert (d.contains("6-Right-leaf") == false);
    assert (d.contains("4-Left-leaf") == true);
    
}



void test_remove_root() {
    std::cerr << "test_remove_root\n";
    Dictionary<std::string, int> d;
    d.add("5-Root", 1);
    d.add("4-Left-leaf", 2);
    d.add("6-Right-leaf", 3);
    assert (d.contains("5-Root") == true);
    d.remove("5-Root");
    assert (d.contains("5-Root") == false);
    assert (d.contains("4-Left-leaf") == true);
}


void test_remove_single_child() {
    std::cerr << "test_remove_single_child\n";
    Dictionary<std::string, int> d;
    d.add("5-Root", 1);
    d.add("4-Left", 2);
    d.add("7-Right", 3);
    d.add("8-RightRight", 4);
    assert (d.contains("7-Right") == true);
    d.remove("7-Right");
    assert (d.contains("7-Right") == false);
}


void test_remove_two_children() {
    std::cerr << "test_remove_two_children\n";
    Dictionary<std::string, int> d;
    d.add("5-Root", 1);
    d.add("4-Left", 2);
    d.add("7-Right", 3);
    d.add("8-RightRight", 4);
    d.add("8-RightLeft", 5);
    assert (d.contains("7-Right") == true);
    d.remove("7-Right");
    assert (d.contains("7-Right") == false);
}


void test_remove_not_found() {
    std::cerr << "test_remove_not_found\n";
    Dictionary<std::string, int> d;
    d.add("d", 1);
    d.add("e", 2);
    assert (d.contains("no-such") == false);
    d.remove("foo");
    assert (d.contains("no-such") == false);
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
