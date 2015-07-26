#include <vector>
#include <string>
#include <stack>

using namespace std;

class EvalRPN{
public:
    int evalRPN(vector<string> & tokens);
};

// check negative numbers
//
int EvalRPN::evalRPN(vector<string> & tokens){
    stack<int> operand;
    for(auto & t: tokens){
        if(isdigit(t[0]) || t.size() > 1){
            operand.push(stoi(t));        
        } else {
            int first = operand.top();
            operand.pop();
            int second = operand.top();
            operand.pop();

            switch(t[0]){
                case '+':
                    operand.push(first + second);
                break;
                case '-':
                    operand.push(second - first);
                break;
                case '/':
                    operand.push(second / first);
                break;
                case '*':
                    operand.push(first * second);
            }
        
        }
    }
    return operand.top();
}
