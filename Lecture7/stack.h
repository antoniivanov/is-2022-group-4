template<class T>
class Stack {
private: 
    std::list<T> backend; 
public:
  
    // pushing an element into the stack
    void push(T d)
    {
        backend.push_front(d);
    }
  
    // popping an element from the stack
    void pop()
    {
        if (cs <= 0) {
            throw std::runtime_error("stack underflow");
        }
        else {
            backend.pop_front();
        }
    }
  
    // if current size is 0 then stack is empty
    bool empty() { return backend.size() == 0 }
  
    // getting the element present at the top of the stack
    T top() { return backend.front(); }
    
    int size()
    {
        // getting the size of the stack
        return backend.size();
    }
  
    
}; 