

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




## Полезни материали: 

### The Seven Steps to problem solving 

**Step 0 - Understand the problem**

Don’t skip this step, ever!

* What is the input? What is the desired output?
* What are the expected side effects?
* Which assumptions are underlying the problem? 
* Break down the problem into subproblems. 

Then the seven steps to problem soving described in
 
- https://adhilton.pratt.duke.edu/sites/adhilton.pratt.duke.edu/files/u37/iticse-7steps.pdf
    
## Домашно   
