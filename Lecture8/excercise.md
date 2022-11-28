
## 1 

Given a string ,
 write a function to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in the given string

The algorithm is the following: 

![x](https://user-images.githubusercontent.com/2536458/204161040-4a09f40f-3294-4e71-8453-85a6290109e0.jpg)

```
bool are_brackets_balanced(std::string expr) {
    std::stack<char> stack;
}
```

## 2 Moving average 

```
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
```

* Calculate complexity 
* What if we can use deque (double ended queue) . How the solution and calcualted complexity changes 
* What if it's ciruclar queue. 


