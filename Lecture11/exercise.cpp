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

// in order ?
template<typename T>
void traverse_inorder(Node<T>* root) {
    if (root != nullptr) { // base case - "empty tree"
        traverse_inorder(root->left);
        std::cout << root->data;
        traverse_inorder(root->right);
    }
}  

template<typename T>
void traverse_inorder_non_recursion(Node<T>* root) {
    std::stack< Node<T>* > stack; 
    Node<T>* current = root;
    while (current != nullptr && !stack.empty()) {
        // left , root, right 
        // go left as much as possible 
        while(current != nullptr) {
            stack.push(current);
            current = current-left;
        }
        // no more elements on the left; 
        current = stack.top();
        stack.pop();
        std::cout << current->data << std::endl;
        // and finally we go right 
        current = current->right;
    }
}

template<typename T>
void bfs(Node<T>* root). {
    std::queue<T> queue;
}

     