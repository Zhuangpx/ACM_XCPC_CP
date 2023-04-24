# [AcWing41. 包含min函数的栈](https://www.acwing.com/problem/content/description/90/)

维护两个栈，A存储原本数据，B存储以A开头的某段数据的最小值。

```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int>a,b;
    MinStack() {
        
    }
    
    void push(int x) {
        a.push(x);
        if(b.empty())b.push(x);
        else b.push(min(x,b.top()));
    }
    
    void pop() {
        a.pop();
        b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};
```

