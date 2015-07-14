#include <climits>
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) {};
};
class InsertionSortList{
public:
    ListNode * insertionSortList(ListNode * head){
        ListNode dummy(INT_MIN);
        ListNode * pseudoHead = & dummy;
        
        while(head != nullptr){
            ListNode * next = head->next;
            ListNode * iter = pseudoHead;
            while(iter != nullptr && iter->next != nullptr){
                if(iter->next->val <= head->val){
                    iter = iter->next;
                } else {
                    break;
                }
            }
            ListNode * temp = iter->next;
            iter->next = head;
            head->next = temp;
            head = next;
         }
         return dummy.next;
    }
};


int main(){
    ListNode * test = new ListNode(2);
    test->next = new ListNode(1);
    test->next->next = new ListNode(3);
    test = InsertionSortList().insertionSortList(test); 
    while(test != nullptr){
        cout << test->val << ",";
        ListNode * victim = test;
        test = test->next;
        delete victim;
    }
}
