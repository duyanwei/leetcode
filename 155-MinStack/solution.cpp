/**
 * @file solution.cpp
 * @author duyanwei (duyanwei0702@gmail.com)
 * @brief
 * @version 0.1
 * @date 2020-03-01
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <stack>

using namespace std;

/**
 * @brief
 *
 * @details requirement: constant time
 *
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        buffer_.push(x);
        if (min_buffer_.empty() || min_buffer_.top() > x) {
            min_buffer_.push(x);
        } else {
            min_buffer_.push(min_buffer_.top());
        }
    }

    void pop() {
        if (!buffer_.empty()) {
            buffer_.pop();
            min_buffer_.pop();
        }
    }

    int top() {
        if (!buffer_.empty()) {
            return buffer_.top();
        }
        return -1;  // not a valid definition
    }

    int getMin() {
        if (!min_buffer_.empty()) {
            return min_buffer_.top();
        }
        return -1;  // not a valid definition
    }

private:
    stack<int> buffer_;
    stack<int> min_buffer_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */