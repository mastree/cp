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

const int N = 1e4 + 10;

int n, m;
vector<pii> edges;
vector<int> adj[N];

int par[N], sz[N];

void init(){
    for (int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
}
int find(int a){
    return (par[a] == a ? a : par[a] = find(par[a]));
}
void make(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
vector<int> candid;

int back[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if (n & 1){
        cout << -1 << el;
        return 0;
    }
    init();
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        make(a, b);
    }
    for (int i=1;i<=n;i++){
        if (par[i] == i){
            candid.pb(i);
        }
    }
    fill(back, back + n + 1, -1);
    int len = candid.size();
    for (int i=0;i<len;i++){
        int id = candid[i];
        for (int j=n;j>=sz[id];j--){
            if (back[j] != -1 || back[j - sz[id]] == -1) continue;
            back[j]
        }
    }

    return 0;
}