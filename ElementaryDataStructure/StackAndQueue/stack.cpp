#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Stack{
public:
    Stack(){}
    ~Stack(){}
    void push(const T &t);
    void pop();
    T top();
    bool empty();
private:
    vector<T> data;
};

template<typename T>
void Stack<T>::push(const T &t){
    data.push_back(t);
}

template<typename T>
void Stack<T>::pop(){
    if(empty()){
        throw underflow_error("Stack empty"); 
    }
    data.pop_back();
}

template<typename T>
T Stack<T>::top(){
    if(empty()){
        throw underflow_error("Stack empty");        
    }
    return data.back();
}

template<typename T>
bool Stack<T>::empty(){
    return data.empty();
}

int main(){
    Stack<int> stk;
    for(int i = 0; i < 10; ++i){
        stk.push(i);
    }
    for(int i = 0; i < 10; ++i){
        cout << stk.top() << endl;
        stk.pop();
    }

}


