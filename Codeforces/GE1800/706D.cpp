#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;


struct Trie{
    struct Node{
        Node * child[2];
        int cnt;
        Node(){
            child[0] = 0;
            child[1] = 0;
            cnt = 0;
        }
    };

    Node * head;

    Trie(){
        head = new Node();
    }

    void insert(int a){
        Node * cur = head;

        for (int i=30;i>=0;i--){
            int bit = (1 << i);
            bool on = (bit & a);

            (cur -> cnt)++;
            if (cur -> child[on] == 0){
                cur -> child[on] = new Node();
            }
            cur = cur -> child[on];
        }
        (cur -> cnt)++;
    }

    void del(int a){
        Node * cur = head;

        for (int i=30;i>=0;i--){
            int bit = (1 << i);
            bool on = (bit & a);

            (cur -> cnt)--;
            cur = cur -> child[on];
        }
        (cur -> cnt)--;
    }

    int ask(int a){
        Node * cur = head;
        int res = 0;

        for (int i=30;i>=0;i--){
            int bit = (1 << i);
            bool on = (bit & a);

            if (cur -> child[!on] != 0 && cur -> child[!on] -> cnt > 0){
                if (!on) res += bit;
                cur = cur -> child[!on];
            } else if (cur -> child[on] != 0){
                if (on) res += bit;
                cur = cur -> child[on];
            } else{
                return res;
            }
        }
        return res;
    }
};

int q;
Trie sol;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    sol.insert(0);
    while (q--){
        char tipe;
        int x;
        cin >> tipe >> x;

        if (tipe == '+'){
            sol.insert(x);
        } else if (tipe == '-'){
            sol.del(x);
        } else{
            cout << (sol.ask(x) ^ x) << el;
        }
    }

    return 0;
}