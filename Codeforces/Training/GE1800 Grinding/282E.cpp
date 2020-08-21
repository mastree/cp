#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10, M = 40;

struct Trie{
    struct Node{
        Node * ch[2];
        Node(){
            ch[0] = ch[1] = 0;
        }
    };
    Node * head;
    Trie(){
        head = new Node();
    }
    void insert(ll x){
        Node * cur = head;
        for (int i = M - 1;i>=0;i--){
            bool on = (x & (1LL << i));
            if (!cur->ch[on]){
                cur->ch[on] = new Node();
            }
            cur = cur->ch[on];
        }
    }
    ll ask(ll x){
        ll ret = 0;
        Node * cur = head;
        for (int i=M - 1;i>=0;i--){
            bool on = (x & (1LL << i));
            if (cur->ch[!on]){
                ret += (1LL << i);
                cur = cur->ch[!on];
            } else{
                cur = cur->ch[on];
            }
        }
        return ret;
    }
};

int n;
ll ar[N];
ll ans;
Trie trie;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll all = 0;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        all ^= ar[i];
    }
    ll baru = 0;
    for (int i=0;i<=n;i++){
        all ^= ar[i];
        baru ^= ar[i];
        trie.insert(baru);
        ans = max(ans, trie.ask(all));
    }
    cout << ans << el;

    return 0;
}