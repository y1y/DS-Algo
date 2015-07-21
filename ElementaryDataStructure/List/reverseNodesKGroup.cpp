#include "ListNode.h"
class ReverseNodesKGroup{
private:
    ListNode * tail;
    ListNode * next;
    int num;
    void reverseK();
public:
    ListNode * reverseKGroup(ListNode * head, int k);
};
// nil(tail)-> 3(rt)
// 1    <-     2         ->3
// rh,                 rt, iter
void ReverseNodesKGroup::reverseK(){
    ListNode * reverse_head = next;
    ListNode * reverse_tail = next;
    int i = 1;
    while(reverse_tail && i < num){
        reverse_tail = reverse_tail->next;
        ++i;    
    }

    if(reverse_tail){
        tail->next = reverse_tail;
        next = reverse_tail->next;
        ListNode * iter = reverse_head->next;
        reverse_head->next = next;
        tail = reverse_head;
        // advance both pointers please!
        while(iter != next){
            ListNode * temp = iter->next;
            iter->next = reverse_head;
            reverse_head = iter;
            iter = temp;
        }
    } else {
        tail->next = reverse_head;
        next = nullptr;
    }
}


ListNode * ReverseNodesKGroup::reverseKGroup(ListNode * head, int k){
    ListNode nil{-1};
    nil.next = head;
    tail = & nil;
    num = k;
    next = head;
    while(next){
        reverseK();
    }
    return nil.next;
}

int main(){

}
