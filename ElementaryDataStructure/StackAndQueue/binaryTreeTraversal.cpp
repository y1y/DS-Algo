#include "TreeNode.h"
#include <vector>
#include <stack>

class BTreeTraversal{
public:
    vector<int> inorderTrav(TreeNode * root);
    vector<vector<int>> zigzagLevelOrder(TreeNode * root);
    vector<vector<int>> zigzagLevelOrder2(TreeNode * root);
    vector<int> preorderTrav(TreeNode * root);
    vector<int> postorderTrav(TreeNode * root);
private:
    vector<int> result;
    stack<TreeNode*> tracker;
    void inorderTravRec(TreeNode * root);
    void inorderTravIter(TreeNode * root);
    void inorderTravIter2(TreeNode * root);
    void preorderTravRec(TreeNode * root);
    void preorderTravIter(TreeNode * root);
    void postorderTravRec(TreeNode * root);
    void postorderTravIter(TreeNode * root);

};

vector<int> BTreeTraversal::inorderTrav(TreeNode * root){
    result.clear();
    inorderTravIter(root);
    return result;
}

void BTreeTraversal::inorderTravRec(TreeNode * root){
    if(root){
        inorderTravRec(root->left);   
        result.push_back(root->val);
        inorderTravRec(root->right);
    }   
}

void BTreeTraversal::inorderTravIter(TreeNode * root){
    tracker = stack<TreeNode*>();
    pushAllLeftNodes(root);
    while(!tracker.empty()){
        root = tracker.top();
        result.push_back(root->val);
        root = root->right;
        tracker.pop();
        pushAllLeftNodes(root);
    }
}

void BTreeTraversal::pushAllLeftNodes(TreeNode * root){
    while(root){
        tracker.push(root);
        root = root->left;
    }
}

vector<vector<int>> BTreeTraversal::zigzagLevelOrder(TreeNode * root){
    vector<vector<int>> result;
    vector<int> level_vec;
    bool is_even = false;
    queue<TreeNode*> recorder;

    if(root){
        recorder.push(root);
        recorder.push(nullptr);
    }
    while(!recorder.empty()){   
        TreeNode * temp = recorder.front();

        recorder.pop();
        if(temp){
            level_vec.push_back(temp->val);
            if(temp->left){
                recorder.push(temp->left);
            }
            if(temp->right){
                recorder.push(temp->right);
            }
        } else {
            if(is_even){
                reverse(level_vec.begin(), level_vec.end());
            }
            result.push_back(level_vec);
            is_even = !is_even;
            level_vec.clear();
            if(!recorder.empty()){
                recorder.push(nullptr);

            }
        }
    }
    return result;
}

vector<vector<int>> BTreeTraversal::zigzagLevelOrder2(TreeNode * root){
    queue<TreeNode*> q;
    if(root){
        q.push(root);
    }
    bool is_even = false;
    vector<vector<int>> result;
    while(!q.empty()){
        int size = q.size();
        vector<int> level_vec(size);
        for(int i = 0; i < size; ++i){
            TreeNode * temp = q.front(); 
            q.pop();
            int idx = is_even? size - i - 1: i;
            level_vec[idx] = temp->val;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        result.push_back(level_vec);
        is_even = !is_even;
    }
    return result;
}

vector<int> BTreeTraversal::preorderTrav(TreeNode *root){
    result.clear();
    preorderTravRec(root);
    return result;
}

void BTreeTraversal::preorderTravRec(TreeNode *root){
    if(root){
        result.push_back(root->val);
        preorderTravRec(root->left);
        preorderTravRec(root->right);
    }
}

void BTreeTraversal::preorderTravIter(TreeNode * root){
    tracker = stack<TreeNode*>();
    if(root){
        tracker.push(root);
    }
    while(!tracker.empty()){
        TreeNode * temp = tracker.top();
        tracker.pop();
        result.push_back(temp->val);
        if(temp->right){
            tracker.push(temp->right);
        }
        if(temp->left){
            tracker.push(temp->left);
        }
    }
}

vector<int> BTreeTraversal::postorderTrav(TreeNode * root){
    result.clear();
    postorderTravRec(root);
    return result;
}

void BTreeTraversal::postorderTravRec(TreeNode * root){
    if(root){
        postorderTravRec(root->left);
        postorderTravRec(root->right);
        result.push_back(root->val);
    }
}

void BTreeTraversal::postorderTravIter(TreeNode * root){
    tracker = stack<TreeNode*>();
    pushAllLefts(root);
    TreeNode * prev = nullptr;
    
    while(!tracker.empty()){
        TreeNode * temp = tracker.top();
        if(temp->right && prev != temp->right){
            pushAllLefts(temp->right);        
        } else {
            tracker.pop();
            result.push_back(temp->val);
            prev = temp;
        }
    }
    return result;
}
