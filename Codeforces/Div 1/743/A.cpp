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
int n;
int deg[N];
vector<int> adj[N], radj[N];

void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        int k;
        cin >> k;
        for (int j=0;j<k;j++){
            int preq;
            cin >> preq;
            adj[preq].pb(i);
            radj[i].pb(preq);
            deg[i]++;
        }
    }
    vector<int> dep(n + 1, -1);
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (deg[i] == 0){
            q.push(i);
            dep[i] = 1;
        }
    }
    while (!q.empty()){
        int node = q.front();
        q.pop();
        dep[node] = 1;
        for (auto& x : radj[node]){
            dep[node] = max(dep[node], dep[x] + (x > node));
        }
        for (auto& x : adj[node]){
            if (--deg[x] == 0){
                q.push(x);
            }
        } 
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (dep[i] == -1){
            ans = -1;
            break;
        }
        ans = max(ans, dep[i]);
    }
    cout << ans << el;

    for (int i=1;i<=n;i++){
        adj[i].clear();
        adj[i].shrink_to_fit();
        radj[i].clear();
        radj[i].shrink_to_fit();
        deg[i] = 0;
    }
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