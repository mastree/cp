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

const int N = 710;

int q;
int n, m;
vector<int> adl[N];
vector<pii> bridges;

bool vis[N];
int tin[N], low[N], timer;

void init(){
    timer = 0;
    bridges.clear();
    for (int i=1;i<=n;i++){
        vis[i] = 0;
        adl[i].clear();
    }
}

void dfs(int node, int p){
    vis[node] = 1;
    tin[node] = low[node] = ++timer;
    for (int x : adl[node]){
        if (x == p) continue;
        if (vis[x]){
            low[node] = min(low[node], tin[x]);
        } else{
            dfs(x, node);
            low[node] = min(low[node], low[x]);
            if (low[x] > tin[node]){
                bridges.pb(mp(min(node, x), max(node, x)));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    for (int tc=1;tc<=q;tc++){
        cin >> n >> m;
        init();
        for (int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            adl[a].pb(b);
            adl[b].pb(a);
        }
        for (int i=1;i<=n;i++){
            if (!vis[i]) dfs(i, i);
        }

        cout << "Caso #" << tc << el;  
        if (bridges.empty()){
            cout << "Sin bloqueos" << el;
            continue;
        }
        sort(bridges.begin(), bridges.end());
        cout << bridges.size() << el;
        for (pii bridge : bridges){
            cout << bridge.fi << " " << bridge.se << el;
        }
    }

    return 0;
} 