class MyQueue {
    stack<int>input;
    stack<int>output;
public:
    MyQueue() {
    
    }
    
    //push element x to the back of the queue
    void push(int x) { 
        input.push(x);
    }
    
    //Removes the element from the front of the queue and returns it.
    int pop() {
        int x = peek();
        output.pop();
        return x;
     }
    
    int peek() {
        if (output.empty()) {
            shiftStacks();
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
    
    void shiftStacks() {
        while(!input.empty()) {
            int temp = input.top();
            input.pop();
            output.push(temp);
            
        }
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