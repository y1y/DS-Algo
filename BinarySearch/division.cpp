#include <iostream>
#include <climits>

using namespace std;
class Division{
public:
    int divide(int dividend, int divisor);
};


int Division::divide(int dividend, int divisor){
    // check overflow!
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)){
        return INT_MAX;
    }
    long long a = llabs(dividend);
    long long b = llabs(divisor);
    int sign = (dividend ^ divisor ) < 0 ? -1: 1;

    int power = 32;
    unsigned long long b_power = static_cast<unsigned long long>(b) << power;
    unsigned result = 0;
    while(a >= b){
        while(b_power > a){
            b_power >>= 1;
            --power;
        }
        result += 1U << power;
        a -= b_power;
    }
    return sign * result;
}

int main(){
    Division solver;
    cout << solver.divide(1, 1) << endl;

}
