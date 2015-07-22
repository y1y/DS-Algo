class ListCycle{
public:
    bool hasCycle(ListNode * head);
    ListNode * detectCycle(ListNode * head);
private:
    ListNode * slow;
    ListNode * fast;
};

ListNode * detectCycle(ListNode * head){
    if(!hasCycle(head)){
        return nullptr;
    }

    fast = head;
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
    // -m- -d------
    //    |    |
    //    |----|
    // 2(m + d) = m + kL + d
    // m  + d = kL + m
}

bool ListCycle::hasCycle(ListNode * head){
    slow = head;
    fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
