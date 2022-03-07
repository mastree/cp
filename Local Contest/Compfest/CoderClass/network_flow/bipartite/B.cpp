#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1010;

struct Person{
    int j;
    pii s, e;
};

int n;
Person ar[N];
vector<int> adj[N];
bool vis[N];
int assign[N];

int manhat(pii a, pii b){
    return abs(a.fi - b.fi) + abs(a.se - b.se);
}
bool match(int u){
    for (auto& v : adj[u]){
        if (vis[v]) continue;
        vis[v] = 1;
        if (assign[v] == 0 || match(assign[v])){
            assign[v] = u;
            return true;
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].j >> ar[i].s.fi >> ar[i].s.se >> ar[i].e.fi >> ar[i].e.se;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i == j) continue;
            if (ar[i].j + manhat(ar[i].s, ar[i].e) + manhat(ar[i].e, ar[j].s) < ar[j].j){
                adj[j].pb(n + i);
            }
        }
    }
    int ans = n;
    for (int i=1;i<=n;i++){
        fill(vis, vis + n + n, 0);
        if (match(i)) ans--;
    }
    cout << ans << el;

    return 0;
}