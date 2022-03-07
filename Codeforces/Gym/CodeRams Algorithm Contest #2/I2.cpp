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

const int N = 1e5 + 10;

int n, m, a, b;
vector<int> adj[N];
int cnt[N];
bool ans[N];
int vis[N];

bool dfs(int node){
    vis[node] = 1;
    if (node == b) return 1;
    for (auto& x : adj[node]){
        if (vis[x]) continue;
        if (dfs(x)) return 1;
    }
    return 0;
}

vector<int> artic[N];
void dfs_artic(int node, int p){
    artic[node].pb(p);
    for (auto& x : adj[node]){
        if (cnt[x] != 1 || (artic[x].size() && artic[x].back() == p)) continue;
        dfs_artic(x, p);
    }
}

int tin[N], low[N], comp[N];
int timer, compNum;
vector<int> st;

void dfs_scc(int node, int p){
    st.pb(node);
    tin[node] = low[node] = ++timer;
    for (auto x : adj[node]){
        if (x == p) continue;
        if (tin[x]){
            low[node] = min(low[node], tin[x]); 
        } else {
            dfs_scc(x, node);
            low[node] = min(low[node], low[x]);
        }
    }
    if (low[node] == tin[node]){
        compNum++;
        while (st.back() != node){
            comp[st.back()] = compNum;
            st.pop_back();
        }
        comp[st.back()] = compNum;
        st.pop_back();
    }
}
void tarjan(){
    for (int i=1;i<=n;i++){
        tin[i] = low[i] = comp[i] = 0;
    }
    timer = compNum = 0;
    st.clear();
    for (int i=1;i<=n;i++){
        if (tin[i] == 0){
            dfs_scc(i, i);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b;
    for (int i=1;i<=m;i++){
        int len;
        cin >> len;
        int a;
        cin >> a;
        cnt[a]++;
        for (int j=2;j<=len;j++){
            int b;
            cin >> b;
            adj[a].pb(b);
            adj[b].pb(a);
            cnt[b]++;
            a = b;
        }
    }
    cnt[a] = max(cnt[a], 2);
    cnt[b] = max(cnt[b], 2);
    for (int i=1;i<=n;i++){
        if (cnt[i] > 1){
            dfs_artic(i, i);
        }
    }
    fill(ans + 1, ans + n + 1, 1);
    for (int i=1;i<=n;i++){
        if (i == a || i == b){
            ans[i] = 0;
            continue;
        }
        if (cnt[i] == 1) continue;
        fill(vis + 1, vis + n + 1, 0);
        vis[i] = 1;
        ans[i] = dfs(a);
    }
    tarjan();
    for (int i=1;i<=n;i++){
        if (cnt[i] == 1 && i != a && i != b){
            if (artic[i].size() == 2 && (comp[i] != comp[artic[i][0]] || comp[i] != comp[artic[i][1]])){
                ans[i] = (ans[artic[i][0]] != 0 || ans[artic[i][1]] != 0);
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << ans[i];
    }
    cout << el;

    return 0;
}