#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

class ValidParentheses{
private:
    unordered_map<char, char> paren;
public:
    ValidParentheses(){
        paren[')'] =  '(';
        paren['}'] = '{';
        paren[']'] = '[';
    }
    bool isValid(const string & s);
};


bool ValidParentheses::isValid(const string & s){
    stack<char> tracker;    
    for(auto const & c: s){
        switch(c){
            case '(':
            case '{':
            case '[':
                tracker.push(c);
                break;
            case ')':
            case '}':
            case ']':
                if(tracker.empty() || tracker.top() != paren[c]){
                    cout << paren[c] << endl;
                    return false;       

                }
                tracker.pop();
        }
    }
    return tracker.empty();
}




int main(){
    ValidParentheses solver;
    cout << solver.isValid("(){}[]") << endl;
    cout << solver.isValid("(){}((()))[]") <<endl;

}
