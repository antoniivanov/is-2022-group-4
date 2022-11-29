
template<typename T>
struct Node {
    T data;   
    Node<T> *left; 
    Node<T> *right;
};


template <typename K, typename V>
class Dictionary {
    
    Node< std::pair<K, V> > *root;

    Node<K,V>* add_helper(Node* root, std::pair<K,V> data) {
        if (root == nullptr) {
            return new Node ....
        } 
        
        if (data.key > root.key) {
            root->right = add_helper(root->right, value)
        } 
        // if ... TODO
     
        return root;
    }

public:

    void add(K key, V value) {
        std::pair<K,V> data (key, value);
        
         this->root = add_helper(root, data);
        

    }

    V get_value(K key); 

    bool contains (K key);

    void remove(K key);
    
}