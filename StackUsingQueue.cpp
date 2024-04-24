https://leetcode.com/problems/implement-stack-using-queues/


class MyStack {
    queue<int> q;       // Using a queue to implement the stack
    int topEle;          // Variable to store the top element of the stack
public:
    MyStack() {}         // Constructor

    void push(int x) {
        q.push(x);       // Push the element onto the queue
        topEle = x;      // Update the top element
    }

    int pop() {
        int size = q.size();
        while (size > 1) {
            this->push(q.front());  // Push all elements except the last one onto the queue
            q.pop();
            size--;
        }
        int x = q.front();   // Store the last element (top of the stack)
        q.pop();             // Remove the last element from the queue
        return x;            // Return the popped element
    }

    int top() {
        return this->topEle;  // Return the top element of the stack
    }

    bool empty() {
        return q.empty();  // Check if the stack is empty by checking if the queue is empty
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */