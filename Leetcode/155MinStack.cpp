class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    vector<int>v;

    MinStack() {

    }

    void push(int x) {
        st.push(x);
        if(st.size()>1)
            v.push_back(min(v[st.size()-2],x));
        else v.push_back(x);
    }

    void pop() {

        st.pop();
        v.pop_back();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return v[st.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 /*
multiset
 */

 class MinStack {
public:
    /** initialize your data structure here. */
    multiset<int> mset;

    stack<int>st;
    MinStack() {

    }

    void push(int x) {
        st.push(x);
        mset.insert(x);
    }

    void pop() {
        int top = st.top();
        st.pop();
        mset.erase(mset.find(top));
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return *mset.begin();
    }
};
