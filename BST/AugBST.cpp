struct Node{
    int key;
    int val;
    int N;
    Node * left, right;
}


class AugBST{
private:
    Node * root;
    void destroy();
    int size(Node * x){
        if(!x){
            return 0;
        } else {
            return x.N;
        }
    }
    int get(Node * x, int key){
        if(!x){
            return -1;
        }
        while(x){
            if(x->key < key){
                x = x->right;
            } else if(x->key > key){
                x = x->left;
            } else {
                return x->val;
            }
        }
        return -1;
    }
    Node * put(Node * x, int key, int val){
        if(!x){
            return new Node{key, val, 1};
        }
        if(x->key < key){
            x->right = put(x->right, key, val);
        } else if (x.key > key) {
            x->left = put(x->left, key, val);
        } else {
            x->val = val;
        }
        x->N = 1 + size(x->left) + size(x->right);
        return x;
    }
    void deleteMin(){
        root = deleteMin(root);
    }
    Node * deleteMin(Node * x){
        if(!x->left){
            Node * y = x->right;
            delete x;
            return y;
        }
        x->left = deleteMin(x->left);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    void del(int key){
        root = del(root, key);
    }
    Node * del(Node * x, int key){
        if(!x){
            return x;
        }
        if(x->key < key){
            x->right = del(x->right, key);
        } else if(x->key > key){
            x->left = del(x->left, key);
        } else {
            if(!x->right){
                return x->left;
            } else if (!x->left){
                return x->right;
            }
            Node * t = x;
            x = min(t->right);
            x->right = deleteMin(t->right);
            x->left = t->left;
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
public:
    AugBST():root(nullptr){}
    ~AugBST(){
        destroy();
    }
    bool isEmpty(){
        return size() == 0;
    }
    int size(){
        return size(root);
    }
    bool contains(int key){
        return get(key) != -1;
    }
    int get(int key){
        return get(root, key);
    }
    void put(int key, int val){
        if(val == -1){
            del(key);
            return;
        }
        root = put(root, key, val);
    }
    Node * floor(Node * x, int key){
        if(!x || x->key == key){
            return x;
        }
        if(x->key > key){
            return floor(x->left, key);
        }
        Node * t = floor(x->right, key);
        if(t){
            return t;
        }
        return x;
    }

    int select(int k){
        if(k < 0 || k >= size()){
            return -1;
        }
        Node * x = select(root, k);
        return x->key;
    }

    Node * select(Node * x, int k){
        if(!x){
            return nullptr;
        }
        int t = size(x->left);
        if(t > k ){
            return select(x->left, k);
        } else if (t < k) {
            return select(x->right, k - t - 1);
        } else {
            return x;
        }
    }
    int rank(int key){
        return rank(key, root); 
    }

    int rank(int key, Node * x){
        if(!x){
            return 0;
        }
        if(x->key < key){
            return 1 + size(x->left) + rank(key, x->right);
        } else if (x->key > key){
            return rank(key, x->left);
        } else {
            return size(x->left);
        }
    }

    void keys(Node * x, vector<int> q, int lo, int hi){
        if(!x){
            return;
        }
        if(x->key < lo){
            keys(x->right, q, lo, hi);
        }
        if(x->key <= lo && x->key <= hi){
            q.push_back(x->key);
        }
        if(x->key < x->hi){
            keys(x->right, q, lo, hi);
        }
    }

    int size(int lo, int hi){
        if(lo > hi){
            return 0;
        }
        if(contains(hi)){
            return rank(hi) - rank(lo) + 1;
        } else {
            return rank(hi) - rank(lo);
        }
    }
    bool isBST(){
        return isBST(root, INT_MIN, INT_MAX);
    }

    bool isBST(Node * x, int min, int max){
        if(!x){
            return true;
        }
        if(x->key <= min){
            return false;
        }
        if(x->key >= max){
            return false;
        }
        return isBST(x->left, min, x->key) && isBST(x->right, x->key, max);
    }
};
