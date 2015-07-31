#include "BST.h"
#include <iostream>
#include <stack>

using namespace std;

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    destroy();
}
BST::BST(const BST & other){
    destroy();
    copy(other.root);
}

BST& BST::operator=(const BST & other){
    destroy();
    copy(other.root);
    return * this;
}

void BST::destroy(){
    stack<Node *> tracker;
    if(root){
        tracker.push(root);
    }

    while(!tracker.empty()){
        Node * victim = tracker.top();
        tracker.pop();

        if(victim->left){
            tracker.push(victim->left);
        }

        if(victim->right){
            tracker.push(victim->right);
        }

        delete victim;        
    }

}
void BST::inorderTraverse(){
    Node * prev = nullptr;
    Node * cur = root;
    Node * next = nullptr;
    while(cur){
        if(prev == cur->parent){
            if(!(cur->left)){
                cout << cur->key << endl;
                next = cur->right? cur->right: cur->parent;
            } else {
                next = cur->left;
            }
        } else if(prev == cur->left){
            cout << cur->key << endl;
            if(cur->right){
                next = cur->right;
            } else {
                next = cur->parent;
            }
        } else {
            next = cur->parent;       
        }
        prev = cur;
        cur = next;
    }
}


void BST::copy(const Node * other){
    const Node * cur = other;
    stack<pair<Node*, const Node*>> tracker;
    if(cur){
        root = new Node{cur->key, cur->val};
        tracker.push(make_pair(root, cur));
    }
    Node * iter = root;
    while(!tracker.empty()){
        iter = tracker.top().first;
        cur = tracker.top().second;
        tracker.pop();
        if(cur->left){
            iter->left = new Node{cur->left->key, cur->left->val};
            tracker.push(make_pair(iter->left, cur->left));
        } 
        if(cur->right){
            iter->right = new Node{cur->right->key, cur->right->val};       
            tracker.push(make_pair(iter->right, cur->right));
        }
    }
}

Node * BST::search(int k){
    Node * iter = root;
    while(iter){
        if(iter->key == k){
            return iter;
        } else if(iter->key < k){
            iter = iter->right;
        } else {
            iter = iter->left;
        }
    }
    return iter;
}

void BST::insert(int k, int v){
    Node * parent = nullptr;
    Node * iter = root;

    while(iter){
        parent = iter;
        if(k < iter->key){
            iter = iter->left; 
        } else {
            iter = iter->right;    
        }
    }

    Node * newNode = new Node {k,v};
    newNode->parent = parent;

    if(!parent){
        root = newNode;    
    } else if(parent->key < k){
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }
}

Node * BST::minNode(Node * start){
    Node * iter = start;
    Node * ret = start;
    while(iter){
        ret = iter;
        iter = iter->left;
    }
    return ret;
}

Node * BST::maxNode(Node * start){
    Node * iter = start;
    Node * ret = start;
    while(iter){
        ret = iter;
        iter = iter->right;
    }
    return ret;
}

Node * BST::successor(Node * node){
    if(node && node->right){
        return minNode(node->right);
    } else if(node){
        Node * parent = node->parent;
        while(parent && node == parent->right){
            node = parent;
            parent = parent->parent;
        }
        return parent;
    } else {
        return nullptr; 
    }
}

Node * BST::predecessor(Node * node){
    if(node && node->left){
        return maxNode(node->left);
    } else if(node){
        Node * parent = node->parent;
        while(parent && parent->left == node){
            node = parent;
            parent = parent->parent;
        }
        return parent;
    } else {
        return nullptr;
    }
}

void BST::del(int k){
    Node * delNode = search(k);
    if(delNode){
        if(!delNode->left){
            transplant(delNode, delNode->right);
        } else if(!delNode->right){
            transplant(delNode, delNode->left);
        } else {
            Node * succ = successor(delNode);
            if(succ->parent != delNode){
                transplant(succ, succ->right);
                delNode->right->parent = succ;
                succ->right = delNode->right;
            }
            transplant(delNode, succ);
            succ->left = delNode->left;
            delNode->left->parent = succ;
            delete delNode;
        }
    }
}

void BST::transplant(Node * x, Node * y){
    if(!x->parent){
        root = y;  
    } else if(x == x->parent->left){
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    if(y){
        y->parent = x->parent;
    }
}
