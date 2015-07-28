#include <stdexcept>
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Queue{
public:
    Queue():head(0), tail(0), size(0){}
    ~Queue(){}
    void push(const T &t);
    void pop();
    T front();
    bool empty();
private:
    int head;
    int tail;
    int size;
    vector<T> data;

    void resize(int new_size);
};

template<typename T>
void Queue<T>::push(const T &t){
    if(empty()){
        if(data.empty()){
            data.resize(2);
        } 
        data[head] = t;
        ++size;
        return;
    }

    
    if(size == data.size()){
        resize(2 * size);
    } 
    
    tail = (tail + 1 ) % data.size();
    data[tail] = t;
    ++size;
}

template<typename T>
void Queue<T>::pop(){
    if(empty()){
        throw underflow_error("queue empty");
    }

    tail = (tail - 1 ) % data.size();
    --size;
    if(size < data.size() / 4){
        resize(data.size() / 4); 
    }
}

template<typename T>
void Queue<T>::resize(int new_size){
    vector<T> temp = move(data);
    data.resize(new_size);
    for(int i = 0; i < size; ++i){
        data[i] = temp[(head + i) % data.size()]; 
    }
    head = 0;
    if(size == 0){
        tail = 0;
    } else {
        tail = size - 1;
    }
}
template<typename T>
T Queue<T>::front(){
    if(empty()){
        throw underflow_error("queue empty");
    }
    return data[tail];
}
 
template<typename T>
bool Queue<T>::empty(){
    return size == 0;
}
int main(){

    Queue<int> q;
    
    for(int i = 0; i < 10; ++i){
        q.push(i);
    }
    while(!q.empty()){   
        cout << q.front() << endl;
        q.pop();
    }

    for(int i = 0; i < 20; ++i){
        q.push(i);
        q.push(i);
        q.pop();
    }
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}


