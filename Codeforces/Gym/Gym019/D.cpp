#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, K = 20;
const int D = 10;
const int INF = 1e9;

int n, k;
string ar[N];

void print_bit(int x){
    for (int i=k - 1;i>=0;i--){
        if (x & (1 << i)) cout << 1;
        else cout << 0;
    }
    cout << el;
}

struct Trie{
    struct Node{
        vector<int> skor;
        bool leaf = 0;
        Node * ch[2] = {0, 0};
        Node(){}
    };
    Node * head;
    Trie(){
        head = new Node();
    }
    void insert(const string& s, int id){
        Node * cur = head;
        for (auto x : s){
            bool on = (x == '1');
            if (!cur->ch[on]){
                cur->ch[on] = new Node();
            }
            cur = cur->ch[on];
        }
        cur->leaf = 1;
        if (cur->skor.empty()){
            cur->skor.resize((1 << D), INF);
        }
        string temp;
        for (int jj=D - 1;jj>=0;jj--){
            temp.pb(ar[id][k - jj - 1]);
        }
        bitset<D> b(temp);
        for (int i=0;i<(1 << D);i++){
            bitset<D> a(i);
            int sk = (int)(a ^ b).count();
            cur->skor[i] = min(cur->skor[i], sk);
        }
    }

    int dp[(1 << D)];
    void dfs(const string& s, int id, Node * cur, int base){
        if (id == s.size()){
            for (int i=0;i<(1 << D);i++){
                dp[i] = min(dp[i], base + cur->skor[i]);
            }
            return;
        }
        bool on = 0;
        if (s[id] == '1') on = 1;
        if (cur->ch[on]){
            dfs(s, id + 1, cur->ch[on], base);
        }
        if (cur->ch[!on]){
            dfs(s, id + 1, cur->ch[!on], base + 1);
        }
    }
    pii ask(int x){
        Node * cur = head;
        string temp;
        for (int i=k - D - 1;i>=0;i--){
            if (x & (1 << i)){
                temp.pb('1');
            } else temp.pb('0');
        }
        fill(dp, dp + (1 << D), INF);
        dfs(temp, 0, head, 0);

        int mx = -1, ret;
        for (int i=0;i<(1 << D);i++){
            if (dp[i] > mx){
                mx = dp[i];
                ret = i;
            }
        }
        return mp(mx, (x << D) + ret);
    }
};

Trie trie;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    if (k <= D){
        int mx = -1, cur;
        for (int i=0;i<(1 << k);i++){
            bitset<K> a(i);
            int mxcur = INF;
            for (int j=1;j<=n;j++){
                bitset<K> b(ar[j]);
                mxcur = min(mxcur, (int)((a ^ b).count()));
            }
            if (mxcur > mx){
                mx = mxcur;
                cur = i;
            }
        }
        print_bit(cur);
        return 0;
    }
    for (int i=1;i<=n;i++){
        string temp = ar[i];
        for (int j=0;j<D;j++) temp.pop_back();
        trie.insert(temp, i);
    }
    int mx = -1, cur;
    for (int i=0;i<(1 << (k - D));i++){
        pii temp = trie.ask(i);
        if (temp.fi > mx){
            mx = temp.fi;
            cur = temp.se;
        }
    }
    print_bit(cur);

    return 0;
}