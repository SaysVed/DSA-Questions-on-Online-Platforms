https://leetcode.com/problems/implement-queue-using-stacks/


class MyQueue {
private:
    stack<int> s1;  // Primary stack for enqueue operations
    stack<int> s2;  // Secondary stack for dequeue operations
public:
    MyQueue() {}    // Constructor

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());  // Transfer elements from s1 to s2
            s1.pop();
        }
        s1.push(x);  // Push the new element onto s1
        while (!s2.empty()) {
            s1.push(s2.top());  // Transfer elements back from s2 to s1
            s2.pop();
        }
    }

    int pop() {
        int temp = s1.top();  // Store the front element
        s1.pop();             // Remove the front element
        return temp;          // Return the popped element
    }

    int peek() {
        return s1.top();  // Return the front element without removing it
    }

    bool empty() {
        return s1.empty();  // Check if the queue is empty
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
