class Stack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x);       
    void pop();
    int top();
    bool empty();
}

bool Stack::empty(){
    return q1.empty();
}
void Stack::push(int x){
    q1.push(x);
}

void Stack::pop(){
    while(q1.size() != 1){
        q2.push(q1.front());
        q1.pop();
    }
    q1.pop();
    swap(q1, q2);
}

void Stack::top(){
    while(q1.size() != 1){
        q2.push(q1.front());
        q1.pop();
    }
    return q1.front();
}


// 1, 2, 3, 4
//
class Stack2{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x);       
    void pop();
    int top();
    bool empty();
}

bool Stack2::empty(){
    return q1.empty();
}
void Stack2::push(int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void Stack2::pop(){
    q1.pop();
}

void Stack2::top(){
    return q1.front();
}

// 1, 2, 3, 4
// 4, 3, 2, 1
//
class Queue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x){
        s1.push(x);
    }
    void pop(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
    }
    int peek(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top(); 
    }
    bool empty(){
        return s1.empty() && s2.empty();
    }
};
