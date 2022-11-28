
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

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window


![wq](https://user-images.githubusercontent.com/2536458/204272046-f99c5189-5afa-4d4f-9ef7-614027eb84c0.jpg)

```
class MovingAverage {
private: 
  int window_size;
  std::queue queue;


public: 
  public MovingAverage(int window_size) {
    this.window_size = window_size;
    // What helper fields we need to be able to calculate average of  window
  }

  public double next(int val) {
    // return the new average of the moving window which is the the average of the last window_size elements added (including this one)

    return /* the new moving average*/
  }
}
```


* Calculate complexity 
* What if we can use deque (double ended queue) . How the solution and calcualted complexity changes 
* What if it's ciruclar queue. 

# 3 Next greater element 

Given an array, print the Next Greater Element (NGE) for every element. 

The Next greater Element for an element a[i] is the first greater element on the right side of a[i] in the array. Elements for which no greater element exist, consider the next greater element as -1. For example for an array {4, 5, 2, 25}, we have the next greater elemetn foreach to be (4,5), (5,25), (2,25), (25,-1). The soluiton should work in linear time ( O(n) complexity where n i size of the array).



