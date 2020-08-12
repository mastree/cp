#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int q;
int n, k;
set<int> adj[N];
int deg[N], ambil[N];

void init(){
    fill(deg, deg + n + 2, 0);
    fill(ambil, ambil + n + 2, 0);
    for (int i=1;i<=n;i++){
        adj[i].clear();
    }
}

void solve(){
    cin >> n >> k;
    
    init();
    for (int i=1;i<n;i++){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (deg[i] == 1){
            q.push(i);
        }
    }
    while (!q.empty()){
        auto node = q.front();
        q.pop();
        for (auto x : adj[node]){
            ambil[x]++;
            if (deg[x] == 2){
                if (ambil[x] % k == 0){
                    q.push(x);
                }
            }
            adj[x].erase(node);
            deg[x]--;
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        ans += ambil[i] / k;
    }
    cout << ans << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}