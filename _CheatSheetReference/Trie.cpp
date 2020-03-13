struct Trie{
    struct Node{
        Node * child[2];
        int cnt;
        Node(){
            child[0] = child[1] = 0;
            cnt = 0;
        }
    };

    Node * head;
    Trie(){
        head = new Node();
    }

    void insert(int x){
        Node * cur = head;
        for (int i=30;i>=0;i--){
            int bit = (1 << i);
            bool on = (x & bit);
            (cur -> cnt)++;
            if (cur -> child[on] == NULL){
                cur -> child[on] = new Node();
            }
            cur = cur -> child[on];
        }
        (cur -> cnt)++;
    }

    void erase(int x){
        Node * cur = head;
        for (int i=30;i>=0;i--){
            int bit = (1 << i);
            bool on = (x & bit);
            (cur -> cnt)--;
            cur = cur -> child[on];
        }
        (cur -> cnt)--;
    }
};