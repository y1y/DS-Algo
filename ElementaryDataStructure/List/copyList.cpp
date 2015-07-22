#include <unordered_map>

struct RandomListNode{
    int label;
    RandomListNode * next, * random;
    RandomListNode(int x): label(x), next(nullptr), random(nullptr){}
};


class CopyList{
public:
    RandomListNode * copyByHash(RandomListNode * head);
    RandomListNode * copyByMix(RandomListNode * head);
};

RandomListNode * CopyList::copyByHash(RandomListNode * head){
    RandomListNode nil(-1);
    RandomListNode * tail = & nil;
    unordered_map<int, RandomListNode *> label_record;
    
    while(head){
        int node_label = head->label;
        
        auto it  = label_record.find(node_label);
        if(it == label_record.end()){
            label_record[node_label] = new RandomListNode(node_label);
        } 
        tail = tail->next = label_record[node_label];
        RandomListNode * rdNode = head->random;
        if(rdNode){
            if(label_record.find(rdNode->label) == label_record.end()){
                label_record[rdNode->label] = new RandomListNode(rdNode->label);
            }   
            tail->random = label_record[rdNode->label]; 
        }
        head = head->next;
    }
    return nil.next;
}

RandomListNode * CopyList::copyByMix(RandomListNode * head){
    RandomListNode * iter = head;
    while(iter){
        RandomListNode * temp = iter->next;
        RandomListNode * newNode = new RandomListNode(iter->label);
        newNode->next = temp;
        iter->next = newNode;
        iter = temp;
    }
    iter = head;
    while(iter){
        if(iter->random){
            iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
    }
    iter = head;
    
    RandomListNode nil(-1);
    RandomListNode * tail = & nil;
    while(iter){
        tail = tail->next = iter->next;
        iter = iter->next = tail->next;
    }
    return nil.next;
}

