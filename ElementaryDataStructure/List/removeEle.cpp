
class removeEle{
public:
    ListNode * removeElements(ListNode * head, int val);
};


ListNode * removeEle::removeElements(ListNode * head, int val){
    ListNode nil(-1);
    nil.next = head;
    ListNode * tail = & nil;
    ListNode * iter = head;
    while(iter){
        if(iter->val != val){
            if(tail->next != iter){
                tail->next = iter;
            }
            tail = iter;
        }
        iter = iter->next;
    }
    tail->next = iter;
    return nil.next;
}


void removeEle::deleteNode(ListNode* node) {
        ListNode * prev = node;
        ListNode * next = prev->next;
        prev->val = next->val;
        while(next->next){
            prev = next;
            next = next->next;
            prev->val = next->val;
        }
        prev->next = nullptr;
 }

