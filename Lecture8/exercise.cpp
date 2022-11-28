 bool are_brackets_balanced(std::string expr) {
    std::stack<char> stack;

    for (int i = 0; i < expr.length(); i++) {
        if (stack.empty()) {
             
            // If the stack is empty
            // just push the current bracket
            stack.push(expr[i]);
        }
        else if ((stack.top() == '(' && expr[i] == ')')
                 || (stack.top() == '{' && expr[i] == '}')
                 || (stack.top() == '[' && expr[i] == ']')) {
             
            // If we found any complete pair of bracket
            // then pop
            stack.pop();
        }
        else {
            stack.push(expr[i]);
        }
    }
    if (stack.empty()) {
         
        // If stack is empty return true
        return true;
    }
    // ther are non-matched left-overs - reutrn false
    return false;
}




class MovingAverage {
private: 
  int window_size;
  std::queue queue;


public: 
  public MovingAverage(int window_size) {
    this.window_size = window_size;
  }

  public double next(int val) {
    // calculate the sum of the moving window

    return /* the new moving average*/
  }
}