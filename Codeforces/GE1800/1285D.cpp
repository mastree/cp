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

const int N = 1e5 + 9;
const int INF = 2e9;

struct Trie{
    struct Node{
        Node * child[2];
        int deg;
        Node(int d){
            child[0] = child[1] = 0;
            deg = d;
        }
    };

    Node * head;
    Trie(){
        head = new Node(31);
    }

    void insert(int a){
        Node * cur = head;
        for (int i=30;i>=0;i--){
            int bit = (1 << i);
            bool on = (bit & a);
            if (cur -> child[on] == 0){
                cur -> child[on] = new Node(i);
            }
            cur = cur -> child[on];
        }
    }

    int sol(){
        int ans = INF;

        queue<pair<int, Node*>> qu;
        qu.push(mp(0, head));

        while (!qu.empty()){
            auto tm = qu.front();
            qu.pop();
            if (tm.se -> child[0] == 0 && tm.se -> child[1] == 0){
                ans = min(ans, tm.fi);
                continue;
            }

            if (tm.se -> child[0] != 0 && tm.se -> child[1] == 0){
                qu.push(mp(tm.fi, tm.se -> child[0]));
            } else if (tm.se -> child[0] == 0 && tm.se -> child[1] != 0){
                qu.push(mp(tm.fi, tm.se -> child[1]));
            } else{
                int kon = tm.fi + (1 << (tm.se -> deg - 1));
                qu.push(mp(kon, tm.se -> child[0]));
                qu.push(mp(kon, tm.se -> child[1]));
            }
        }

        return ans;
    }
};


int n;
Trie trie;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        trie.insert(a);
    }

    cout << trie.sol() << el;

    return 0;
}