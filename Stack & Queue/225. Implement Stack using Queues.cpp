class MyStack {
public:
    queue<int> main;
    queue<int> temp;
    MyStack() {}
    
    void push(int x) {
        // if main queue is empty,push into the temp queue
        while(!main.empty()){
            temp.push(main.front());
            main.pop();
        }
        main.push(x);
        while(!temp.empty()){
            main.push(temp.front());
            temp.pop();
        }
    }
    
    // pop easly understand (STL)
    int pop() {
        int popped = main.front();
        main.pop();
        return popped;
    }
    
    // Front() - FiFo concepet 
    int top() {
        return main.front();
    }
    
    // check the queue is empty or not 
    bool empty() {
        return main.empty();
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