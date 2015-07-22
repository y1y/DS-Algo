#include "ListNode.h"
class Palindrome{
public:
    bool isPalindrome(ListNode * head);
};

// 0   ->  2   ->    2     ->   1
//        p1                    p2
//                             iter  next
//                  next                  tmp
//                  iter                  next
bool Palindrome::isPalindrome(ListNode * head){
    if(!head || !(head->next)){
        return true;
    }
    ListNode * p1 = head;
    ListNode * p2 = p1? p1 -> next: p1;

    while(p2 && p2->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }
    ListNode * iter = p1->next;
    ListNode * next = iter->next;
    iter->next = nullptr; 
    while(next){
        ListNode * temp = next->next;
        next->next = iter;
        iter = next;
        next = temp;
    }
    next = iter->next;
    iter->next = nullptr;
    bool is_palindrome = true;
    while(next){
        if(is_palindrome){
            is_palindrome = ((iter->val) == (head->val));
        }
        ListNode * tmp = next->next;
        next->next = iter;
        iter = next;
        next = tmp;
        head = head->next;
    }
    if(is_palindrome){
        is_palindrome = ((iter->val) == (head->val));
    }
    return is_palindrome;
}


int main(){

}
