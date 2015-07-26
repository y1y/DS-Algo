#include <string>
#include <stack>
#include <iostream>

using namespace std;
class BasicCal{
private:
    stack<int> operands;
    stack<char> operators;
    void calc();
public:
    int calculate(string s);
};

int BasicCal::calculate(string s){
    string num = "";
    for(int i = s.size() - 1; i >= 0; --i){
        char c = s[i];
        if(isdigit(c)){
            num = c + num;
            if(i == 0){
                cout << "num:" << num << endl;
                operands.push(stoi(num));
            }
        } else {
            cout << "num:o" << num << endl;
            // check empyt!!
            if(!num.empty()){
                operands.push(stoi(num));
            }
            num = "";
            switch(c){
                case '+':
                case '-':
                case ')':
                    operators.push(c);
                break;
                case '(':
                    while(operators.top() != ')'){
                        calc();
                    }
                    operators.pop();
            } 
        }
    }
    while(operands.size() != 1){
        calc();
    }
    return operands.top();
}

void BasicCal::calc(){
    char op = operators.top();
    operators.pop();
    int first = operands.top();
    operands.pop();
    int second = operands.top();
    operands.pop();
    switch(op){
        case '+':
            operands.push(first + second);
            break;
        case '-':
            operands.push(first - second);
            break;
        case '/':
            operands.push(first / second);
            break;
        case '*':
            operands.push(first * second);
    }
}

int main(){
    BasicCal cal;
    cout << cal.calculate("(1)") << endl;

}
