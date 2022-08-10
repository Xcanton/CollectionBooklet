
/*
* 在时间复杂度 O(1) 的限制下实现堆栈中指定功能。
* Program the pre-set stuck class 
* under the time complexity limitation of O(1)
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class MinStack {
    // write your code here
    stack<int> real_stack;
    stack<int> co_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        co_stack.push(INT_MAX);
    }
    
    void push(int x) {
        real_stack.push(x);
        co_stack.push(::min(co_stack.top(), x));
    }
    
    void pop() {
        real_stack.pop();
        co_stack.pop();
    }
    
    int top() {
        return real_stack.top();
    }
    
    int min() {
        return co_stack.top();
    }
};

int main(){
    MinStack* stuck = new MinStack();
    stuck->push(-2);
    stuck->push(0);
    stuck->push(-3);

    int result1 = stuck->min();
    stuck->pop();
    int result2 = stuck->top();
    int result3 = stuck->min();
    string final = result1==-3 && result2==0 && result3==-2?"totally correct":"not correct";
    std::cout << "result1 is " << result1 << "\n";
    std::cout << "result2 is " << result2 << "\n";
    std::cout << "result3 is " << result3 << "\n";
    std::cout << "final result is " <<  final;
    std::cout << std::endl;
    return 0;
}