class MinStack {
public:

stack<int>s1; //--- holding the real values
stack<int>s2; //--- holding the supporting min. values

MinStack() {
    
}

void push(int val) {
    
    s1.push(val);
    if(s2.size()==0 || s2.top()>=val)
    {
        s2.push(val);
    }
    
}

void pop() {

    if(s1.size()==0)
        return;
    
    if(s1.top()==s2.top())
    {
        s2.pop();
    }
    
    s1.pop();
    
}

int top() {
    
    if(s1.size()==0)
        return -1;
    
    return s1.top();
    
}

int getMin() {
    
    if(s2.size()==0)
        return -1;
    
    return s2.top();
    
}
};