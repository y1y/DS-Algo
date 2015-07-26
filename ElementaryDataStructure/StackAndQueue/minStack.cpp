class MinStack{
private:
    stack<int> ele;
    stack<int> mins;
public:
    void push(int x);
    void pop();
    int top();
    int getMin();
};


void MinStack::push(int x){
    ele.push(x);
    if(mins.empty() || x <= mins.top()){
        mins.push(x);
    }
}

void MinStack::pop(){
    if(!ele.empty()){
        if(mins.top() == ele.top()){
            mins.pop();
        }
        ele.pop();
    }
}

int MinStack::top(){
    if(!ele.empty()){
        return ele.top();
    }
    return -1;
}

int MinStack::geMin(){
    if(!mins.empty()){
        return mins.top();
    }
    return -1;
}



class MinStack2{
private:
    stack<long> diff;
    long min;
public:
    void push(int x);
    void pop();
    int top();
    int getMin();
};


void MinStack2::push(int x){
    if(diff.empty()){
        diff.push(0);
        min = x;
    } else {
        diff.push(min - x);
        if(x < min){
            min = x;
        }
    }
}

void MinStack::pop(){
    if(!diff.empty()){
        if(diff.top() > 0){
            min = min + diff.top();
        }
        diff.pop();
    }
}

int MinStack::top(){
    if(!diff.empty()){
        if(diff.top() >= 0){
            return min;
        } else {
            return min - diff.top();
        }
    }
    return -1;
}

int MinStack::geMin(){
    if(!diff.empty()){
        return min;
    }
    return -1;
}




