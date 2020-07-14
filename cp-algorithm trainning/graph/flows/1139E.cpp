#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e3 + 10;

int q;
int n, m;
int pot[N], member[N], quer[N], ans[N];
bool absent[N];
vector<int> adj[2 * N];

int match[2 * N];
bool vis[2 * N];
bool cari(int node){
    if (vis[node]) return 0;
    vis[node] = 1;

    for (auto x : adj[node]){
        if (match[x] == -1){
            match[node] = x;
            match[x] = node;
            return 1;
        } else if (cari(match[x])){
            match[node] = x;
            match[x] = node;
            return 1;
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(match, match + 2 * N, -1);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> pot[i];
    }
    for (int i=1;i<=n;i++){
        cin >> member[i];
    }
    int sisa = n;
    cin >> q;
    for (int i=1;i<=q;i++){
        cin >> quer[i];
        absent[quer[i]] = 1;
    }
    // nodes rule
    // MEX -> 0--N
    // Group -> N + 1--N + n
    for (int i=1;i<=n;i++){
        if (absent[i]) continue;

        adj[N + member[i]].pb(pot[i]);
        adj[pot[i]].pb(N + member[i]);
    }
    int cur = 0;
    for (int i=q;i>=1;i--){
        fill(vis, vis + 2 * N, 0);
        while (cari(cur)){
            cur++;
            fill(vis, vis + 2 * N, 0);
        }
        ans[i] = cur;
        adj[N + member[quer[i]]].pb(pot[quer[i]]);
        adj[pot[quer[i]]].pb(N + member[quer[i]]);
    }
    for (int i=1;i<=q;i++){
        cout << ans[i] << el;
    }

    return 0;
}