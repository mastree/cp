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


int calc(int a, int b){
    if (a == b) return 20;
    int temp = (a ^ b);
    int ret = 0;
    while ((temp & 1) == 0){
        temp >>= 1;
        ret++;
    }
    return ret;
}

struct Trie{
    struct Node{
        Node * child[2];
        set<int> id;
        Node(){
            child[0] = child[1] = 0;
        }
    };

    Node * head;
    Trie(){
        head = new Node();
    }

    void insert(int x, int id){
        Node * cur = head;
        for (int i=0;i<20;i++){
            int bit = (1 << i);
            bool on = x & bit;
            if (cur->child[on] == NULL) cur->child[on] = new Node();
            cur->id.insert(id);
            // cur->id.pb(id);
            cur = cur->child[on];
        }
        cur->id.insert(id);
        // cur->id.pb(id);
    }
    void erase(int x, int id){
        Node * cur = head;
        for (int i=0;i<20;i++){
            int bit = (1 << i);
            bool on = x & bit;
            cur->id.erase(id);
            // cur->id.pop_back();
            cur = cur->child[on];
        }
        cur->id.erase(id);
        // cur->id.pop_back();
    }
    int find(int x, int len){
        Node * cur = head;
        for (int i=0;i<len;i++){
            int bit = (1 << i);
            bool on = x & bit;
            cur = cur->child[on];
        }
        if (cur->id.empty()){
            return -1;
        }
        // int lenn = cur->id.size();
        return *(cur->id.begin());
    }
};


const int N = 5e5 + 10;

int n;
pii ar[N];


void init(Trie& trie){
    for (int i=1;i<=n;i++){
        trie.insert(ar[i].fi, i);
        trie.insert(ar[i].se, i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }

    if (n == 1){
        cout << calc(ar[1].fi, ar[1].se) << el;
        cout << 1 << " " << 2 << el;
        return 0;
    }
    for (int i=20;i>=0;i--){
        // cout << i << el;
        Trie trie;
        vector<pii> ans;
        bool bisa = 1;
        int ambil = 0;

        init(trie);
        ans.pb(mp(1, 2));
        int last = ar[1].se;
        trie.erase(ar[1].fi, 1);
        trie.erase(ar[1].se, 1);
        ambil++;
        // if (i <= 4) return 0;
        while (ambil < n){
            int id = trie.find(last, i);
            // cout << last << " " << id << el;
            // cout << ambil << el;
            // if (ambil > 2) return 0;
            if (id <= 0){
                bisa = 0;
                break;
            }
            // cout << (ar[id].fi ^ last) << el;
            if ((ar[id].fi ^ last) >= (1 << i) || (ar[id].fi ^ last) == 0){
                ans.pb(mp(id * 2 - 1, id * 2));
                last = ar[id].se;
            } else{
                ans.pb(mp(id * 2, id * 2 - 1));
                last = ar[id].fi;
            }
            trie.erase(ar[id].fi, id);
            trie.erase(ar[id].se, id);
            ambil++;
        }
        if (!bisa){
            continue;
        }
        if ((last ^ ar[1].fi) >= (1 << i) || (last ^ ar[1].fi) == 0){
            cout << i << el;
            for (auto x : ans){
                cout << x.fi << " " << x.se << " ";
            }
            cout << el;
            return 0;
        }
    }

    return 0;
}