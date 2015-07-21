#include "ListNode.h"
#include <iostream>
using namespace std;


class AddTwoNumbers{
public:
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2);
private:
    int carry;
    int digit_sum;
    ListNode * iter;
    void addSum();
};

void AddTwoNumbers::addSum(){
    iter->next = new ListNode {digit_sum % 10};
    carry = digit_sum / 10;
    iter = iter->next;
}

ListNode * AddTwoNumbers::addTwoNumbers(ListNode * l1, ListNode * l2){
   
    ListNode head {-1};
    iter = & head;
    carry = 0;
    while(l1 != nullptr && l2 != nullptr){
        digit_sum = l1->val + l2->val + carry;
        addSum();
        l1 = l1->next; 
        l2 = l2->next;
    }
    
    while(l1 != nullptr){
        digit_sum = l1->val + carry;
        addSum();
        l1 = l1->next;
    }
    
    while(l2 != nullptr){
        digit_sum = l2->val + carry;
        addSum();
        l2 = l2 ->next;
    }
    while(carry){
        digit_sum = carry;
        addSum();
    }
    return head.next;
}

int main(){
    AddTwoNumbers solver;
    ListNode * l1 = new ListNode{2, new ListNode{4, new ListNode{3}}};
    ListNode * l2 = new ListNode{5, new ListNode{6, new ListNode{4}}}; 
    ListNode * l3 = solver.addTwoNumbers(l1, l2);
    while(l3){
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;
}
