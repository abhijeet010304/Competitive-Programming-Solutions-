class MyQueue {
    stack<int> s1;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(empty()){
            s1.push(x);
            return ;
        }
        int top = pop();
        push(x);
        s1.push(top);
       
    }
    
    int pop() {
        int top = s1.top();
        s1.pop();
        return top;
    }
    
    int peek() {
         int top = s1.top();
        return top;
    }
    
    bool empty() {
        return s1.size()==0;
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