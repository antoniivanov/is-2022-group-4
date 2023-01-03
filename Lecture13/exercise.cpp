#include <queue>

#include <iostream>

using namespace std;



template<typename T>
struct box {
    T data;   
    Node<T> *left; 
    Node<T> *right;

    Node(T data, box<T>* left, box<T>* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
}; 
 
template<typename T> 
void expand(box<T> *t1, box<T> * & t2) {
    if (t1 == nullptr) {
        return;
    } else if (t2 == nullptr) {
        t2 = new box <T>{t1->data, nullptr, nullptr}
    }
    
    expand(t1->left, t2->left);
    expand(t1->right, t2->right);
}

template<typename T>
void
diff(box<T> *t1, box<T>*t2, std::vector<int>&result) {
    if (t1 == nullptr) {
        return;
    } else if (t2 == nullptr) {
        result.push_back(t1->data);
        diff<T>(t1->left, nullptr, result);
        diff<T>(t1->right, nullptr, result);
    } else { // t1 != nullptr // t2 != nullptr 
        diff<T>(t1->left, t2->left, result);
        diff<T>(t1->right, t2->right, result);
    
}

template<typename T> 
std::vector<T> diff(box<T> * t1, box<T> *t2) {
    std::vector<T> result>
    diff<T>(t1, t2, result);
    return result; 
}


template<typename T> 
void get_node_values_at_level(box<T> *root, int level, std::vector<T> &values) {
    
    if(root == nullptr) {
        return;
    }
    if (level == 1) {
        values.push_back(root->data);
    } else {
        get_node_values_at_level(root->left, level - 1, values);
        get_node_values_at_level(root->right, level - 1, values);
    }
}


 template<typename T>
std::vector<T> levelsGrowing(box<T>* root) {
    
    int height = tree_height(root);
    
    std::vector<T> result; 
    
    int prev_values_size = 0; 
    for (int level = 1; level <=height; ++level) {
        std::vector<T> values; 
        get_node_values_at_level(root, level, values);
        if (values.size() > prev_values_size) {
            result.insert(result.end(), values.begin(), values.end());
        }
        prev_values_size = values.size();
    }
    return result; 
}



 template<typename T>
std::vector<T> levelsGrowing(box<T>* root) {
    
    std::vector<int> result; 
    std::queue < box<T>* > next_nodes; 
    next_nodes.push(root);
    
    int prev_values_size = 0;
    while(!next_nodes.emtpy()) {
        
        int size = next_nodes.size(); 
        for(int i = 0; i < size; ++i) {
            auto node = next_nodes.front();
            next_nodes.pop();
            if (size > prev_values_size) {
                result.push_back(node->data);
            }
            if (node->right != nullptr) {
                next_nodes.push(node->right);
            }
            if (node->left != nullptr) {
                next_nodes.push(node->left);
            }
        }
        prev_values_size = size; 
    }
}
 
