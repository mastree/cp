#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct Node{
    int dep = 0;
    unordered_map<int, Node*> child;
    Node* par;
    int vpar;
    Node(int dep, Node* par = 0, int vpar = 0) : dep(dep) {
        this->par = par;
        this->vpar = vpar;
    }
};
struct Trie{
    Node* head;

    Trie(){
        head = new Node(0);
    }
    void insert(const vector<int>& vec){
        Node* cur = head;
        for (auto& x : vec){
            if (!cur->child[x]){
                cur->child[x] = new Node(cur->dep + 1, cur, x);
            }
            cur = cur->child[x];
        }
    }
};

const int N = 11;
const ll INF = 1e18;

int n, m;
vector<ll> vec[N];
Trie trie;

ll mx[N], pre[N];
set<pair<ll, int>> setdah[N];
vector<ll> except;
vector<Node*> getnode;
void dfs_node(Node* node){
    getnode.pb(node);
    for (auto& x : node->child){
        setdah[node->dep + 1].erase(mp())
    }
    for (auto& x : node->child){
        dfs_node(x.se);
    }
}

void init_node(){
    Node* cur = trie.head;
    dfs_node(cur);
}

vector<ll> dp[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        vec[i].resize(len + 1);
        ll emx = 0;
        for (int j=1;j<=len;j++){
            cin >> vec[i][j];
            emx = max(emx, vec[i][j]);
            setdah[i].insert(mp(vec[i][j], j));
        }
        mx[i] = emx;
        pre[i] = pre[i - 1] + mx[i];
    }
    cin >> m;
    for (int i=1;i<=m;i++){
        vector<int> ban(n);
        for (int j=0;j<n;j++){
            cin >> ban[j];
        }
        trie.insert(ban);
    }
    init_node();
    // cout << getnode.size() << el;
    int len = getnode.size();
    for (int i=0;i<=n;i++){
        dp[i].resize(len, -INF);
    }
    dp[0][0] = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<len;j++){
            if (dp[i][j] == -INF) continue;
            for (auto& ch : getnode[j].child){

            }
        }
    }

    return 0;
}