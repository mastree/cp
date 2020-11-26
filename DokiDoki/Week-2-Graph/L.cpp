#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;

int n, m;
vector<int> adj[N];
vector<pii> art;

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

vector<int> nadj[N];
int par[N];
void find_path(int a, int b){
    queue<int> qu;
    qu.push(a);
    par[a] = a;
    while (!qu.empty()){
        int node = qu.front();
        qu.pop();
        for (auto x : nadj[node]){
            if (par[x]) continue;
            qu.push(x);
            par[x] = node;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(b);
        adj[b].pb(a);
        if (c){
            art.pb(mp(a, b));
        }
    }    
    int aw, ak;
    cin >> aw >> ak;
    tarjan();
    {
        for (int i=1;i<=n;i++){
            for (auto j : adj[i]){
                if (comp[i] != comp[j]){
                    int a = comp[i];
                    int b = comp[j];
                    nadj[a].pb(b);
                    nadj[b].pb(a);
                }
            }
        }
    }
    find_path(comp[aw], comp[ak]);
    {
        bool cek[N];
        fill(cek, cek + n + 2, 0);

        int cur = comp[ak];
        while (cur != comp[aw]){
            cek[cur] = 1;
            cur = par[cur];
        }
        cek[cur] = 1;
        for (auto x : art){
            int a = comp[x.fi];
            int b = comp[x.se];
            if (cek[a] && cek[b]){
                cout << "YES" << el;
                return 0;
            }
        }
    }
    cout << "NO" << el;

    return 0;
}